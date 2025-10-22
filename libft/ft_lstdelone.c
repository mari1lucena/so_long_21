/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:10:10 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 15:39:17 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

// int main()
// {
// 	t_list	*lst;
// 	char *str = "ola";	
// 	lst = ft_lstnew(str);
// 	printf("antes de deletar: %s\n", (char *)lst->content);
// 	ft_lstdelone(lst, free);
// 	printf("depois de deletar: %s\n", (char *)lst->content);
// 	return (0);
// }
