/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:07:58 by mboudrio          #+#    #+#             */
/*   Updated: 2022/11/23 15:30:52 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_pformat(va_list arg, char c);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int number, int counter);
int	ft_putunsigned(unsigned int n, int counter);
int	ft_put_hexa(unsigned long int number, char *base, int counter);
int	ft_putsign(void);
int	printf_pointer(unsigned long int i, char *base, int len);
int	count_len(unsigned long int k);

#endif
