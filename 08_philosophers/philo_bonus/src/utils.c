/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:53:20 by layang            #+#    #+#             */
/*   Updated: 2025/05/22 11:33:26 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_numeric(const char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	while (*str == ' ')
		str++;
	if (*str == '\0' && i > 0)
		return (1);
	return (0);
}

static char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	while (s[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_utoa(unsigned int n)
{
	char	tmp[12];
	int		i;
	int		j;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	while (n > 0)
	{
		tmp[i++] = (n % 10) + '0';
		n /= 10;
	}
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	j = 0;
	while (i-- > 0)
		res[j++] = tmp[i];
	return (res);
}

char	*strjoin_free(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		dest[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	free((void *)s2);
	return (dest);
}
