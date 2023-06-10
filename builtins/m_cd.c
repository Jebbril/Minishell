/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:02:46 by orakib            #+#    #+#             */
/*   Updated: 2023/06/10 18:39:44 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"
#include <dirent.h>
#include <sys/param.h>

t_env	*get_envnode(t_env **envar, char *str)
{
	t_env	*vnode;

	vnode = *envar;
	while (vnode)
	{
		if (ft_strncmp(str, vnode->key, 4) == 0
			&& ft_strncmp(str, vnode->key, ft_strlen(vnode->key)) == 0)
			return (vnode);
		vnode = vnode->next;
	}
	return (NULL);
}

void	change_pwdvar(t_env **envar)
{
	t_env	*pwd;
	t_env	*oldpwd;
	char	*str;

	str = malloc(MAXPATHLEN + 1);
	if (!str)
	{
		perror("Minishell");
		return ;
	}
	oldpwd = get_envnode(envar, "OLDPWD");
	pwd = get_envnode(envar, "PWD");
	free(oldpwd->value);
	oldpwd->value = pwd->value;
	if (!getcwd(str, MAXPATHLEN))
	{
		free (str);
		return ;
	}
	pwd->value = str;
}

int	change_dir(char *arg, t_env **envar)
{
	t_env	*oldpwd;

	oldpwd = get_envnode(envar, "OLDPWD");
	if (strncmp(arg, "-", ft_strlen(arg)) == 0)
	{
		if (chdir(oldpwd->value) != 0)
		{
			perror("Minishell: cd");
			return (EXIT_FAILURE);
		}
		change_pwdvar(envar);
	}
	else
	{
		if (chdir(arg) != 0)
		{
			perror("Minishell: cd");
			return (EXIT_FAILURE);
		}
		change_pwdvar(envar);
	}
	return (EXIT_SUCCESS);
}

int	m_cd(char **args, t_env **envar)
{
	t_env	*vnode;

	vnode = *(envar);
	if (!args[1])
	{
		vnode = get_envnode(envar, "HOME");
		if (chdir(vnode->value) != 0)
		{
			perror("Minishell: cd");
			return (EXIT_FAILURE);
		}
		change_pwdvar(envar);
		return (EXIT_SUCCESS);
	}
	if (!args[1][0])
		return (EXIT_SUCCESS);
	if (args[1])
	{
		change_dir(args[1], envar);
	}
	return (EXIT_SUCCESS);
}
