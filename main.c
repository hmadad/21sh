/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 09:00:16 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/14 14:30:34 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <termcap.h>
#include <term.h>
#include <stdio.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

typedef struct	s_liste
{
	char			*content;
	struct s_liste	*previous;
	struct s_liste	*next;
}				t_liste;

t_liste	*ft_listenew(char *content)
{
	t_liste			*new;

	if (!(new = (t_liste *)malloc(sizeof(*new))))
		return (0);
	if (content == NULL)
		new->content = "";
	else
		new->content = ft_strdup(content);
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	ft_liste_push_back(t_liste **lst, t_liste *new)
{
	t_liste	*list;
	t_list	*prev;

	list = *lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
		new->previous = list;
	}
	else
		*lst = ft_listenew(new->content);
}

void	ft_liste_push_front(t_liste **lst, t_liste *new)
{
	t_liste	*list;

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

int		ft_putc(int c)
{
	write(1, &c, 1);
	return (1);
}

int		main(void)
{
	int				getent;
	char			*name;
	struct termios	term;
	struct termios	term2;
	t_list			*chaine = NULL;
	char			buf[4];
	char			*string;
	int				fd;
	t_liste			*history;
	char			*line;
	int				signal;

	signal = 0;
	name = getenv("TERM");
	if (name == 0)
		ft_putstr("TERM is undefined in env\n");
	else
	{
		getent = tgetent(0, name);
		if (getent == 0)
		{
			ft_putstr(name);
			ft_putstr(" not found in the termcap DB\n");
		}
		if (getent == -1)
			ft_putstr("Could not access to the termcap DB\n");
		if (getent > 0)
		{
			ft_putstr(name);
			ft_putstr(" Successfully found in termcap DB\n");
			if (tcgetattr(0, &term) == -1)
				ft_putstr("Error cannot fill up the struct\n");
			else
			{
				term2 = term;
				term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
				term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
				term.c_cc[VMIN] = 1;
				term.c_cc[VTIME] = 0;
				// On applique les changements :
				if (tcsetattr(0, TCSADRAIN, &term) == -1)
					ft_putstr("Cannot apply the change on the termios struct\n");
				else
				{
					if ((fd = open(".history", O_RDONLY)) == -1)
						ft_putstr("Cannot open history file\n");
					else
					{
						while (get_next_line(fd, &line) != 0)
						{
							ft_liste_push_front(&history, ft_listenew(line));
							line = NULL;
						}
						close(fd);
					}
					if ((line = tgetstr("cl", NULL)) == NULL)
						ft_putstr("bug cl\n");
					else
						tputs(line, 0, ft_putc);
					ft_putstr("?>");
					if ((line = tgetstr("sc", NULL)) == NULL)
						ft_putstr("bug save cursor position\n");
					else
						tputs(line, 0, ft_putc);
					while (42)
					{
						ft_bzero(buf, 2);
						read(0, buf, 3);
						if (ft_strcmp(buf, "\n") == 0)
						{
							ft_lst_push_back(&chaine, ft_lstnew("\n", 2));
							string = ft_strdup("");
							while (chaine)
							{
								string = ft_strjoin(string, chaine->content);
								chaine = chaine->next;
							}
							if (ft_strcmp(ft_strtrim(string), "") != 0)
							{
								if ((fd = open(".history", O_WRONLY | O_APPEND)) == -1)
									ft_putstr("Cannot open file\n");
								else
								{
									ft_putstr_fd(string, fd);
									close(fd);
								}
								chaine = NULL;
								ft_putchar('\n');
								ft_putstr("?>");
								if ((line = tgetstr("sc", NULL)) == NULL)
									ft_putstr("bug save cursor position\n");
								else
									tputs(line, 0, ft_putc);
								ft_liste_push_front(&history, ft_listenew(string));
							}
						}
						else if (buf[0] == 27 && ft_strlen(buf) == 3)
						{
							if (history)
							{
								if (buf[2] == 'A')
								{
									if ((line = tgetstr("rc", NULL)) == NULL)
										ft_putstr("bug restor cursor position\n");
									else
										tputs(line, 0, ft_putc);
									if ((line = tgetstr("cd", NULL)) == NULL)
										ft_putstr("bug cd UP\n");
									else
										tputs(line, 0, ft_putc);
									ft_putstr("?>");
									ft_putstr(history->content);
									if (history->next)
										history = history->next;
								}
								if (buf[2] == 'B')
								{
									if ((line = tgetstr("rc", NULL)) == NULL)
										ft_putstr("bug restor cursor position\n");
									else
										tputs(line, 0, ft_putc);
									if ((line = tgetstr("cd", NULL)) == NULL)
										ft_putstr("bug cd down\n");
									else
										tputs(line, 0, ft_putc);
									ft_putstr("?>");
									ft_putstr(history->content);
									if (history->previous)
										history = history->previous;
								}
							}
						}
						else if (buf[0] == 27 && ft_strlen(buf) == 1)
						{
							ft_putstr("\n");
							ft_putstr(RED "-~[ Fermeture du Terminal ]~-\n" RESET);
							tcsetattr(0, TCSADRAIN, &term2);
							exit(0);
						}
						else
						{
							ft_lst_push_back(&chaine, ft_lstnew(buf, 2));
							ft_putstr(buf);
						}
					}
				}
			}
		}
	}
	return (0);
}
