/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:25:21 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/31 12:43:48 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_termcap_backspace(t_shell **shell)
{
	int		len;
	t_shell	*s;

	s = *shell;
	if (s->position != 0)
	{
		len = s->pos_max - (s->pos_max - s->position);
		while (len)
		{
			tputs(tgetstr("le", NULL), 0, ft_putc);
			len--;
		}
		tputs(tgetstr("cd", NULL), 0, ft_putc);
		s->line = ft_strdelat(s->line, s->position - 1);
		s->pos_max -= 1;
		s->position -= 1;
		ft_putstr(s->line);
	}
}

static void	ft_termcap_delete(t_shell **shell)
{
	int		len;
	char	*tmp;
	t_shell	*s;

	s = *shell;
	if (s->pos_max != s->position)
	{
		len = s->pos_max - (s->pos_max - s->position);
		while (len)
		{
			tputs(tgetstr("le", NULL), 0, ft_putc);
			len--;
		}
		tputs(tgetstr("cd", NULL), 0, ft_putc);
		tmp = ft_strdelat(s->line, s->position);
		s->line = ft_strsub(tmp, 0, ft_strlen(tmp) - 1);
		s->pos_max -= 1;
		ft_putstr(s->line);
	}

}

void	ft_delete_char(t_shell **shell, char *buf)
{
	t_shell	*s;

	s = *shell;
	if (s->pos_max > 0)
	{
		if (buf[0] == 127)
			ft_termcap_backspace(shell);
		else
			ft_termcap_delete(shell);
	}
}
