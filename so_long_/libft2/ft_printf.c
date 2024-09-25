/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:15 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/21 13:03:50 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	verify_format(char conver, va_list ap)
{
	int	count;

	count = 0;
	if (conver == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (conver == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (conver == 'p')
	{
		count = ft_putstr("0x");
		count += nbr_p(va_arg(ap, unsigned long), "0123456789abcdef", 16);
	}
	else if (conver == 'd' || conver == 'i')
		count = nbr_b(va_arg(ap, int), "0123456789", 10);
	else if (conver == 'u')
		count = nbr_b(va_arg(ap, unsigned int), "0123456789", 10);
	else if (conver == 'x')
		count = nbr_b(va_arg(ap, unsigned int), "0123456789abcdef", 16);
	else if (conver == 'X')
		count = nbr_b(va_arg(ap, unsigned int), "0123456789ABCDEF", 16);
	else if (conver == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	arg_p;
	int		printed_nbr;

	va_start(arg_p, format);
	printed_nbr = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			printed_nbr += verify_format(*(++format), arg_p);
			if (printed_nbr < 0)
				return (-1);
		}
		else
		{
			printed_nbr += write(1, format, 1);
			if (printed_nbr < 0)
				return (-1);
		}
		format++;
	}
	va_end(arg_p);
	return (printed_nbr);
}
