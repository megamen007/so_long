/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:25:04 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/16 05:33:09 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_hexa(unsigned long int number, char *base, int len)
{
	unsigned long int	number2;

	number2 = number;
	if (number >= 16)
	{
		ft_put_hexa(number / 16, base, len);
		ft_put_hexa(number % 16, base, len);
	}
	else
		ft_putchar(base[number]);
	len = count_len(number2);
	return (len);
}

int	ft_pformat(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		len += printf_pointer(va_arg(arg, unsigned long int),
				"0123456789abcdef", len);
	else if (c == 'd')
		len += ft_putnbr(va_arg(arg, int), len);
	else if (c == 'i')
		len += ft_putnbr(va_arg(arg, int), len);
	else if (c == 'u')
		len += ft_putunsigned(va_arg(arg, unsigned int), len);
	else if (c == 'x')
		len += ft_put_hexa(va_arg(arg, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		len += ft_put_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF", len);
	else if (c == '%')
		len += ft_putsign();
	return (len);
}

int	count_len(unsigned long int number)
{
	int	i;

	i = 0;
	if (number == 0)
		i++;
	while (number > 0)
	{
		number /= 16;
		i++;
	}
	return (i);
}
