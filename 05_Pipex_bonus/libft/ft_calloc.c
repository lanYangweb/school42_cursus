/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:47:48 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 12:11:43 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stddef.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> */

#include "libft.h"

/* void check(int condition)
{
	if (!condition)
	{
		write(2, "Check failed\n", 13);
		exit(1);
	}
} */
/* Description: Allocates memory for an array of count elements of size bytes */
/* each and initializes all bytes to zero.                                    */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*m;
	size_t	i;

	if (nmemb && size > ((size_t)-1) / nmemb)
		return (NULL);
	m = (void *)malloc(nmemb * size);
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)m)[i] = 0;
		i++;
	}
	return (m);
}

/* int main(void)
{
	// Test case for the specific case of ft_calloc(-5, -5)
	if (ft_calloc(-5, -5) == NULL)
		write(1, "NULL", 5);
	write(1, "\n", 1);
	return 0;
} */