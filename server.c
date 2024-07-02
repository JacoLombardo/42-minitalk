/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:52 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/02 17:34:45 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	btoc(char *binary)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	while (i < 8)
	{
		value = (value << 1) | (binary[i] - '0');
		i++;
	}
	return ((char)value);
}

char	*ft_btos(char *binary, char *message)
{
	char	byte[9];
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = strlen(binary) / 8;
	bzero(byte, 8);
	while (i < len)
	{
		strncpy(byte, &binary[j], 8);
		byte[8] = '\0';
		message[i] = btoc(byte);
		j += 8;
		bzero(byte, 8);
		i++;
	}
	message[len] = '\0';
	return (message);
}

int	ft_check_terminator(char *binary)
{
	int	i;
	int	len;

	i = 0;
	len = strlen(binary);
	while (i < 8)
	{
		if (binary[len - i - 1] == '0')
			i++;
		else
			return (0);
	}
	return (1);
}

/* void	ft_sig_handler(int signum)
{
	static char	binary[800];
	static int	i;
	char		message[800];

	if (signum == SIGUSR1)
	{
		binary[i] = '0';
		i++;
	}
	else
	{
		binary[i] = '1';
		i++;
	}
	if (ft_check_terminator(binary))
	{
		binary[i - 8] = '\0';
		printf("%s\n", ft_btos(binary, message));
		bzero(binary, 800);
		bzero(message, 800);
		i = 0;
	}
} */

void	ft_sig_handler(int signum)
{
	static char	binary[800];
	static int	i;
	char		message[800];

	if (signum == SIGUSR1)
	{
		binary[i] = '0';
		i++;
	}
	else
	{
		binary[i] = '1';
		i++;
	}
	if (ft_check_terminator(binary))
	{
		binary[i - 8] = '\0';
		printf("%s\n", ft_btos(binary, message));
		bzero(binary, 800);
		bzero(message, 800);
		i = 0;
	}
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
