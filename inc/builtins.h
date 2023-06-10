/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:05:09 by orakib            #+#    #+#             */
/*   Updated: 2023/06/06 18:58:17 by orakib           ###   ########.fr       */
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
int		m_pwd(void);
int		m_cd(char **args, t_env **envar);
int		m_exit(char **args);

#endif