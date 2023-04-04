#include "../../includes/miniminiminishell.h"

typedef struct s_list
{
	char			*string;
	struct s_token	*next;
}	t_list;

t_list	*make_argv_node(char *str)
{
	t_list	*argv_node;

	argv_node = malloc(sizeof(t_list));
	argv_node->string = ft_strdup(str);
	argv_node->next = NULL;
	return (argv_node);
}

t_cmd	*make_cmd_node(void) // 얘만 빈통으로 만들어줌
{
	t_cmd	*cmd_node;

	cmd_node = malloc(sizeof(t_cmd));
	cmd_node->argv = NULL;
	cmd_node->redirection = NULL;
	// cmd_node->pipe = NULL;
	cmd_node->prev = NULL;
	cmd_node->next = NULL;
	return (cmd_node);
}

t_redirection	*make_redirection_node(char *sign, char *file)
{
	t_redirection	*new_redirection;

	new_redirection = malloc(sizeof(t_redirection));
	new_redirection->type = ft_strdup(sign);
	new_redirection->file = ft_strdup(file);
	new_redirection->next = NULL;
	return (new_redirection);
}

int	find_list_size(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char	**change_list_to_double_ptr(t_list *argv_list)
{
	char	**res;
	int		list_size;
	int		i;

	i = 0;
	list_size = find_list_size(argv_list);
	res = (char **)malloc(sizeof(char *) * (list_size + 1));
	while (argv_list)
		res[i++] = ft_strdup(argv_list->string);
	res[i] = NULL;
	return (res);
}


t_cmd	*create_cmd_list(t_token *token_list)
{
	t_cmd			*cmd_list;
	t_redirection	*redirection_list;
	t_list			*argv_list;
	t_cmd			*head;

	cmd_list = make_cmd_node();
	argv_list = NULL;
	head = cmd_list;
	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_REDIRECTION) //리다이렉션 만나면 다음 두 노드 밀고 리다이렉션 멤버에 등록해준다
		{
			redirection_list = make_redirection_node(token_list->string, token_list->next->string);// ->[< a] [< b] < c
			if (cmd_list->redirection) // 없으면 만들고
				cmd_list->redirection = redirection_list;
			else // 있으면 뒤에 이어준다
				redirection_list = redirection_list->next; //////// 땡스투자리
			token_list = token_list->next; // 두개 옮겨야 해서 여기서도 한번 옮김
		}
		else if (token_list->type == TOKEN_TYPE_PIPELINE)// 파이프 만나면 여태까지 만든 argv리스트 다 이중포인터로 할당해서 등록해준다
		{ //그냥 끝일때 처리 해줘야함
			cmd_list->argv = change_list_to_double_ptr(argv_list);
			// argv리스트 프리
			cmd_list->next = make_cmd_node();
			cmd_list = cmd_list->next;
		}
		else if (token_list->type == TOKEN_TYPE_ARGV) // 파이프를 만나기 전까지 argv_list에 추가해준다
		{
			if (argv_list) // 아직 argv만나지 못했으면
				argv_list = make_argv_node(token_list->string);
			else
			{
				argv_list->next = make_argv_node(token_list->string);
				argv_list = argv_list->next;
			}
		}
		token_list = token_list->next;
	}
	// 여기서 argv 처리
	return (head);
}