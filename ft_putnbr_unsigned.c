/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:36:39 by saguesse          #+#    #+#             */
/*   Updated: 2022/05/31 12:24:40 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n <= 9)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
