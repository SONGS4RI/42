/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:00 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/20 22:09:43 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*lexical_analysis(t_info *info, char *input)
{
	t_token	*token_list;

	token_list = create_token(input, TOKEN_TYPE_CHUNK);
	handle_heredoc_limiter(info, token_list);
	handle_quotes(info, token_list);
	handle_environment_variables(info, token_list);
	seperate_token_by_arg(token_list, " ");
	seperate_token_by_arg(token_list, "|");
	seperate_token_by_arg(token_list, "<<");
	seperate_token_by_arg(token_list, ">>");
	seperate_token_by_arg(token_list, "<");
	seperate_token_by_arg(token_list, ">");
	handle_chunk(&token_list);
	merge_continuous_argv_token(&token_list);
	remove_space_token(&token_list);
	return (token_list);
}
