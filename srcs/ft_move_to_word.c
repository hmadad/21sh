/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:13:38 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/25 12:33:56 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_del_line(t_shell **shell)
{
	int		len;
	char	*cap;
	t_shell	*s;

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
}


void	ft_move_to_word_l(t_shell **shell)
{
	t_shell	*s;
	int		i;
	int		j;

	s = *shell;
	i = s->position - 1;
	j = 0;
	ft_del_line(shell);
	while ((s->line)[i] == ' ' || (s->line)[i] == '\t')
	{
		i--;
		j++;
	}
	while (i >= 0 && (s->line)[i] != ' ' && (s->line)[i] != '\t')
	{
		j++;
		i--;
	}
	while (j--)
		s->line = ft_free_join(s->line, "\b", 'L');
	s->position = i + 1;
	ft_putstr(s->line);
}

void	ft_move_to_word_r(t_shell **shell)
{
	t_shell	*s;
	int		i;
	int		j;

	s = *shell;
	i = s->position;
	j = 0;
	ft_del_line(shell);
	while ((s->line)[i] && (s->line)[i] != ' ' && (s->line)[i] != '\t' && (s->line)[i] != '\b')
	{
		j++;
		i++;
	}
	while ((s->line)[i] && ((s->line)[i] == ' ' || (s->line)[i] == '\t'))
	{
		i++;
		j++;
	}
	while (j--)
		s->line = ft_strsub(s->line, 0, ft_strlen(s->line) - 1);
	s->position = i;
	ft_putstr(s->line);
}

void	ft_move_to_word(t_shell **shell, char *buf)
{
	t_shell	*s;

	s = *shell;
	if (!(s->line))
		return ;
	if (buf[0] == 27 && buf[2] == '6' && s->position > 0)
		ft_move_to_word_l(shell);
	else if (buf[0] == 27 && buf[2] == '5' && s->position + 1 != s->pos_max)
		ft_move_to_word_r(shell);
}
