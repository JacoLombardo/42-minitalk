/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:09:22 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/16 14:50:51 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	ft_send_sig(int pid, unsigned int c, int i)
{
	unsigned int	temp;

	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

void	ft_handle_msg(pid_t pid_s, char *message, pid_t pid_c)
{
	int	i;

	i = 0;
	ft_send_sig(pid_s, pid_c, 32);
	while (message[i])
		ft_send_sig(pid_s, message[i++], 8);
	ft_send_sig(pid_s, '\0', 8);
}

void	ft_sig_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message received!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	pid_c;

	pid_c = getpid();
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	if (argc == 3)
	{
		ft_handle_msg(ft_atoi(argv[1]), argv[2], pid_c);
		while (1)
			pause();
	}
	else if (argc == 2 || argc == 1)
		ft_printf("Too few arguments\n");
	else
		ft_printf("Too many arguments\n");
	return (0);
}
