/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:13:33 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/14 15:15:08 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_history	*ft_listenew(char *content)
{
	t_history	*new;

	if (!(new = (t_history *)malloc(sizeof(*new))))
		return (0);
	if (content == NULL)
		new->content = "";
	else
		new->content = ft_strdup(content);
	new->previous = NULL;
	new->next = NULL;
	return (new);
}
