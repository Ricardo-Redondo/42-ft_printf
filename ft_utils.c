/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:20:27 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/11 22:09:10 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long n, char *BASE)
{
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, BASE);
		count += ft_puthex(n % 16, BASE);
	}
	else if (n < 16)
		count += ft_putchar(BASE[n]);
	return (count);
}

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(ptr, HEX_LOW);
	return (count);
}
