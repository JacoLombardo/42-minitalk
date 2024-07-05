/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:09:22 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/05 16:34:51 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	ft_send_sig(pid_t pid, unsigned int c, int i)
{
	unsigned int	temp;

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

int	ft_prepare_message(pid_t pid_s, char *message, pid_t pid_c)
{
	int				i;
	unsigned int	*uni_chars;
	int				uni_chars_len;

	i = 0;
	uni_chars = extract_uni_all(message, &uni_chars_len);
	if (!uni_chars)
		return (0);
	ft_send_sig(pid_s, pid_c, 31);
	while (i < uni_chars_len)
	{
		ft_send_sig(pid_s, uni_chars[i], 31);
		i++;
	}
	i = 0;
	while (i < 32)
	{
		kill(pid_s, SIGUSR1);
		usleep(40);
		i++;
	}
	free(uni_chars);
	return (1);
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
	ft_printf("PID: %i\n", pid_c);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	if (argc == 3)
	{
		if (!ft_prepare_message(ft_atoi(argv[1]), argv[2], pid_c))
		{
			ft_printf("An error has occured\n");
			return (0);
		}
		while (1)
			pause();
	}
	else if (argc == 2 || argc == 1)
		ft_printf("Too few arguments\n");
	else
		ft_printf("Too many arguments\n");
	return (0);
}
