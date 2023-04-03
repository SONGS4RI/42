#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

/**
 * 1. quote 해석 -> ", '
 * 2. $ 환경변수 해석
 * 3. 공백 분리
 * 4. 연산자 (파이프, 리다이렉션) 분리
 * 5. 연속된 argv 병합
 * 6. 공백 소각
 */


int	check_quote(char *input)
{
	int single_quote = 1, double_quote = 1;

	int	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			single_quote *= -1;
		else if (input[i] == '\"')
			double_quote *= -1;
	}
}

char *func(int start_idx,char *s)// 무조건 ' or " idx == 문자열에서 시작 idx
{//토큰화하고 , 토큰타입
	int i = start_idx;

	while (s[++i])
		if (s[i] == s[start_idx]) return ft_substr(s, start_idx, i - start_idx);
	return	NULL;
}
/*
123"123"123
123
"123$a "
123
*/



# define single_quote 1
# define double_quote 2

/*
처리과정
|echo "aaa $a"| ==> aaa $a
|echo |+|aaa 123|
|echo aaa 123|
echo ,aaa ,123

*/

/*

1.

|echo "aaa $a"|
|echo aaa 123|

|echo "aaa $a"|
|echo |+|aaa $a| => |echo |+|aaa | + |123|
|echo aaa 123|
|echo|, | |, |aaa|, | |, |$a|
|echo|, | |, |aaa|, | |, |123|
|echo aaa 123|

echo "aaa 123" | cat -e

2.
|echo 'aaa $a'|
|echo aaa $a|
|echo|, | |, |aaa|, | |, |$a|

*/

/*
echo '$a' => echo ,$a
			    D,  S,
echo "aaa $a" => echo aaa 123 => "echo", " ", "aaa", " ", "123"

echo '$a' => echo $a => echo, $a
*/

typedef struct s_token
{
	char			*token;
	char			*original_str;
	// int				이건 환경변수 해석해야함
	int				type;
	struct s_token	*next;
}	t_token;


int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("🥨 minishell$ ");
		// 1. quote 해석
		free(input);
	}
	return (0);
}
//-lreadline -L/Users/jahlee/.brew/Cellar/readline/8.2.1/lib -I/Users/jahlee/.brew/Cellar/readline/8.2.1/include