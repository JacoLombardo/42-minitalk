/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:45:47 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/05 15:23:48 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

unsigned int	ft_uhandler(unsigned char *message, unsigned int *unicode,
		int *bytes_checked)
{
	int	i;

	i = 1;
	while (i < *bytes_checked)
	{
		if ((message[i] & 0xC0) != 0x80)
			return (0);
		*unicode = (*unicode << 6) | (message[i] & 0x3F);
		i++;
	}
	return (*unicode);
}

unsigned int	extract_uni(unsigned char *message, int *bytes_checked,
		unsigned int *unicode)
{
	*bytes_checked = 0;
	if (message[0] <= 0x7F)
	{
		*unicode = message[0];
		*bytes_checked = 1;
	}
	else if ((message[0] & 0xE0) == 0xC0)
	{
		*unicode = message[0] & 0x1F;
		*bytes_checked = 2;
	}
	else if ((message[0] & 0xF0) == 0xE0)
	{
		*unicode = message[0] & 0x0F;
		*bytes_checked = 3;
	}
	else if ((message[0] & 0xF8) == 0xF0)
	{
		*unicode = message[0] & 0x07;
		*bytes_checked = 4;
	}
	else
		return (0);
	return (ft_uhandler(message, unicode, bytes_checked));
}

unsigned int	*extract_uni_all(char *message, int *uni_chars_len)
{
	int				index;
	int				bytes_checked;
	unsigned int	*uni_chars;
	unsigned int	unicode;

	index = 0;
	unicode = 0;
	uni_chars = malloc(strlen(message) * sizeof(unsigned int));
	if (!uni_chars)
		return (NULL);
	while (*message != '\0')
	{
		unicode = extract_uni((unsigned char *)message, &bytes_checked,
				&unicode);
		uni_chars[index++] = unicode;
		message += bytes_checked;
	}
	*uni_chars_len = index;
	return (uni_chars);
}
