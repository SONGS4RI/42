#include "../../includes/miniminiminishell.h"

/*

03/29 TO DO LIST
1. quotes 안 $? 해석
2. 연속된 argv 토큰 병합
3. space 토큰 제거

*/

t_token	*lexical_analysis(t_info *info, char *input)
{
	t_token	*token_list;

	// 1. input -> chunk
	token_list = create_token(input, TOKEN_TYPE_CHUNK);
	printf("============ 1 토큰 생성 ===============\n");
	print_token_list(token_list);
	// 2. handle quotes
	handle_quotes(info->env_list, token_list);
	printf("============ 2 따옴표 처리 ==============\n");
	print_token_list(token_list);
	// 3. handle environment variables
	handle_environment_variables(info, token_list);
	printf("============ 3 환경변수 처리 =============\n");
	print_token_list(token_list);
	// 4. seperate space token
	seperate_token_by_arg(token_list, " ");
	printf("============ 4 공백으로 나누기 ===========\n");
	print_token_list(token_list);
	// 5. seperate pipeline token
	seperate_token_by_arg(token_list, "|");
	printf("============ 5 파이프로 나누기 ===========\n");
	print_token_list(token_list);
	// 6. seperate redirection toekn << < > >>
	seperate_token_by_arg(token_list, "<<");
	seperate_token_by_arg(token_list, ">>");
	seperate_token_by_arg(token_list, "<");
	seperate_token_by_arg(token_list, ">");
	printf("============ 6 리다이렉션으로 나누기 ======\n");
	print_token_list(token_list);
	// 7. remove empty chunk & change chunk to argv
	handle_chunk(token_list);
	printf("============ 7 토큰 정리 ===============\n");
	print_token_list(token_list);
	// 8. remove space token
	return (token_list);
}
