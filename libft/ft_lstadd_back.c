/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:02:10 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/21 20:52:46 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*x;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	x = ft_lstlast(*lst);
	x -> next = new;
}

// int main()
// {
// 	t_list	*t1 = ft_lstnew("oi");
// 	t_list	*t2 = ft_lstnew("hi"); 

// 	ft_lstadd_back(&t1, t2);
// 	printf("%s\n", (char *)t1->content);
// 	printf("%s\n", (char *)t1->next->content);
// }