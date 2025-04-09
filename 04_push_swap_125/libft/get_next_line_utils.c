/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:51:19 by layang            #+#    #+#             */
/*   Updated: 2025/01/24 12:59:03 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char	*src)
{
	int		len;
	int		i;
	char	*in;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	in = (char *)malloc(sizeof(char) * (len + 1));
	if (in == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		in[i] = src[i];
		i++;
	}
	in[len] = '\0';
	return (in);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*str;
	size_t	i;
	size_t	m;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	m = ft_strlen(s1);
	n = ft_strlen(s2);
	str = (char *)malloc(m + n + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < m)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < m + n)
	{
		str[i] = s2[i - m];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char	*s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
