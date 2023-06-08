/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:22:50 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/07 14:16:52 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	main(int ac, char **av, char **env)
// {
// 	//pid_t	pid;
// 	int		fd[2];
// 	int		fdin;
// 	int 	fdout;
// 	int 	var;
// 	int		i;

// 	i = 2;
// 	fdin = 0;
// 	fdout = 1;
// 	if (!env)
// 		return (1);
// 	while(i < ac - 1)
// 	{
// 		pipe (fd);
// 		var = fd[0];
// 		fdout = fd[1];
// 		if (i == ac - 2)
// 			fdout = 1;
// 		ch_process(av[i], env, fdin, fdout, var);
// 		p_process(av, env, fdin, fdout);
// 		fdin = fd[0];
// 		i++;
// 	}
// 	while(wait(NULL) != -1);
// 	return (0);
// }