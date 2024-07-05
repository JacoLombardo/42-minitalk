/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:52 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/05 15:38:17 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//#include "libft/libft.h"
#include <locale.h>

void	ft_extra_handle(int *binary, int *pid, int *i)
{
	setlocale(LC_CTYPE, "");
	if (*binary == 0)
	{
		printf("\n");
		kill(*pid, SIGUSR1);
		*pid = 0;
	}
	else
		printf("%lc", *binary);
	*binary = 0;
	*i = 0;
}

void	ft_sig_handler(int signum)
{
	static int	binary;
	static int	i;
	static int	pid;

	if (signum == SIGUSR2)
		binary |= 1;
	i++;
	if (i == 32 && !pid)
	{
		pid = binary;
		binary = 0;
		i = 0;
	}
	else if (i == 32 && pid)
		ft_extra_handle(&binary, &pid, &i);
	else
		binary <<= 1;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("The process ID is %d\n", pid);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1)
		pause();
	return (0);
}
