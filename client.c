/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:09:22 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/03 17:09:16 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_send_sig(pid_t pid, char c)
{
	int		i;
	char	temp;

	i = 7;
	while (i >= 0)
	{
		temp = c >> i;
		if (temp % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(40);
		i--;
	}
}

void	ft_handle_sig(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		ft_send_sig(pid, message[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(40);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_handle_sig(atoi(argv[1]), argv[2]);
	return (0);
}
