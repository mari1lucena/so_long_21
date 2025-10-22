/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:32:01 by mlucena-          #+#    #+#             */
/*   Updated: 2025/05/06 20:14:34 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(t_ll nbr)
{
	long long	i;
	int			count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = nbr * -1;
	}
	i = nbr;
	if (i > 9)
	{
		count += ft_putnbr(i / 10);
		count += ft_putnbr(i % 10);
	}
	else
		count += ft_putchar(i + '0');
	return (count);
}
