/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:20:27 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/11 21:11:44 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while(str[i])
	{
		write(1, str[i], 1);
	}
	return (i);
}

int	ft_puthex(unsigned long n, char *BASE)
{
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_putadress(n / 16, BASE);
		count += ft_putadress(n % 16, BASE);
	}
	else if (n < 16)
		count += ft_putchar(BASE[n]);
	return (count);
}

int	ft_putptr(va_list args)
{
	unsigned long	ptr;
	int				count;

	ptr = va_arg(args, unsigned long);
	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putadress(ptr, HEX_low);
	return (count);
}
