# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkostany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 16:16:06 by nkostany          #+#    #+#              #
#    Updated: 2023/06/03 16:16:11 by nkostany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./inc # -g -fsanitize=address #

PFUNC = src/pipex.c \
		src/functions.c \
		src/other.c \
		src/fdup.c \

LFUNC = libft/ft_putstr_fd.c\
		libft/ft_split.c	\
		libft/ft_strjoin.c	\
		libft/ft_strncmp.c	\
		libft/ft_strchr.c	\
		libft/ft_strnstr.c	\

BFUNC = bonus/child.c \
		bonus/functions.c \
		bonus/here_doc.c \
		bonus/pipex.c \
		bonus/other.c \
		bonus/get_next_line.c \
		bonus/get_next_line_utils.c \

OBJ_L = $(patsubst %.c, %.o, $(LFUNC))
OBJ_P = $(patsubst %.c, %.o, $(PFUNC)) 
OBJ_B = $(patsubst %.c, %.o, $(BFUNC))

HEADER =  inc/pipex.h
HEADER_BONUS = inc/pipex_bonus.h

$(NAME): $(OBJ_P) $(OBJ_L) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ_P) $(OBJ_L) -o $(NAME)

%.o : %.c $(HEADER) 
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

fclean: clean
	rm -rf $(NAME)

bonus: $(OBJ_B) $(OBJ_L) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_B) $(OBJ_L) -o $(NAME)

clean:
	rm -rf $(OBJ_P)
	rm -rf $(OBJ_L)
	rm -rf $(OBJ_B)

re: fclean all

.PHONY: all clean fclean re