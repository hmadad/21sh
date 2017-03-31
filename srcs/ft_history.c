/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:14:15 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/29 16:16:40 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_up_arrow(t_shell **shell)
{
	t_history	*h;
	t_shell		*s;
	char		*cap;

	s = *shell;
	h = s->history;
	s->pos_max -= (s->pos_max - s->position);
	while (s->pos_max)
	{
		if ((cap = tgetstr("le", NULL)) == NULL)
			ft_putstr("Cannot move the cursor to the right\n");
		else
			tputs(cap, 0, ft_putc);
		s->pos_max--;
	}
	if ((cap = tgetstr("cd", NULL)) == NULL)
		ft_putstr("Cannot delete line blow the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	s->line = ft_strdup(h->content);
	ft_putstr(h->content);
	if (h->next)
		s->history = h->next;
	return (ft_strlen(h->content));
}

int		ft_down_arrow(t_shell **shell)
{
	t_history	*h;
	t_shell		*s;
	char		*cap;

	s = *shell;
	h = s->history;
	s->pos_max -= (s->pos_max - s->position);
	while (s->pos_max)
	{
		if ((cap = tgetstr("le", NULL)) == NULL)
			ft_putstr("Cannot move the cursor to the right\n");
		else
			tputs(cap, 0, ft_putc);
		s->pos_max--;
	}
	if ((cap = tgetstr("cd", NULL)) == NULL)
		ft_putstr("Cannot delete line blow the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	s->line = ft_strdup(h->content);
	ft_putstr(h->content);
	if (h->previous)
		s->history = h->previous;
	return (ft_strlen(h->content));
}


void	ft_right_arrow(t_shell **shell)
{
	t_shell	*s;
	char	*cap;
	int		len;

	s = *shell;
	len = s->pos_max - (s->pos_max - s->position);
	while (len)
	{
		if ((cap = tgetstr("le", NULL)) == NULL)
			ft_putstr("Cannot move the cursor to the right\n");
		else
			tputs(cap, 0, ft_putc);
		len--;
	}
	if ((cap = tgetstr("cd", NULL)) == NULL)
		ft_putstr("Cannot delete line blow the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	s->line = ft_strsub(s->line, 0, ft_strlen(s->line) - 1);
	ft_putstr(s->line);
	s->position += 1;
}

void	ft_left_arrow(t_shell **shell)
{
	t_shell	*s;
	char	*cap;
	int		len;

	s = *shell;
	len = s->pos_max - (s->pos_max - s->position);
	while (len)
	{
		if ((cap = tgetstr("le", NULL)) == NULL)
			ft_putstr("Cannot move the cursor to the right\n");
		else
			tputs(cap, 0, ft_putc);
		len--;
	}
	if ((cap = tgetstr("cd", NULL)) == NULL)
		ft_putstr("Cannot delete line blow the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	s->line = ft_free_join(s->line, "\b", 'L');
	ft_putstr(s->line);
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
			s->pos_max = ft_up_arrow(shell);
			s->position = s->pos_max;
		}
		if (buf[2] == 'B')
		{
			s->pos_max = ft_down_arrow(shell);
			s->position = s->pos_max;
		}
	}
	if (buf[2] == 'C' && s->position < s->pos_max && s->position >= 0)
		ft_right_arrow(shell);
	if (buf[2] == 'D' && s->position <= s->pos_max && s->position > 0)
		ft_left_arrow(shell);
}
