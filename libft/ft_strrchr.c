/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:22:12 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/07 14:50:17 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (p[i] == (char)c)
			return (p + i);
		i--;
	}
	return (NULL);
}
