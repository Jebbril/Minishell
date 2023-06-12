/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:49 by orakib            #+#    #+#             */
/*   Updated: 2023/06/12 14:47:37 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"
#include <dirent.h>
#include <sys/param.h>

void	increment_shlvl(t_env **envar)
{
	t_env	*vnode;
	char	*str;

	vnode = get_envnode(envar, "SHLVL");
	if (vnode)
	{
		str = vnode->value;
		vnode->value = ft_itoa(ft_atoi(str) + 1);
		free(str);
	}
}

void	main_2(char *str, t_lexer **tokens, t_simple_cmd **commands,
	t_env **envar)
{
	if (!str)
	{
		write(1, "exit\n", 5);
		exit(g_var.exit_code);
	}
	if (str)
		add_history(str);
	tokens = tokenizer(str);
	commands = parser(tokens, envar);
	concatenate(tokens, commands);
	get_heredocs(commands, envar);
	cmd_execution(commands, envar);
	unlink_hd(commands);
	if (tokens)
		ft_deltall(tokens);
	if (commands)
		ft_delpall(commands);
	free(str);
}

void	min_env(t_env **envar)
{
	char	str[MAXPATHLEN];

	ft_addvback(envar, ft_newvnode(ft_substr("PWD", 0, 3),
			ft_substr(getcwd(str, MAXPATHLEN), 0, ft_strlen(str))));
	ft_addvback(envar, ft_newvnode(ft_substr("SHLVL", 0, 5), ft_itoa(1)));
	ft_addvback(envar, ft_newvnode(ft_substr("_", 0, 1),
			ft_substr("/usr/bin/env", 0, 13)));
}

int	main(int ac, char **av, char **env)
{
	t_simple_cmd	**commands;
	t_lexer			**tokens;
	t_env			**envar;
	char			*str;

	(void)ac;
	(void)av;
	commands = NULL;
	tokens = NULL;
	ft_handler();
	g_var.exit_code = 0;
	envar = get_envar(env);
	increment_shlvl(envar);
	if (!(*envar))
		min_env(envar);
	while (1)
	{
		g_var.status = ISREADING;
		str = readline("Minishell> ");
		g_var.status = ISEXECUTING;
		main_2(str, tokens, commands, envar);
	}
	ft_delvall(envar);
}
