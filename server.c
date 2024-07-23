/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:08:47 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/23 17:37:01 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char		binary;
	static int		bits;

	(void)context;
	if (signum == SIGUSR1)
		binary = (binary << 1) | 1;
	else if (signum == SIGUSR2)
		binary <<= 1;
	bits++;
	if (bits == 8)
	{
		bits = 0;
		if (!binary)
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		ft_printf("%c", binary);
		binary = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
