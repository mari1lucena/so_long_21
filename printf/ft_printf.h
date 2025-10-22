/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:32:01 by mlucena-          #+#    #+#             */
/*   Updated: 2025/05/06 18:40:57 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long	t_ull;
typedef long long			t_ll;

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_hexa(t_ull hexa, char c);
int	ft_putnbr(t_ll nbr);
int	ft_putadress(t_ull	adress);

#endif