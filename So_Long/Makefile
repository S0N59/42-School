# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkostany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 13:15:25 by nkostany          #+#    #+#              #
#    Updated: 2023/07/13 13:15:31 by nkostany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
PRINTF_PATH	=	./ft_printf/
GNL_PATH	= 	./get_next_line/
SRC_PATH	=	./src/

SRC 		= 	$(addprefix $(SRC_PATH),	 main.c			 \
											 parsing.c	  	 \
											 pathing.c		 \
											 count_line.c	 \
											 key_hook.c 	 \
											 keys.c 		 \
											 print_sprites.c \
											 initialize.c 	 \
											 ft_tabdup.c 	 \
											 is_door_open.c  )
				
SRC_PRINTF	=	 $(addprefix $(PRINTF_PATH), ft_printf.c			     \
											 ft_printf_utils.c			 \
											 ft_printf_print_hex.c		 \
											 ft_pritnf_utils2.c			 \
											 ft_printf_print_ptr.c		 \
											 ft_printf_print_unsigned.c  )

SRC_GNL		=	 $(addprefix $(GNL_PATH), 	 get_next_line.c 	   \
										  	 get_next_line_utils.c )

OBJ_DIR 	= ./obj
OBJ_SRC	= $(patsubst $(SRC_PATH)%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_GNL = $(patsubst $(GNL_PATH)%.c, $(OBJ_DIR)/%.o, $(SRC_GNL))
OBJ_PRINTF = $(patsubst $(PRINTF_PATH)%.c, $(OBJ_DIR)/%.o, $(SRC_PRINTF))


NAME 		= so_long
CC 			= cc
MLX			= -lmlx -framework OpenGL -framework AppKit
RM 			= rm -rf
MK			= mkdir -p

CFLAGS 		= -Wall -Werror -Wextra -I inc/  #-g -fsanitize=address 

all:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_PATH)%.c 
		@$(MK) $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_PATH)%.c 
		@$(MK) $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_PATH)%.c
		@$(MK) $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_SRC) $(OBJ_GNL) $(OBJ_PRINTF)
		@$(CC) $(MLX) $(CFLAGS) $(OBJ_SRC) $(OBJ_GNL) $(OBJ_PRINTF) -o $(NAME)


clean:
			@$(RM) $(OBJ_DIR)

fclean: 	clean
			@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: 	all clean fclean re 
