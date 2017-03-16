/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 11:37:31 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/15 14:49:03 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_create_tab(char *str)
{
	char	**ta;

	if (!(ta = (char**)malloc(sizeof(char*) * (2))))
		return (0);
	ta[1] = 0;
	ta[0] = ft_strdup(str);
	return (ta);
}

char	**ft_realloc(char ***ta, char *str)
{
	char	**new;
	size_t	i;
	size_t	len;

	if (!(*ta))
		return (*ta = ft_create_tab(str));
	i = 0;
	len = ft_strlen2d(*ta) + 1;
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (0);
	new[len] = 0;
	while ((*ta)[i])
	{
		new[i] = ft_strdup((*ta)[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	ft_freetab(ta);
	return (new);
}

int		ft_exist(char ***ta, char *str)
{
	int		i;
	char	*search;

	i = 0;
	while ((*ta)[i])
	{
		search = ft_strbchr((*ta)[i], '=');
		if (ft_strcmp(str, search) == 0)
		{
			ft_strdel(&search);
			return (1);
		}
		ft_strdel(&search);
		i++;
	}
	return (0);
}

char	**ft_unalloc(char ***ta, char *str)
{
	char	**new;
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!(*ta) || ft_strlen2d(*ta) == 1)
		return (0);
	if (ft_exist(ta, str) == 0)
		return (*ta);
	j = 0;
	i = ft_strlen2d(*ta);
	if (!(new = (char**)malloc(sizeof(char*) * (i))))
		return (0);
	new[i - 1] = 0;
	i = 0;
	while ((*ta)[j])
	{
		if (ft_strcmp(str, tmp = ft_strbchr((*ta)[j], '=')) != 0)
			new[i++] = ft_strdup((*ta)[j]);
		ft_strdel(&tmp);
		j++;
	}
	ft_freetab(ta);
	return (new);
}
