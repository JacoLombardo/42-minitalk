/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:09:22 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/02 16:57:56 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*ft_ctob(char c)
{
	char	*arr;
	int		i;

	i = 7;
	arr = (char *)malloc(9 * sizeof(char));
	while (i >= 0)
	{
		if (c % 2)
			arr[i] = '1';
		else
			arr[i] = '0';
		c /= 2;
		i--;
	}
	arr[8] = '\0';
	return (arr);
}

char	*ft_stob(char *str, char *binary)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
	{
		temp = ft_ctob(str[i]);
		//printf("TEMP: %s\n", temp);
		ft_strncat(binary, temp, strlen(temp));
		free(temp);
		i++;
	}
	ft_strncat(binary, "00000000", 8);
	return (binary);
}

void	ft_send_sig(pid_t pid, char c)
{
	if (c == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(20);
}

void	ft_handle_sig(pid_t pid, char *message, char *binary)
{
	int	i;

	i = 0;
	ft_stob(message, binary);
	printf("BINARY: %s\n", binary);
	while (binary[i])
	{
		ft_send_sig(pid, binary[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	binary[800];

	bzero(binary, 800);
	if (argc == 3)
	{
		printf("MESSAGE: %s\n", argv[2]);
		ft_handle_sig(atoi(argv[1]), argv[2], binary);
	}
	return (0);
}
