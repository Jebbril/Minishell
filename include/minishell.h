/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:31:47 by orakib            #+#    #+#             */
/*   Updated: 2023/06/02 15:32:13 by orakib           ###   ########.fr       */
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
void	cmd_execution(t_simple_cmd **cmds, t_env **envar, t_global *g_var);
int		check_builtin(char *arg);
void	exec_onebuiltin(t_simple_cmd *command, t_env **envar, t_global *g_var);
int		get_redirection(t_simple_cmd *command);
int		swap_fds(t_simple_cmd *command);
int		swap_fds_back(t_simple_cmd *command);

#endif