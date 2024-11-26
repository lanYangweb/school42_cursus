/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:39:46 by layang            #+#    #+#             */
/*   Updated: 2024/11/18 13:27:17 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_by_sign(va_list	a_list, const char c)
{
	int	char_n;

	char_n = 0;
	if (c == 'c')
		char_n += ft_putchar_n(va_arg(a_list, int));
	else if (c == 's')
		char_n += ft_putstr_n(va_arg(a_list, char *));
	else if (c == 'u')
		char_n += ft_put_un(va_arg(a_list, unsigned int));
	else if (c == 'i' || c == 'd')
		char_n += ft_put_n(va_arg(a_list, int));
	else if (c == 'x')
		char_n += ft_put_h(va_arg(a_list, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		char_n += ft_put_h(va_arg(a_list, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		char_n += ft_put_ptr(va_arg(a_list, void *));
	else if (c == '%')
		char_n += ft_putchar_n('%');
	else
		char_n += write(1, "(unknown)", 9);
	return (char_n);
}

int	ft_printf(const char	*format, ...)
{
	int		i;
	va_list	a_list;
	int		char_num;

	i = 0;
	char_num = 0;
	va_start(a_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			char_num += convert_by_sign(a_list, format[i + 1]);
			i++;
		}
		else
			char_num += ft_putchar_n(format[i]);
		i++;
	}
	va_end(a_list);
	return (char_num);
}
