/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:34:06 by saguesse          #+#    #+#             */
/*   Updated: 2022/06/02 14:42:06 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(size_t nb, char *base)
{
	int	i;

	i = 0;
	if (nb < 16)
		i += ft_putchar(base[nb]);
	else
	{
		i += ft_putptr(nb / 16, base);
		i += ft_putptr(nb % 16, base);
	}
	return (i);
}

int	check_if_null(size_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (i += ft_putstr("(nil)"));
	else
	{
		i += ft_putstr("0x");
		i += ft_putptr(nb, "0123456789abcdef");
	}
	return (i);
}
