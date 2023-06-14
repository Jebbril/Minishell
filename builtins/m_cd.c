/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:09:51 by orakib            #+#    #+#             */
/*   Updated: 2023/06/14 21:36:16 by orakib           ###   ########.fr       */
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
		if (vnode)
		{
			if (ft_strncmp(str, vnode->key, 4) == 0
				&& ft_strncmp(str, vnode->key, ft_strlen(vnode->key)) == 0)
				return (vnode);
		}
		vnode = vnode->next;
	}
	return (NULL);
}

int	specific_ch(char *str, t_env **envar)
{
	t_env	*vnode;

	vnode = get_envnode(envar, str);
	if (!vnode || !vnode->value)
	{
		ft_putendl_fd(str, 2);
		ft_putendl_fd(" is not set\n", 2);
		return (1);
	}
	if (chdir(vnode->value) != 0)
	{
		perror("");
		return (1);
	}
	if (ft_strncmp(str, "OLDPWD", 7) == 0)
	{
		ft_putendl_fd(vnode->value, 1);
		ft_putendl_fd("\n", 1);
	}
	return (0);
}

int	change_dir(char *arg, t_env **envar)
{
	(void)envar;
	if (chdir(arg) != 0)
	{
		perror("");
		return (1);
	}
	return (0);
}

void	update_vars(t_env **envar)
{
	t_env	*pwd;
	t_env	*oldpwd;

	ft_delvone(envar, get_envnode(envar, "OLDPWD"));
	pwd = get_envnode(envar, "PWD");
	oldpwd = ft_newvnode(ft_strdup("OLDPWD"), NULL);
	ft_addvback(envar, oldpwd);
	if (!pwd)
		oldpwd->value = ft_strdup("");
	else
	{
		oldpwd->value = pwd->value;
		pwd->value = getcwd(NULL, 0);
	}
}

int	m_cd(char **args, t_env **envar)
{
	int	ret;

	ret = 0;
	if (!args[1])
		ret = specific_ch("HOME", envar);
	else if (!args[1][0])
		;
	else if (ft_strncmp(args[1], "-", 1) == 0)
		ret = specific_ch("OLDPWD", envar);
	else
		ret = change_dir(args[1], envar);
	if (ret == 0)
		update_vars(envar);
	return (ret);
}
