/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:52:17 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/15 14:42:11 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_getenv(char **env, char *search)
{
	int		i;
	char	*str;

	i = 0;
	if (env == 0 || search == 0 || ft_strcmp(search, "") == 0)
		return (0);
	while (env[i])
	{
		str = ft_strbchr(env[i], '=');
		if (ft_strcmp(str, search) == 0)
		{
			ft_strdel(&str);
			return (ft_strchr(env[i], '=') + 1);
		}
		ft_strdel(&str);
		i++;
	}
	return (0);
}

int		ft_setenv(char ***env, char *str)
{
	int		i;
	char	*search;
	char	*tmp;

	i = 0;
	while ((*env)[i])
	{
		search = ft_strbchr((*env)[i], '=');
		tmp = ft_strbchr(str, '=');
		if (ft_strcmp(tmp, search) == 0)
		{
			ft_strdel(&search);
			ft_strdel(&tmp);
			ft_strdel(&(*env)[i]);
			(*env)[i] = ft_strdup(str);
			return (1);
		}
		ft_strdel(&search);
		ft_strdel(&tmp);
		i++;
	}
	*env = ft_realloc(env, str);
	return (0);
}

int		ft_unsetenv(char ***env, char *str)
{
	*env = ft_unalloc(env, str);
	return (0);
}
