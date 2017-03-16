/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:14:15 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/16 13:48:22 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_up_arrow(t_history **history)
{
	t_history	*h;
	char		*cap;
	int			len;

	h = *history;
	if ((cap = tgetstr("rc", NULL)) == NULL)
		ft_putstr("Cannot restor the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	if ((cap = tgetstr("cd", NULL)) == NULL)
		ft_putstr("Cannot delete line blow the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	ft_putstr(h->content);
	len = ft_strlen(h->content);
	if (h->next)
		*history = h->next;
	return (len);
}

int		ft_down_arrow(t_history **history)
{
	t_history	*h;
	char		*cap;
	int			len;

	h = *history;
	if ((cap = tgetstr("rc", NULL)) == NULL)
		ft_putstr("Cannot restor the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	if ((cap = tgetstr("cd", NULL)) == NULL)
		ft_putstr("Cannot delete line blow the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	ft_putstr(h->content);
	len = ft_strlen(h->content);
	if (h->previous)
		*history = h->previous;
	return (len);
}


void	ft_right_arrow(t_shell **shell)
{
	char	*cap;
	t_shell	*s;

	s = *shell;
	if ((cap = tgetstr("nd", NULL)) == NULL)
		ft_putstr("Cannot move the cursor to the left\n");
	else
		tputs(cap, 0, ft_putc);
	s->position += 1;
}

void	ft_left_arrow(t_shell **shell)
{
	char	*cap;
	t_shell	*s;

	s = *shell;
	if ((cap = tgetstr("le", NULL)) == NULL)
		ft_putstr("Cannot move the cursor to the right\n");
	else
		tputs(cap, 0, ft_putc);
	s->position -= 1;
}

void	ft_history_key(t_shell **shell, char *buf)
{
	t_shell	*s;

	s = *shell;
	if (s->history)
	{
		if (buf[2] == 'A')
		{
			s->pos_max = ft_up_arrow(&(s->history));
			s->position = s->pos_max;
		}
		if (buf[2] == 'B')
		{
			s->pos_max = ft_down_arrow(&(s->history));
			s->position = s->pos_max;
		}
	}
	if (buf[2] == 'C' && s->position < s->pos_max && s->position >= 0)
		ft_right_arrow(shell);
	if (buf[2] == 'D' && s->position <= s->pos_max && s->position > 0)
		ft_left_arrow(shell);
}
