/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:09:22 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/02 12:10:17 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*ft_ctob(char c)
{
	char	*arr;
	char	*base;
	int		i;

	base = "01";
	i = 7;
	arr = (char *)malloc(9 * sizeof(char));
	while (i >= 0)
	{
		arr[i] = base[c % 2];
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
		printf("TEMP: %s\n", temp);
		ft_strncat(binary, temp, strlen(temp));
		free(temp);
		i++;
	}
	return (binary);
}

int	main(int argc, char **argv)
{
	char	binary[800];

	if (argc == 3)
	{
		printf("MESSAGE: %s\n", argv[2]);
		printf("%s\n", ft_stob(argv[2], binary));
	}
	return (0);
}
