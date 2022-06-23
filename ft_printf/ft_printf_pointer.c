/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohd-ni <amohd-ni@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:05:06 by amohd-ni          #+#    #+#             */
/*   Updated: 2022/05/08 23:05:06 by amohd-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(size_t	addr)
{
	int		size;
	char	c;

	size = 0;
	if (addr >= 16)
		size += ft_printf_pointer(addr / 16);
	c = "0123456789abcdef"[addr % 16];
	size += write(1, &c, 1);
	return (size);
}
