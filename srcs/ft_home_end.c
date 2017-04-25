/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:34:04 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/25 13:36:35 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_move_to_home(t_shell **shell)
{
	t_shell *s;
	int		len;

	s = *shell;
	ft_del_line(shell);
	len = s->pos_max - (s->pos_max - s->position);
	while (len)
	{
		s->line = ft_free_join(s->line, "\b", 'L');
		len--;
	}
	ft_putstr(s->line);
	s->position = 0;
}

void	ft_move_to_end(t_shell **shell)
{
	t_shell *s;

	s = *shell;
	ft_del_line(shell);
	s->line = ft_strtrimb(s->line);
	ft_putstr(s->line);
	s->position = s->pos_max;
}

void	ft_home_end(t_shell **shell, char *buf)
{
	t_shell	*s;

	s = *shell;
	if (s->line && buf[2] == 'F')
		ft_move_to_end(shell);
	else if (s->line && buf[2] == 'H')
		ft_move_to_home(shell);
}
