/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:31:51 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:59:29 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Description: Allocates and returns a substring from the string s,          */
/* starting at index start and with maximum length len.                       */
static char	*allocate_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (i < len && s[start + i] != '\0')
		i++;
	sub = (char *)malloc(i + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	size_t	strlen;
	char	*sub;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
	{
		sub = (char *)malloc(1);
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	return (allocate_substr(s, start, len));
}
