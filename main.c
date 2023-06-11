/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:49 by orakib            #+#    #+#             */
/*   Updated: 2023/06/11 18:13:18 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

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
	while (1)
	{
		g_var.status = ISREADING;
		str = readline("Minishell> ");
		g_var.status = ISEXECUTING;
		main_2(str, tokens, commands, envar);
	}
	ft_delvall(envar);
}
