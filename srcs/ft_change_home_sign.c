/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_home_sign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:57:23 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/17 15:07:18 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_prepare_setenv(char ***g_env, char **opt)
{
	char	*tmp;

	if (ft_strlen2d(opt) == 3)
	{
		tmp = ft_free_join(ft_strjoin(opt[1], "="), opt[2], 'L');
		ft_setenv(g_env, tmp);
		ft_strdel(&tmp);
	}
	else
		ft_putstr("setenv: 2 arguments are required\n");
}

void	ft_prepare_unsetenv(char ***g_env, char **opt)
{
	if (ft_strlen2d(opt) == 2)
	{
		ft_unsetenv(g_env, opt[1]);
	}
	else
		ft_putstr("unsetenv: 1 arguments are required\n");
}

char	*ft_change_home_sign(char *line, char *home, char c)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!home)
		return (line);
	new = ft_strnew(ft_strlen(line) + ft_strlen(home));
	if (!new)
		return (0);
	while (line[i])
	{
		if (line[i] == c && j == 0)
		{
			ft_strcpy(new + i, home);
			j = ft_strlen(home) - 1;
		}
		else
			new[i + j] = line[i];
		i++;
	}
	ft_strdel(&line);
	return (new);
}
