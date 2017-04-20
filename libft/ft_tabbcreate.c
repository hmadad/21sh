/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabbcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:30:41 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/14 14:28:38 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_tabbcreate(char **content)
{
	char	***new;
	int		i;

	i = 0;
	if (!(new = (char ***)malloc(sizeof(char **) * 2)))
		return (NULL);
	new[i] = ft_tabdup(content);
	new[++i] = NULL;
	return (new);
}
