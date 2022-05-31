/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:07 by saguesse          #+#    #+#             */
/*   Updated: 2022/05/31 16:11:20 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hexa(unsigned int nb, unsigned int size, char *base)
{
	if (/*nb >= 0 &&*/ nb < size)
		ft_putchar(base[nb]);
	/*else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_hexa(-nb, size, base);
	}*/
	else
	{
		ft_putnbr_hexa(nb / size, size, base);
		ft_putnbr_hexa(nb % size, size, base);
	}
}
