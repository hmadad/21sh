/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:52:17 by hmadad            #+#    #+#             */
/*   Updated: 2017/02/06 13:25:01 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char **g_env, char *search)
{
	int		i;
	char	*str;

	i = 0;
	if (g_env == 0 || search == 0 || ft_strcmp(search, "") == 0)
		return (0);
	while (g_env[i])
	{
		str = ft_strbchr(g_env[i], '=');
		if (ft_strcmp(str, search) == 0)
		{
			ft_strdel(&str);
			return (ft_strchr(g_env[i], '=') + 1);
		}
		ft_strdel(&str);
		i++;
	}
	return (0);
}

int		ft_setenv(char ***g_env, char *str)
{
	int		i;
	char	*search;
	char	*tmp;

	i = 0;
	while ((*g_env)[i])
	{
		search = ft_strbchr((*g_env)[i], '=');
		tmp = ft_strbchr(str, '=');
		if (ft_strcmp(tmp, search) == 0)
		{
			ft_strdel(&search);
			ft_strdel(&tmp);
			ft_strdel(&(*g_env)[i]);
			(*g_env)[i] = ft_strdup(str);
			return (1);
		}
		ft_strdel(&search);
		ft_strdel(&tmp);
		i++;
	}
	*g_env = ft_realloc(g_env, str);
	return (0);
}

int		ft_unsetenv(char ***g_env, char *str)
{
	*g_env = ft_unalloc(g_env, str);
	return (0);
}
