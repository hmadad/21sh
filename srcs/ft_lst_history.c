/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:17:49 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/15 15:15:50 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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

void		ft_liste_push_back(t_history **lst, t_history *new)
{
	t_history	*list;

	list = *lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
		new->previous = list;
		new->next = NULL;
	}
	else
		*lst = ft_listenew(new->content);
}

void		ft_liste_push_front(t_history **lst, t_history *new)
{
	t_history	*list;

	list = *lst;
	if (list)
	{
		list->previous = new;
		new->next = list;
		*lst = new;
	}
	else
		*lst = ft_listenew(new->content);
}

int			ft_putc(int c)
{
	write(1, &c, 1);
	return (1);
}
