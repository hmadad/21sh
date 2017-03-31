/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_commande.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:00:05 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/31 10:38:35 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_escape(t_shell **shell)
{
	t_shell	*s;

	s = *shell;
	ft_putstr("\n");
	ft_putstr(RED "-~[ Fermeture du Terminal ]~-\n" RESET);
	tcsetattr(0, TCSADRAIN, &(s->default_term));
	exit(0);
}

void	ft_update_history(t_shell **shell)
{
	int			fd;
	t_shell		*s;
	char		*tmp;

	s = *shell;
	tmp = ft_strtrim(s->line);
	if (tmp && ft_strcmp(tmp, "") != 0)
	{
		if ((fd = open(".history", O_WRONLY | O_APPEND)) == -1)
			ft_putstr("Cannot open file\n");
		else
		{
			ft_putendl_fd(s->line, fd);
			close(fd);
		}
		ft_liste_push_front(&(s->history), ft_listenew(s->line));
		ft_strdel(&tmp);
	}
}

void	ft_read_commande(t_shell **shell)
{
	t_shell		*s;
	char		buf[5];
	char		*cap;
	int			len;

	s = *shell;
	while (42)
	{
		len = 0;
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if (ft_strcmp(buf, "\n") == 0)
		{
			ft_update_history(&s);
			//ft_exec_commande(shell);
			ft_strdel(&(s->line));
			ft_putchar('\n');
			ft_prompt(s->env);
			ft_reset_position(shell);
		}
		else if (buf[0] == 27 && ft_strlen(buf) == 3 && buf[2] != '3')
		{
			//ft_putstr("Je suis dans les arrow\n");
			ft_history_key(shell, buf);
		}
		else if (buf[0] == 27 && ft_strlen(buf) == 1)
			ft_escape(shell);
		else if (buf[0] == 127 || (buf[0] == 27 && buf[2] == '3')) //126 = del et 127 = backspace
		{
			/*//ft_putstr("Je suis dans les touche supp\n");
			if (s->pos_max > 0)
			{
				if (buf[0] == 127)
					;
				else
				{
					if (s->pos_max != s->position)
					{
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
						s->line = ft_strdelat(s->line, s->position);
						s->pos_max -= 1;
						ft_putstr(s->line);
					}
				}
			}*/
		}
		else
		{
			//ft_putstr("Je suis dans les touche normales\n");
			if (s->line)
			{
				if (s->position == s->pos_max)
				{
					s->line = ft_free_join(s->line, buf, 'L');
					ft_putstr(buf);
				}
				else
				{
					if ((cap = tgetstr("im", NULL)) == NULL)
						ft_putstr("Cannot insere caractere\n");
					else
						tputs(cap, 0, ft_putc);
					cap = ft_straddat(s->line, buf[0], s->position);
					s->line = ft_strsub(cap, 0, ft_strlen(cap) - 1);
					ft_putstr(buf);
					if ((cap = tgetstr("ei", NULL)) == NULL)
						ft_putstr("Cannot delete insere caractere\n");
					else
						tputs(cap, 0, ft_putc);
				}
			}
			else
			{
				s->line = ft_strdup(buf);
				ft_putstr(buf);
			}
			s->pos_max += 1;
			s->position += 1;
		}
		//printf("\nposition = %d\npos_max = %d\n", s->position, s->pos_max);
	}
}
