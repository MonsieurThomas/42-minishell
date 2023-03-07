NAME		=	minishell

HEADER		=	./includes/

LIBFT		=	libft/libft.a

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra #-fsanitize=address -g

SRCS		=	sources/main.c \
				sources/env.c \
				sources/lexer/lexer.c \
				sources/lexer/lexer_special_char.c \
				sources/lexer/lexer_count.c \
				sources/lexer/lexer_count_quotes.c \
				sources/lexer/lexer_dollar.c \
				sources/lexer/lexer_dollar_variable.c \
				sources/lexer/lexer_guill.c \
				sources/builtin/echo.c \
				sources/builtin/env.c \
				sources/builtin/cd.c \
				sources/builtin/exit.c \
				sources/builtin/export.c \
				sources/builtin/export_tab.c \
				sources/builtin/export_extra.c \
				sources/builtin/export_main.c \
				sources/builtin/pwd.c \
				sources/builtin/unset.c \
				sources/exec/exec_main.c \
				sources/exec/exec_special_char.c \
				sources/exec/signals.c \
				sources/exec/free.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline -L${HOME}/.brew/opt/readline/lib -I${HOME}/.brew/opt/readline/include

$(LIBFT)	:
				make -C ./libft

clean		:
				rm -rf $(OBJS)
				#make clean -C ./libft

fclean		:	clean
				rm $(NAME)
				#make fclean -C ./libft

re			:	fclean all

.PHONY		: all clean fclean re
