/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:53:19 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/11 21:11:40 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr(long nb)
{
	char	c;
	int		count;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		count ++;
	}
	if (nb >= 10)
	{
		count += ft_putnbr_fd(nb / 10);
	}
	c = '0' + (nb % 10);
	count += ft_putchar_fd(c);
	return (count);
}

int	ft_putnbr_unsigned(long n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_putchar(n + '0');
	else if (n > 9)
	{
		count += ft_putnbr_unsigned(n / 10);
		count += ft_putnbr_unsigned(n % 10);
	}
	return (count);
}
