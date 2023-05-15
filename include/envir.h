/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:15:00 by orakib            #+#    #+#             */
/*   Updated: 2023/05/15 15:53:55 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIR_H

# define ENVIR_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	int				printed;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

t_env	**get_envar(char **env);
t_env	*ft_newvnode(char *key, char *value);
void	ft_addvback(t_env **vhead, t_env *vnode);
void	ft_delvall(t_env **vhead);
void	ft_delvone(t_env **vhead, t_env *vnode);

#endif