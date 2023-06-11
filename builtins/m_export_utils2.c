/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_export_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:32:33 by orakib            #+#    #+#             */
/*   Updated: 2023/06/11 18:10:06 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"

char	*ft_strjoin3(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1)
		s1 = "";
	if (!s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	append_value2(char *key, char *value, int i, t_env **envar)
{
	if (i == 0)
		ft_addvback(envar, ft_newvnode(key, value));
	if (i == 1)
	{
		free(key);
		free(value);
	}
}

int	append_value(char *key, char *value, t_env **envar)
{
	int		i;
	char	*tmp;
	t_env	*vnode;

	i = 0;
	vnode = *envar;
	while (vnode)
	{
		if (ft_strncmp(key, vnode->key, ft_strlen(vnode->key)) == 0
			&& ft_strncmp(key, vnode->key, ft_strlen(key)) == 0)
		{
			tmp = vnode->value;
			vnode->value = ft_strjoin3(vnode->value, value);
			free(tmp);
			i = 1;
			break ;
		}
		vnode = vnode->next;
	}
	append_value2(key, value, i, envar);
	return (0);
}

int	exp_knv2(char *arg, t_env **envar)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (i > 0 && arg[i - 1] == '+')
		i--;
	key = ft_substr(arg, 0, i);
	j = i;
	while (arg[j])
		j++;
	value = ft_substr(arg, i + 2, j - i);
	i = -1;
	if (key[i + 1] != '_' && !ft_isalpha(key[i + 1]))
		return (free(key), free(value)
			, write(2, "not a valid identifier\n", 24), EXIT_FAILURE);
	while (key[++i])
		if (key[i] != '_' && !ft_isalnum(key[i]))
			return (free(key), free(value)
				, write(2, "not a valid identifier\n", 24), EXIT_FAILURE);
	append_value(key, value, envar);
	return (EXIT_SUCCESS);
}
