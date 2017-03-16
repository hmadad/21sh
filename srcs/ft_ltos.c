/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:45:21 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/16 14:06:41 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_ltos(t_list **commande)
{
	t_list	*c;
	t_list	*del;
	char	*str;

	if (!(*commande))
		return (0);
	c = *commande;
	str = ft_strdup("");
	while (c)
	{
		del = c;
		str = ft_free_join(str, c->content, 'B');
		c = c->next;
		free(del);
	}
	return (str);
}
