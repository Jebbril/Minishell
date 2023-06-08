/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:31:47 by orakib            #+#    #+#             */
/*   Updated: 2023/06/08 17:02:10 by edraidry         ###   ########.fr       */
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
# include <sys/wait.h>
# include "parser.h"
# include "concat.h"
# include "builtins.h" 

char	*ft_itoa(int n);
int		get_heredocs(t_simple_cmd **cmds, t_env **envar);
void	expand_heredoc(char **input, t_env **envar);
void	unlink_hd(t_simple_cmd **cmds);
void	cmd_execution(t_simple_cmd **cmds, t_env **envar);
int		check_builtin(char *arg);
void	exec_onebuiltin(t_simple_cmd *command, t_env **envar);
int		get_redirection(t_simple_cmd *command);
int		swap_fds(t_simple_cmd *command);
int		swap_fds_back(t_simple_cmd *command);
char	**ft_split(char const *s, char c);//
char	*ft_strdup(const char *src);//
char	*ft_strnstr(const char *s1, const char *chr, size_t k);
void	ft_ex(char *av, char **env);
char	*find_path(char **env);
char	*get_path_env(char *cmd, char **env);
void	ft_error(char *str);
void	ch_process(t_simple_cmd *command, char *av, char **env,
			int fdin, int fdout, int var);
void	p_process(char *av, char **env, int fdin, int fdout);
void	close_fun(int fd);
int		get_input(t_simple_cmd *command, t_lexer **tnode);
int		get_output(t_simple_cmd *command, t_lexer **tnode);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strnstr( const char *s1, const char *chr, size_t k);

#endif