/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_continuous_argv_token.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:03 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/21 16:43:09 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// ARGV, ARGV => ARGV
void	merge_continuous_argv_token(t_token **token_list)
{
	t_token	**head;
	t_token	*cur;
	char	*merge_str;

	head = token_list;
	cur = *token_list;
	while (cur && cur->next)
	{
		if (cur->type == TOKEN_TYPE_ARGV && cur->next->type == TOKEN_TYPE_ARGV)
		{
			merge_str = ft_strjoin(cur->string, cur->next->string);
			free(cur->string);
			cur->string = merge_str;
			delete_token(cur->next, head);
		}
		else
			cur = cur->next;
	}
}
