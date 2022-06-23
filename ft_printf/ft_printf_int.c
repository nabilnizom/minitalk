/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohd-ni <amohd-ni@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:05:06 by amohd-ni          #+#    #+#             */
/*   Updated: 2022/05/08 23:05:06 by amohd-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int num)
{
	int				size;
	unsigned int	unsigned_num;
	char			c;

	size = 0;
	if (num < 0)
	{
		size += write(1, "-", 1);
		unsigned_num = (unsigned int)(num * -1);
	}
	else
		unsigned_num = (unsigned int)num;
	if (unsigned_num >= 10)
		size += ft_printf_int((int)(unsigned_num / 10));
	c = (unsigned_num % 10) + '0';
	size += write(1, &c, 1);
	return (size);
}
