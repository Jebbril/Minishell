/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:49 by orakib            #+#    #+#             */
/*   Updated: 2023/05/14 18:04:07 by orakib           ###   ########.fr       */
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
	envar = get_envar(env);
	// while (1)
	// {
	// 	str = readline("Minishell >");
	// 	add_history(str);
		str = "export xxx+x=test";
		tokens = tokenizer(str);
		commands = parser(tokens, envar);
		concatenate(tokens, commands);
		m_export((*commands)->cmd, envar);
		exp_print(envar);
		if (tokens)
			ft_deltall(tokens);
		if (commands)
			ft_delpall(commands);
		// free(str);
	// }
	ft_delvall(envar);
}
