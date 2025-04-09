/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:52:25 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 12:00:17 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Description: Allocates and returns a copy of s1 with the characters        */
/* specified in set removed from the beginning and the end.                   */
static int	find_set(char c, char	*charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	int		i;
	int		start;
	int		end;
	char	*subset;

	start = 0;
	while (s1[start] && find_set(s1[start], (char *)set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && find_set(s1[end], (char *)set))
		end--;
	subset = (char *)malloc(end - start + 2);
	if (!subset)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		subset[i] = s1[start];
		i++;
		start++;
	}
	subset[i] = '\0';
	return (subset);
}
