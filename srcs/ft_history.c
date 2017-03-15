/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:14:15 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/15 14:25:59 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_up_arrow(t_history **history)
{
	t_history	*h;
	char		*line;

	h = *history;
	if ((line = tgetstr("rc", NULL)) == NULL)
		ft_putstr("Cannot restor the cursor position\n");
	else
		tputs(line, 0, ft_putc);
	if ((line = tgetstr("cd", NULL)) == NULL)
		ft_putstr("Cannot delete line blow the cursor position\n");
	else
		tputs(line, 0, ft_putc);
	ft_putstr("?>");
	ft_putstr(h->content);
	if (h->next)
		h = h->next;
}

void	ft_down_arrow(t_history **history)
{

}

void	ft_history_key(t_history **history, char *buf)
{
	if (*history)
	{
		if (buf[2] == 'A')
			ft_up_arrow(history);
		if (buf[2] == 'B')
			ft_down_arrow(history);
	}
}
