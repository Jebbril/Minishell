/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:41:22 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/08 16:41:46 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_path_env(char *cmd, char **path_file)
{
	char	*path;

	if (!path_file || !cmd)
		return (NULL);
	if (ft_strnstr(cmd, "./", 2))
		return (ft_strdup(cmd + 2));
	if (access(cmd, F_OK) == 0 && ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	if (!cmd[0])
		write(1, "erron commond not found", 24);
	else if (access(cmd, F_OK) != 0 && ft_strchr(cmd, '/'))
		return (NULL);
	while (*path_file)
	{
		path = ft_strjoin(*path_file, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		path_file++;
	}
	return (NULL);
}

void	ft_ex(char *av, char **env)
{
	char	**cmd;
	char	**path;
	char	*path_com;
	int		i;

	i = -1;
	path = ft_split(find_path(env), ':');
	if (!path)
		(exit(EXIT_FAILURE));
	cmd = ft_split (av, ' ');
	path_com = get_path_env(cmd[0], path);
	while (path[++i])
		free(path[i]);
	free (path);
	i = -1;
	if (execve(path_com, cmd, env) == -1)
	{
		if (path_com)
			free(path_com);
		while (cmd[++i])
			free(cmd[i]);
		free (cmd);
		ft_error("execution");
	}
}

char	*find_path(char **env)
{
	while (*env && ft_strncmp("PATH=", *env, 5))
		env++;
	if (!(*env))
		return (NULL);
	return (*env + 5);
}
