/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:02:17 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/19 12:46:48 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_cd_lp(char **opt, char ***g_env)
{
	if (ft_strcmp(opt[1], "-P") == 0)
	{
		ft_strdel(&(opt[1]));
		opt[1] = opt[2];
		opt[2] = 0;
		ft_cd(opt, g_env, 'P');
	}
	else
	{
		ft_strdel(&(opt[1]));
		opt[1] = opt[2];
		opt[2] = 0;
		ft_cd(opt, g_env, 'L');
	}
	return (1);
}

int		ft_prepare_cd(char **opt, char ***g_env)
{
	if (ft_strlen2d(opt) > 1 && ft_strcmp(opt[1], "-") == 0)
	{
		ft_strdel(&opt[1]);
		if (!ft_getenv(*g_env, "OLDPWD"))
		{
			ft_putstr("OLDPWD not set\n");
			return (1);
		}
		opt[1] = ft_strdup(ft_getenv(*g_env, "OLDPWD"));
	}
	if (ft_strlen2d(opt) > 1 && (ft_strcmp(opt[1], "-P") == 0
			|| ft_strcmp(opt[1], "-L") == 0))
		ft_cd_lp(opt, g_env);
	else
		ft_cd(opt, g_env, 'L');
	return (1);
}
