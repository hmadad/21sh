/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:26:35 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/19 12:48:27 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_trim(char **line)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strtrim(*line);
	ft_strdel(&tmp);
}

int		ft_home_process(char **home, char *split)
{
	char	*tmp;

	tmp = *home;
	*home = ft_cdsplit(split, *home);
	ft_strdel(&tmp);
	return (1);
}

void	ft_lvlup(char ***g_env)
{
	char	*tmp;
	int		nb;

	if (!ft_getenv(*g_env, "SHLVL"))
		ft_setenv(g_env, "SHLVL=1");
	else
	{
		nb = ft_atoi(ft_getenv(*g_env, "SHLVL"));
		nb += 1;
		ft_setenv(g_env, tmp = ft_free_join("SHLVL=", ft_itoa(nb), 'R'));
		ft_strdel(&tmp);
	}
}

int		ft_cd_home(char ***g_env, char **home)
{
	if (!ft_getenv(*g_env, "HOME"))
	{
		ft_putstr("Home not set\n");
		return (0);
	}
	*home = ft_strdup(ft_getenv(*g_env, "HOME"));
	return (1);
}

int		ft_verif_home(char **opt, char **home, char ***g_env)
{
	if (opt[1][0] == '/')
		*home = ft_strdup("");
	else
	{
		if (!ft_getenv(*g_env, "PWD"))
			*home = NULL;
		else
			*home = ft_strdup(ft_getenv(*g_env, "PWD"));
	}
	return (1);
}
