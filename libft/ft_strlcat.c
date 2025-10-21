/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:34:21 by mlucena-          #+#    #+#             */
/*   Updated: 2025/04/22 19:21:19 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//concatena apenas o tamanho de size
//retorna o espaço total que era necessario para concatenar
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	dstlen = 0;
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	i = 0;
	if (dstlen < size)
	{
		while ((i + dstlen) < (size - 1) && src[i])
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		dst[i + dstlen] = '\0';
	}
	return (dstlen + srclen);
}

// int main ()
// {
// 	char str[] = "hello";
// 	const char *src = " world";

// 	printf("%zu\n", ft_strlcat(str, src, 12));
// 	printf("%s\n", str);
// }