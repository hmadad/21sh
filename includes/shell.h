/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:43:05 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/29 16:16:42 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <../libft/libft.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <termcap.h>
# include <term.h>
# include <stdio.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

typedef struct	s_shell
{
	int					position;
	int					pos_max;
	char				*line;
	char				**path;
	char				**all;
	char				**opt;
	char				**env;
	struct s_history	*history;
	struct termios		default_term;
}				t_shell;

typedef struct		s_history
{
	char				*content;
	struct s_history	*previous;
	struct s_history	*next;

}					t_history;

int				ft_21sh(char ***env);
t_history		*ft_init_term(t_shell **shell);
void			ft_read_commande(t_shell **shell);
void			ft_history_key(t_shell **shell, char *buf);
char			*ft_ltos(t_list **commande);
void			ft_reset_position(t_shell **shell);
t_history		*ft_listenew(char *content);
void			ft_liste_push_back(t_history **lst, t_history *new);
void			ft_liste_push_front(t_history **lst, t_history *new);
int				ft_putc(int c);
char			*ft_getenv(char **env, char *search);
int				ft_setenv(char ***env, char *str);
int				ft_unsetenv(char ***env, char *str);
char			*get_pwd();
void			ft_prompt(char **env);
char			*ft_find_last_pwd(char *pwd);
char			**ft_realloc(char ***ta, char *str);
char			**ft_unalloc(char ***ta, char *str);

#endif
