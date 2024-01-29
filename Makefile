# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 18:48:58 by aakhtab           #+#    #+#              #
#    Updated: 2024/01/24 11:39:00 by aakhtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=====COLORS=====#
RESET	= \033[0m
GRAY		= \033[0;90m
GREEN		= \033[0;1;3;32m
YELLOW		= \033[0;1;3;33m
SYELLOW		= \033[0;1;33m
RED			= \033[0;1;3;31m
PURPLE		= \033[0;1;3;35m
CYAN		= \033[0;1;3;36m
S1			= "=================================================================================="

AUTHOR			=	aakhtab

CC			=	cc

SRCS			=	src/main.c #src/parsing_part/
				#src/raycasting_part/
					
OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror -I./lib/libft -I./mlx_linux -fsanitize=address -g3
#-g -fsanitize=address

NAME			=	cub3D

LIBFT		= lib/libft.a


MLX = -lmlx -framework OpenGL -framework AppKit

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

all:	${NAME}


${NAME}:	$(LIBFT) ${OBJS} header
			@$(CC) $(CFLAGS) $(SRCS) $(MLX) lib/libft.a -o $(NAME)


$(LIBFT)	:
	@make -s -C lib

##---- need to modier----------
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
##-----------------------------

header:
	@printf  "$(SYELLOW)            __   ____ ___ 	\n"
	@printf  "$(SYELLOW)  ______ __/ /  |_  // _ \	\n"
	@printf  "$(SYELLOW) / __/ // / _ \_/_ </ // /	\n"
	@printf  "$(SYELLOW) \__/\_, /____/____/\___/	\n\n"
	@printf  "$(GREEN)Author\t\t: $(CYAN)$(AUTHOR)\n"
	@printf  "$(GREEN)CC    \t\t: $(YELLOW)$(CC)\n\033[m"
	@printf  "$(GREEN)FLAGS \t\t: $(YELLOW)$(CFLAGS)\n\033[m"
	@printf  "$(GREEN)LIBFT Usage \t: $(YELLOW)Yes\n\033[m"
	
clean:	
			@make -s clean -C lib
			@rm -f $(OBJS)
			@printf "$(YELLOW)\r    [OBJECTS CLEANED 🗑️$(RESET)"

fclean:	clean
			@make -s fclean -C lib
			@rm -f ${NAME}
			@printf "\r												"
			@printf "$(RED)\r     [EVERYTHING CLEANED 👌]    \n$(RESET)"
			
re:	fclean all
