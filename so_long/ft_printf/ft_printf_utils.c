/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:22:34 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/16 05:34:50 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_pointer(unsigned long int i, char *base, int len)
{
	write(1, "0x", 2);
	len = 2;
	len += ft_put_hexa(i, base, len);
	return (len);
}

int	ft_putunsigned(unsigned int n, int len)
{
	if (n <= 9)
		len = ft_putchar((n + 48));
	else if (n > 9)
	{
		len += ft_putunsigned(n / 10, len);
		len += ft_putunsigned(n % 10, len);
	}
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	ft_putsign(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_putnbr(int number, int len)
{
	long int	n;

	n = number;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n <= 9)
		len = ft_putchar((n + 48));
	else if (n > 9)
	{
		len += ft_putnbr(n / 10, len);
		len += ft_putnbr(n % 10, len);
	}
	if (number < 0)
	{
		number = -number;
		return (len + 1);
	}
	return (len);
}
