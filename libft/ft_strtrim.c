/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:21:50 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 15:48:11 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    char    *str;
    
    if (!s1 || !set)
        return (NULL);
    
    start = 0;
    end = ft_strlen(s1);
    
    // Encontra o início (primeiro caractere que NÃO está em 'set')
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    
    // Encontra o fim (último caractere que NÃO está em 'set')
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
    
    // Aloca memória para a nova string
    str = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!str)
        return (NULL);
    
    // Copia a parte trimada
    ft_strlcpy(str, s1 + start, end - start + 1);
    return (str);
}

// int main()
// {
// 	printf("%s\n", ft_strtrim(" Hel lo! ", " "));
// 	printf("%s\n", ft_strtrim(" Hello! ", " "));
// 	printf("%s\n", ft_strtrim(" Hello!", " "));
// 	printf("%s\n", ft_strtrim("Hello! ", " "));
// 	printf("%s\n", ft_strtrim("Hello!", " "));
// 	printf("%s\n", ft_strtrim("", ""));
// 	printf("%s\n", ft_strtrim(" Hello! ", ""));
// 	printf("%s\n", ft_strtrim("", " "));
// }