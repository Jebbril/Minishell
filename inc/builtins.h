/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:05:09 by orakib            #+#    #+#             */
/*   Updated: 2023/06/11 17:42:08 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H

# define BUILTINS_H

# include "minishell.h"

int		m_env(t_env **envar);
int		m_export(char **args, t_env **envar);
int		exp_k(char *arg, t_env **envar);
int		exp_knv(char *arg, t_env **envar);
void	exp_print(t_env **envar);
int		m_unset(char **args, t_env **envar);
int		m_echo(char **args);
int		m_pwd(t_env **envar);
int		m_cd(char **args, t_env **envar);
int		m_exit(char **args);
t_env	*get_envnode(t_env **envar, char *str);
int		ft_atoi(const char *str);
int		exp_knv2(char *arg, t_env **envar);

#endif