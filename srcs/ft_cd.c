/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:39:31 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/19 12:56:26 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_delpath(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (s[i] != '/')
	{
		if (s[i] != '\0')
			s[i] = '\0';
		i--;
	}
	if (s[i] == '/' && ft_strlen(s) > 1)
		s[i] = '\0';
	return (s);
}

int		ft_home(char *home, char ***g_env, char c)
{
	char	*tmp;

	if (home)
	{
		if (c == 'P')
		{
			chdir(home);
			ft_strdel(&home);
			home = get_pwd();
			chdir(home);
		}
		else
			chdir(home);
		if (!ft_getenv(*g_env, "PWD"))
			ft_setenv(g_env, tmp = ft_strjoin("OLDPWD=", ""));
		else
			ft_setenv(g_env, tmp = ft_strjoin("OLDPWD=",
						ft_getenv(*g_env, "PWD")));
		ft_strdel(&tmp);
		ft_setenv(g_env, tmp = ft_strjoin("PWD=", home));
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

int		ft_finish(char *home, char **split, char ***g_env, char c)
{
	ft_home(home, g_env, c);
	if (split)
		ft_freetab(&split);
	if (home)
		ft_strdel(&home);
	return (1);
}

int		ft_cd(char **opt, char ***g_env, char c)
{
	char	**split;
	int		i;
	char	*home;

	i = 0;
	split = NULL;
	if (ft_strlen2d(opt) == 1)
	{
		if (ft_cd_home(g_env, &home) == 0)
			return (0);
	}
	else
	{
		ft_verif_home(opt, &home, g_env);
		split = ft_strsplit(opt[1], '/');
		while (split[i] && (home))
			ft_home_process(&home, split[i++]);
	}
	if (home && ft_strcmp(home, "") == 0)
	{
		ft_strdel(&home);
		home = ft_strdup("/");
	}
	ft_finish(home, split, g_env, c);
	return (1);
}

char	*ft_cdsplit(char *split, char *home)
{
	char	*newpath;

	newpath = ft_free_join(ft_strjoin(home, "/"), split, 'L');
	if (!ft_strcmp(split, ".."))
		home = ft_delpath(home);
	else if (!chdir(newpath))
	{
		if ((ft_strcmp(split, ".") != 0))
			return (newpath);
	}
	else
	{
		ft_cd_errors(newpath, &home);
		ft_strdel(&newpath);
		return (0);
	}
	ft_strdel(&newpath);
	return (ft_strdup(home));
}
