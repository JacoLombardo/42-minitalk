/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:52 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/03 17:06:14 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_sig_handler(int signum)
{
	static unsigned char	binary;
	static int				i;

	if (signum == SIGUSR1)
		binary |= 0;
	else
		binary |= 1;
	i++;
	if (i == 8)
	{
		if (binary == 0)
			printf("\n");
		else
			printf("%c", binary);
		binary = 0;
		i = 0;
	}
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
