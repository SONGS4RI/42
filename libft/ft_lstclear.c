/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:54:18 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/24 14:18:32 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*target;
	t_list	*tmp;

	target = *lst;
	if (!lst || !del)
		return ;
	while (target)
	{
		tmp = target->next;
		ft_lstdelone(target, del);
		target = tmp;
	}
	*lst = NULL;
}
