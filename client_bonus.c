/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:09:22 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/23 17:40:40 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

static int	g_received;

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	g_received = 1;
	if (signum == SIGUSR1)
		ft_printf("Message received!\n");
}

void	ft_send_sig(int pid, unsigned int c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_received)
			pause();
		g_received = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	int					i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART | SA_SIGINFO;
		sa.sa_sigaction = sig_handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (argv[2][i])
			ft_send_sig(pid, argv[2][i++]);
		ft_send_sig(pid, '\0');
	}
	else if (argc == 2 || argc == 1)
		ft_printf("Too few arguments\n");
	else
		ft_printf("Too many arguments\n");
	return (0);
}
