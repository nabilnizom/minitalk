/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohd-ni <amohd-ni@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:05:06 by amohd-ni          #+#    #+#             */
/*   Updated: 2022/05/08 23:05:06 by amohd-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_usint(unsigned int n)
{
	int		size;
	char	c;

	size = 0;
	if (n >= 10)
		size += ft_printf_usint((int)(n / 10));
	c = (n % 10) + '0';
	size += write(1, &c, 1);
	return (size);
}
