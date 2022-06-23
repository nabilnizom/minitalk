/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohd-ni <amohd-ni@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:05:06 by amohd-ni          #+#    #+#             */
/*   Updated: 2022/05/08 23:05:06 by amohd-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(int num, char lettercase)
{
	int				size;
	unsigned int	unsigned_num;
	char			c;

	size = 0;
	if (num < 0)
		unsigned_num = 4294967295 + num + 1;
	else
		unsigned_num = (unsigned int)(num);
	if (unsigned_num >= 16)
		size += ft_printf_hex((int)(unsigned_num / 16), lettercase);
	unsigned_num = unsigned_num % 16;
	if (lettercase == 'x')
		c = "0123456789abcdef"[unsigned_num];
	else
		c = "0123456789ABCDEF"[unsigned_num];
	size += write(1, &c, 1);
	return (size);
}
