/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:31:47 by orakib            #+#    #+#             */
/*   Updated: 2023/05/29 19:44:03 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "parser.h"
# include "concat.h"
# include "builtins.h"

char	*ft_itoa(int n);
int		get_heredocs(t_simple_cmd **cmds, t_env **envar);
void	expand_heredoc(char **input, t_env **envar);
void	unlink_hd(t_simple_cmd **cmds);

#endif