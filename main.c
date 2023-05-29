/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:49 by orakib            #+#    #+#             */
/*   Updated: 2023/05/29 20:15:03 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_global	g_var;

int	main(int ac, char **av, char **env)
{
	t_simple_cmd	**commands;
	t_lexer			**tokens;
	t_env			**envar;
	char			*str;

	(void)ac;
	(void)av;
	g_var.exit_code = 0;
	envar = get_envar(env);
	while (1)
	{
		str = readline("Minishell >");
		add_history(str);
		// str = "$?";
		tokens = tokenizer(str);
		commands = parser(tokens, envar, &g_var);
		concatenate(tokens, commands);
		get_heredocs(commands, envar);
		unlink_hd(commands);
		if (tokens)
			ft_deltall(tokens);
		if (commands)
			ft_delpall(commands);
		free(str);
		// system("leaks a.out");
	}
	ft_delvall(envar);
}
