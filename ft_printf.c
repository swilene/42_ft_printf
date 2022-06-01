/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:19:33 by saguesse          #+#    #+#             */
/*   Updated: 2022/06/01 18:53:33 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	arg_type(const char c, va_list args, int i)
{
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_putnbr_hexa(va_arg(args, long unsigned int), 16,
				"0123456789abcdef");
	}
	else if (c == 'i' || c == 'd')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_putnbr_hexa(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		i += ft_putnbr_hexa(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	else if (c == '%')
		i += ft_putchar('%');
	else
		ft_putstr("Error\n");
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
		if (s[j] == '%')
		{
			j++;
			i += arg_type(s[j], args, 0);
			j++;
		}
		else
		{
			i += ft_putchar(s[j]);
			j++;
		}
	}
	va_end(args);
	return (i);
}

int	main()
{
	//char	s[] = "hello";
	//int i = 25421;
	//char c = 's';

	ft_printf("%d\n", ft_printf("%p\n", (int)0));
	printf("%d\n", printf("%p\n", (void *)0));
	return (0);
}
