# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 10:32:12 by orakib            #+#    #+#              #
#    Updated: 2023/06/10 15:50:11 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c lexer/ft_isspace.c lexer/lexer.c lexer/linked_list.c \
		lexer/ft_substr.c lexer/handle_quote.c lexer/handle_sep.c \
		lexer/handle_space.c lexer/handle_word.c parser/linked_list.c \
		parser/parser.c parser/syntax.c parser/create_commands.c \
		parser/get_rds.c env/get_env.c env/linked_list.c parser/expander.c\
		parser/ft_strchr.c parser/ft_isalpha.c concatenate/concatenate.c \
		concatenate/get_cmds.c builtins/m_env.c builtins/m_export.c \
		builtins/m_export_utils.c builtins/m_unset.c heredoc/ft_itoa.c \
		heredoc/heredoc.c heredoc/expand_heredoc.c builtins/m_echo.c \
		builtins/m_pwd.c builtins/m_cd.c builtins/m_exit.c parser/expand_exitc.c \
		heredoc/unlink_hd.c execution/execution.c execution/one_builtin.c \
		execution/redirections.c execution/swap_fds.c execution/exec.c \
		execution/ft_split.c execution/ft_strdup.c execution/ft_strjoin2.c \
		execution/ft_strnstr.c execution/get_path.c signals.c

HEADER = inc/minishell.h

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L/Users/$(USER)/.brew/opt/readline/lib -lreadline -o $(NAME) $(OBJ)
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I /Users/$(USER)/.brew/opt/readline/include -c $< -o $@

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re