/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:53:19 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/12 10:31:06 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
	}
	c = '0' + (nb % 10);
	count += ft_putchar(c);
	return (count);
}

int	ft_putnbr_unsigned(long nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putnbr_unsigned(nb / 10);
	}
	c = '0' + (nb % 10);
	count += ft_putchar(c);
	return (count);
}

int	ft_puthex(t_ul nb, char *BASE)
{
	int		count;

	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16, BASE);
	count += ft_putchar(BASE[nb % 16]);
	return (count);
}
