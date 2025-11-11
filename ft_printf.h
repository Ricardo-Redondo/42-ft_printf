/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:35:47 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/11 22:11:11 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_HIGH "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	possible_args(char c, va_list args);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_puthex(unsigned long n, char *BASE);
int	ft_putptr(unsigned long long ptr);
int	ft_putnbr(long nb);
int	ft_putnbr_unsigned(long nb);

#endif