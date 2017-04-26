/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:12:37 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/26 16:00:54 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"


void	ft_move_down(t_shell **shell)
{
	t_shell			*s;
	struct winsize	w;
	int				len;

	s = *shell;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	ft_del_line(shell);
	if (s->position <= (len = w.ws_col - ft_strlen(ft_find_last_pwd(ft_getenv(s->env, "PWD")) + 5)))
	{
		if ((s->position + len) <= s->pos_max)
		{
			s->line = ft_strsub(s->line, 0, ft_strlen(s->line) - len);
			s->position += len;
		}
	}
	else
	{
		if (s->position + (len = w.ws_col) <= s->pos_max)
		{
			s->line = ft_strsub(s->line, 0, ft_strlen(s->line) - len);
			s->position += len;
		}
	}
	ft_putstr(s->line);
}

void	ft_move_up(t_shell **shell)
{
	t_shell			*s;
	struct winsize	w;
	int				len;

	s = *shell;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	ft_del_line(shell);
	if ((s->position - (len = w.ws_col)) >= 0)
	{
		while (len--)
			s->line = ft_free_join(s->line, "\b", 'L');
		s->position -= w.ws_col;
	}
	ft_putstr(s->line);
}

void	ft_move_up_down(t_shell **shell, char *buf)
{
	if (buf[1] == 'P')
		ft_move_down(shell);
	if (buf[1] == 'O')
		ft_move_up(shell);
}
