/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:41:22 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/12 14:05:13 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	ft_ex(char **env, t_simple_cmd *command)
{
	char	**path;
	char	*path_com;
	int		i;

	i = -1;
	path = ft_split(find_path(env), ':');
	if (!path)
		(exit(EXIT_FAILURE));
	path_com = get_path_env(command->cmd[0], path);
	while (path[++i])
		free(path[i]);
	free (path);
	i = -1;
	if (execve(path_com, command->cmd, env) == -1)
	{
		if (path_com)
			free(path_com);
		ft_error(path_com, command);
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
