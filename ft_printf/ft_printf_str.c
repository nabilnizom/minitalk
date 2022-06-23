/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohd-ni <amohd-ni@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:05:06 by amohd-ni          #+#    #+#             */
/*   Updated: 2022/05/08 23:05:06 by amohd-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char	*str)
{
	int	size;

	size = 0;
	if (str == NULL)
	{
		size += write(1, "(null)", 6);
		return (size);
	}
	else
	{
		while (*str)
		{
			size += write(1, str, 1);
			str++;
		}
	}
	return (size);
}
