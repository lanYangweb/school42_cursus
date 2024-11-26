/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:51:19 by layang            #+#    #+#             */
/*   Updated: 2024/11/25 20:01:17 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	*ft_memcpy(void	*dst, const void	*src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void	*dst, const void	*src, size_t n)
{
	size_t	i;

	if (dst == src || n == 0)
		return (dst);
	if (dst < src)
	{
		ft_memcpy(dst, src, n);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		}
	}
	return (dst);
}

char	*alloc_copy(char	*line, size_t len, char	*buffer, size_t copy_len)
{
	char	*new_line;

	new_line = malloc(len + copy_len + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	if (line)
	{
		ft_memcpy(new_line, line, len);
		free(line);
	}
	ft_memcpy(new_line + len, buffer, copy_len);
	new_line[len + copy_len] = '\0';
	return (new_line);
}

int	find_newline(char	*buffer, size_t bytes_read, size_t *index)
{
	size_t	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			*index = i;
			return (1);
		}
		i++;
	}
	return (0);
}
