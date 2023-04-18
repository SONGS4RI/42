#include "../../includes/miniminiminishell.h"

void	signal_handler(int signum)
{
	(void)signum;
	ft_putendl_fd(CYAN"💎 minishell-1.0$ "RESET, STDOUT_FILENO);
	g_exit_status = 1;
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

// void	parent_handler(int signum)
// {
// 	if (signum == SIGINT)
// 		ft_putendl_fd("here", STDERR_FILENO);
// }

void	child_handler(int signum)
{
	(void)signum;
	rl_on_new_line();
	rl_replace_line("why", 1);
	rl_redisplay();
}

void	heredoc_handler(int signum)
{
	(void)signum;
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	ft_putendl_fd("", STDERR_FILENO);
	exit(1);
}

void	quit_handler(int signum)
{
	(void)signum;
	exit(1);
}

void	set_signal(void)
{
	signal(SIGINT, signal_handler);	// ctrl + C
	signal(SIGQUIT, SIG_IGN);		// ctrl + "\"
}
