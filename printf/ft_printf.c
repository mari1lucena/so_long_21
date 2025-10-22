/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:13 by mlucena-          #+#    #+#             */
/*   Updated: 2025/05/12 12:28:13 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkletter(const char *str, va_list args)
{
	int		count;

	count = 0;
	if (*str == 'c')
		count += ft_putchar(va_arg(args, int));
	if (*str == 's')
		count += ft_putstr(va_arg(args, char *));
	if (*str == 'p')
		count += ft_putadress(va_arg(args, t_ull));
	if (*str == 'd' || *str == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (*str == 'u')
		count += ft_putnbr(va_arg(args, unsigned int));
	if (*str == 'x' || *str == 'X')
		count += ft_hexa(va_arg(args, unsigned int), *str);
	if (*str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_checkletter(str, args);
			str++;
		}
		else
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	va_end(args);
	return (count);
}
