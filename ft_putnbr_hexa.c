/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:07 by saguesse          #+#    #+#             */
/*   Updated: 2022/06/01 17:09:26 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_hexa(size_t nb, size_t size, char *base)
{
	int	i;

	i = 0;
	if (nb < size)
		i += ft_putchar(base[nb]);
	else
	{
		i += ft_putnbr_hexa(nb / size, size, base);
		i += ft_putnbr_hexa(nb % size, size, base);
	}
	return (i);
}
