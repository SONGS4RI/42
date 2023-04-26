/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:07 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/21 16:44:09 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_space_token(t_token **token_list)
{
	t_token	**head;
	t_token	*cur;

	head = token_list;
	cur = *token_list;
	while (cur)
	{
		if (cur->type == TOKEN_TYPE_SPACE)
		{
			cur = delete_token(cur, head);
			continue ;
		}
		cur = cur->next;
	}
}
