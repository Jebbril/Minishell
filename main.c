/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:49 by orakib            #+#    #+#             */
/*   Updated: 2023/06/09 17:37:20 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_simple_cmd	**commands;
	t_lexer			**tokens;
	t_env			**envar;
	char			*str;

	(void)ac;
	(void)av;
	ft_handler();
	g_var.exit_code = 0;
	envar = get_envar(env);
	while (1)
	{
		g_var.status = ISREADING;
		str = readline("Minishell> ");
		g_var.status = ISEXECUTING;
		if (!str)
			exit(g_var.exit_code);
		if (*str)
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
	ft_delvall(envar);
}
