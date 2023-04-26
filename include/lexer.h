/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:53:35 by orakib            #+#    #+#             */
/*   Updated: 2023/04/26 17:46:41 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H

# include <stdlib.h>
# include <stdio.h>

typedef enum s_tokens
{
	word,
	dbq_word,
	sq_word,
	w_space,
	pipe,
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

t_lexer	**tokenizer(char *input);
t_lexer	*ft_newtnode(char *str, t_tokens token);
void	ft_addtback(t_lexer **head, t_lexer *node);
t_lexer	*ft_lasttnode(t_lexer **thead);
void	ft_deltall(t_lexer **thead);
int		ft_isspace(char c);
int		handle_space(char *input, int *i, t_lexer **thead);
int		handle_sep(char *input, int *i, t_lexer **thead);
int		handle_quote(char *input, int *i, t_lexer **thead);
int		handle_dbquote(char *input, int *i, t_lexer **thead);
int		handle_squote(char *input, int *i, t_lexer **thead);
int		handle_word(char *input, int *i, t_lexer **thead);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif