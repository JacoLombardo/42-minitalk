/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:08:47 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/08 14:10:46 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	ft_sig_handler(int signum)
{
	static int	binary;
	static int	i;

	if (signum == SIGUSR2)
		binary |= 1;
	i++;
	if (i == 8)
	{
		if (binary == 0)
		{
			ft_printf("\n");
		}
		else
			ft_printf("%c", binary);
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
	ft_printf("The process ID is %d\n", pid);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1)
		pause();
	return (0);
}
