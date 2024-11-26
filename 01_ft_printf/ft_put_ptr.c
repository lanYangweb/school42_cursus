/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:35:24 by layang            #+#    #+#             */
/*   Updated: 2024/11/18 13:33:32 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
functions to convert pointer: %p
*/

int	ft_put_ptr(void	*ptr_hex)
{
	int	len;

	len = 0;
	if (!ptr_hex)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += ft_put_h((unsigned long)ptr_hex, "0123456789abcdef");
	return (len);
}
