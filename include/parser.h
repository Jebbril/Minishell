/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:50:24 by orakib            #+#    #+#             */
/*   Updated: 2023/05/29 17:10:16 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "lexer.h"
# include "envir.h"

typedef struct s_simple_cmd
{
	int					index;
	char				**cmd;
	t_lexer				**redirections;
	int					infd;
	int					outfd;
	struct s_simple_cmd	*prev;
	struct s_simple_cmd	*next;
}	t_simple_cmd;

t_simple_cmd	**parser(t_lexer **thead, t_env **envar, t_global *g_var);
int				pipe_errors(t_lexer *tnode);
int				rd_errors(t_lexer *tnode);
int				start_end_errors(t_lexer *tnode);
t_simple_cmd	*ft_newpnode(void);
void			ft_addpback(t_simple_cmd **head, t_simple_cmd *node);
void			ft_delpall(t_simple_cmd **phead);
int				create_pnodes(t_lexer **thead, t_simple_cmd **phead);
t_lexer			*ft_cpynode(t_lexer *tnode);
int				get_rds(t_lexer **thead, t_simple_cmd **phead);
int				get_cmd(t_lexer **thead, t_simple_cmd **phead);
int				ft_expander(t_lexer **thead, t_simple_cmd **phead,
					t_env **envar, t_global *g_var);
char			*ft_strchr(char *s, int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			expand_exitc(t_lexer *tnode, t_global *g_var, int i);

#endif