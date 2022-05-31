/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:19:33 by saguesse          #+#    #+#             */
/*   Updated: 2022/05/31 16:18:11 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	arg_type(const char *s, va_list args, int i, int j)
{
	
	if (s[j] == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (s[j] == 's')
		i += ft_putstr(va_arg(args, char*));
	else if (s[j] == 'd')
		ft_putnbr(va_arg(args, int));
	else if (s[j] == 'i')
		ft_putnbr(va_arg(args, int));
	else if (s[j] == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (s[j] == 'x')
		ft_putnbr_hexa(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (s[j] == 'X')
		ft_putnbr_hexa(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	else if (s[j] == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		j;
	int		i;

	va_start(args, s);
	i = 0;
	j = 0;
	while (j < ft_strlen(s))
	{
		while (s[j] != '%' && s[j])
		{
			ft_putchar(s[j]);
			j++;
			i++;
		}
		j++;
		i += arg_type(s, args, i, j);
		j++;
	}
	va_end(args);
	/*printf("\n%d", ft_strlen(s));
	printf("\n%d", j);
	printf("\n%d", i);*/
	return (i);
}

int	main()
{
	ft_printf("Entier d : %X %c %s %%%u", 42, 'c', "hello", 4294967296);
	printf("\n%X", 2147483637);
	return (0);
}
