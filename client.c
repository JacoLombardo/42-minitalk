/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:08:36 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/08 14:42:48 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	ft_send_sig(int pid, unsigned int c)
{
	int				i;
	unsigned int	temp;

	i = 8;
	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(10);
	}
}

void	ft_handle_msg(pid_t pid_s, char *message)
{
	int	i;

	i = 0;
	while (message[i])
		ft_send_sig(pid_s, message[i++]);
	i = 0;
	while (i < 8)
	{
		kill(pid_s, SIGUSR1);
		usleep(10);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_handle_msg(ft_atoi(argv[1]), argv[2]);
	else if (argc == 2 || argc == 1)
		ft_printf("Too few arguments\n");
	else
		ft_printf("Too many arguments\n");
	return (0);
}
