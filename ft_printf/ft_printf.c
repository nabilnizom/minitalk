/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohd-ni <amohd-ni@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:05:06 by amohd-ni          #+#    #+#             */
/*   Updated: 2022/05/08 23:05:06 by amohd-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;
	char	*str_write;

	size = 0;
	va_start(args, str);
	str_write = (char *)str;
	while (*str_write)
	{
		if (*str_write != '%')
			write(1, (str_write), 1);
		else
			size += check_type(++str_write, args) - 1;
		size++;
		str_write++;
	}
	va_end(args);
	return (size);
}

int	check_type(char *type, va_list args)
{
	int		size;
	char	c;

	size = 0;
	if (*type == 'c')
	{
		c = va_arg(args, int);
		size += write(1, &c, 1);
	}
	else if (*type == 's')
		size += ft_printf_str(va_arg(args, char *));
	else if (*type == 'i' || *type == 'd')
		size += ft_printf_int(va_arg(args, int));
	else if (*type == 'p')
	{
		size += write(1, "0x", 2);
		size += ft_printf_pointer(va_arg(args, size_t));
	}
	else if (*type == 'u')
		size += ft_printf_usint(va_arg(args, unsigned int));
	else if (*type == 'x' || *type == 'X')
		size += ft_printf_hex(va_arg(args, int), *type);
	else if (*type == '%')
		size += write(1, "%", 1);
	return (size);
}
