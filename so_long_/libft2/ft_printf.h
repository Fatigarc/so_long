/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:18:20 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/21 13:03:58 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_printf(char const *format, ...);
int	verify_format(char conver, va_list ap);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	nbr_b(long n, char *base_values, int base);
int	nbr_p(uintptr_t n, char *base_values, int base);

#endif
