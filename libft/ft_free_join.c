/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:19:37 by hmadad            #+#    #+#             */
/*   Updated: 2016/12/11 11:46:08 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char *s1, char *s2, char c)
{
	if (c == 'L')
		ft_strdel(&s1);
	if (c == 'R')
		ft_strdel(&s2);
	if (c == 'B')
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
}

char		*ft_free_join(char const *s1, char const *s2, char c)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	if (!(new = (char*)malloc(sizeof(*new) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))))
		return (0);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	ft_free((char*)s1, (char*)s2, c);
	return (new);
}
