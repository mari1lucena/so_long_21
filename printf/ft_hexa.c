/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:17:22 by mlucena-          #+#    #+#             */
/*   Updated: 2025/05/06 20:42:47 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(t_ull hexa, char c)
{
	int	count;

	count = 0;
	if (hexa > 15)
	{
		count += ft_hexa(hexa / 16, c);
		count += ft_hexa(hexa % 16, c);
	}
	else if (hexa < 10)
		count += ft_putchar(hexa + '0');
	else if (hexa >= 10 && hexa <= 15)
	{
		if (c == 'x')
			count += ft_putchar(hexa - 10 + 'a');
		else if (c == 'X')
			count += ft_putchar(hexa - 10 + 'A');
	}
	return (count);
}
