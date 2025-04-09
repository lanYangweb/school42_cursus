/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:20:06 by layang            #+#    #+#             */
/*   Updated: 2025/03/07 17:18:03 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Description: Allocates and returns a new string which is the result of the */
/* concatenation of s1 and s2.
                                             */
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

void	ft_free_array(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}
