/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:53:35 by orakib            #+#    #+#             */
/*   Updated: 2023/06/08 19:28:35 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef enum s_tokens
{
	word,
	dbq_word,
	sq_word,
	w_space,
	is_pipe,
	rd_input,
	rd_output,
	here_doc,
	rd_output_apnd,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				index;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_global
{
	int	exit_code;
}	t_global;

t_global	g_var;

int		ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
t_lexer	**tokenizer(char *input);
t_lexer	*ft_newtnode(char *str, t_tokens token);
void	ft_addtback(t_lexer **head, t_lexer *node);
t_lexer	*ft_lasttnode(t_lexer **thead);
void	ft_deltall(t_lexer **thead);
void	ft_deltone(t_lexer **thead, t_lexer *tnode);
int		ft_isspace(char c);
int		handle_space(char *input, int *i, t_lexer **thead);
int		handle_sep(char *input, int *i, t_lexer **thead);
int		handle_quote(char *input, int *i, t_lexer **thead);
int		handle_dbquote(char *input, int *i, t_lexer **thead);
int		handle_squote(char *input, int *i, t_lexer **thead);
int		handle_word(char *input, int *i, t_lexer **thead);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);

#endif