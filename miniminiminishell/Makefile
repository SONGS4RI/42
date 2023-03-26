# compile options
NAME		= miniminiminishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror #-g3 -fsanitize=address
RM			= rm -f
LIBFT		= -Llibft -lft
LDFLAGS		= -lreadline -L/Users/jikoo/.brew/opt/readline/lib
CPPFLAGS	= -I/Users/jikoo/.brew/opt/readline/include

# source files
MS_DIR		= srcs/
MS_SRCS		= main.c token.c lexcial_analysis.c handle_quotes.c \
			  handle_environment_variables.c utils.c
MS_PATH		= $(addprefix $(MS_DIR), $(MS_SRCS))
MS_OBJS		= $(MS_PATH:c=o)

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(MS_OBJS)
	@make -sC libft all
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFT) $^ -o $(NAME)
	@echo "╔═══════════════════════════════════════════════╗"
	@echo "║                                               ║"
	@echo "║               miniminiminishell               ║"
	@echo "║               compile finished.               ║"
	@echo "║                                               ║"
	@echo "╚═══════════════════════════════════════════════╝"

clean:
	@make -C libft clean
	@$(RM) $(MS_OBJS)
	@echo "╔═══════════════════════════════════════════════╗"
	@echo "║              make clean finished.             ║"
	@echo "╚═══════════════════════════════════════════════╝"

fclean:
	@make -C libft fclean
	@make clean
	@$(RM) $(NAME)
	@echo "╔═══════════════════════════════════════════════╗"
	@echo "║             make fclean finished.             ║"
	@echo "╚═══════════════════════════════════════════════╝"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re