# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmadad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/12 14:56:33 by hmadad            #+#    #+#              #
#    Updated: 2017/04/25 15:03:38 by hmadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC_PATH = ./srcs

SRCS_NAME = ft_21sh.c \
			ft_env.c \
			ft_find_last_pwd.c \
			ft_arrow_key.c \
			ft_init_term.c \
			ft_lst_history.c \
			ft_ltos.c \
			ft_prompt.c \
			ft_read_commande.c \
			ft_realloc.c \
			ft_print_char.c \
			ft_termcap_delete.c \
			ft_strtrimb.c \
			ft_exec_commande.c \
			ft_change_home_sign.c \
			ft_exit.c \
			ft_commande.c \
			ft_echo.c \
			ft_prepare_cd.c \
			ft_cd.c \
			ft_cd_error.c \
			ft_trim.c \
			ft_get_pwd.c \
			ft_pipette.c \
			ft_move_to_word.c \
			ft_home_end.c \
			ft_print_history.c \
			main.c \

SRC = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

OBJECTS = $(SRCS_NAME:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc $(FLAGS) -I ./includes -c $(SRC)
	@gcc -o $(NAME) -lreadline -ltermcap $(OBJECTS) -lft -L libft

.PHONY: clean
clean:
	@rm -f $(OBJECTS)
	@make clean -C ./libft
	@echo "objects files deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "minishell deleted"

re: fclean all
