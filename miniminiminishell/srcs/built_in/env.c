#include "../../includes/miniminiminishell.h"

int	ms_env(t_env_node *env_list, char **argv)
{
	int		idx;
	char	*temp_value;
	
	while(env_list)
	{
		idx = -1;
		temp_value = NULL;
		while (argv[++idx])
		{
			if (ft_strncmp(env_list, argv[idx], ft_strlen(argv[idx])) == 0)
				temp_value = argv[idx];
		}
		if (temp_value)
			printf("%s=%s\n", env_list->key, temp_value);
		else
			printf("%s=%s\n", env_list->key, env_list->value);
		env_list = env_list->next;
	}
}

/*

	env: 	key && value 가 둘다있어야함 근데 진짜 들어가는 건 아님
			추가하든 안하든 무조건 출력
			key=value

	export: key만 있어도 됨
			추가할 때는 출력 X
			declare -x key="value"
	
*/
