/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:03:15 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 17:05:20 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	ft_isalnum(int c)
// {
// 	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
//           || (c >= '0' && c <= '9'))
// 		return (1);
// 	else
// 		return (0);
// }
// int	main ()
// {
// 	int a = 'a';
// 	int teste = '\n';
// 	while(a <= 'z')
// 	{
// 		printf("\n%d : %d", a, ft_isalnum(a));
// 		a++;
// 	}
// 	a = 'A';
// 	while(a <= 'Z')
// 	{
// 		printf("\n%d : %d", a, ft_isalnum(a));
// 		a++;
// 	}
// 	a = 0;
// 	while(a <= 9)
// 	{
// 		printf("\n%d : %d", a, ft_isalnum(a));
// 		a++;
// 	}
// 	printf("\n%d : %d", teste, ft_isalnum(teste));
// 	return 0;
// }