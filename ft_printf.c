/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:14:15 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/11 21:10:25 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int possible_args(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned((long)va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (c == 'x')
		len += ft_puthex((long)va_arg(args, unsigned int), HEX_low);
	else if (c == 'X')
		len += ft_puthex((long)va_arg(args, unsigned int), HEX_high);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		len;
	va_list	args;

	len = 0;
	if (!str)
		return (-1);
	va_start(args, &str);
	while (str[i])
	{
		if (str[i] == "%")
		{
			len += possible_args(str[i + 1], args);
			i++;
		}
		else
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
