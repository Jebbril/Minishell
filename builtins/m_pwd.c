/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:39:45 by orakib            #+#    #+#             */
/*   Updated: 2023/06/10 18:44:05 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"
#include <sys/param.h>

int	m_pwd(t_env **envar)
{
	t_env	*pwd;

	pwd = get_envnode(envar, "PWD");
	if (!pwd)
		return (EXIT_FAILURE);
	printf("%s\n", pwd->value);
	return (EXIT_SUCCESS);
}
