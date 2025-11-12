/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:14:15 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/12 14:09:02 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	possible_args(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr((long)va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned((long)va_arg(args, t_ui));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, t_ull));
	else if (c == 'x')
		len += ft_puthex((t_ul)va_arg(args, t_ui), HEX_LOW);
	else if (c == 'X')
		len += ft_puthex((t_ul)va_arg(args, t_ui), HEX_HIGH);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = -1;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
			len += possible_args(str[++i], args);
		else
			len += ft_putchar((int)str[i]);
	}
	va_end(args);
	return (len);
}
