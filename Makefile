# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liurne <liurne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:11:13 by jcoquard          #+#    #+#              #
#    Updated: 2023/11/29 01:17:55 by liurne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ : NAME de la regle
# $^ : tous les OBJS
# $< : premiere dependance

GREY = \033[30m
RED = \033[31m
GREEN = \033[32m
ORANGE = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
LIGHTBLUE = \033[36m
WHITE = \033[37m

IRED=\033[41m
IWHITE=\033[47m
IBLUE=\033[44m
IPURPLE=\033[45m

END = \033[0m

NAME = cub3D
DISPLAY = display

FLAGS		= -Wall -Wextra -Werror -I libs/minilibx/
ARFLAGS		= rsc
MLXFLAGS	= -Llibs/minilibx/ -lmlx -lXext -lX11 -lm
MLX			= libs/minilibx/libmlx.a

SRCS = main.c \
		src/process.c \
		src/utils/free_dtab.c \
		src/utils/transfocube.c \
		src/init/window.c \
		src/init/loading.c \
		src/init/parsing.c \
		src/init/texture.c

OBJS = ${SRCS:.c=.o}

HEADER = src/cube3d.h

all:	libs ${NAME}


${NAME}:	${OBJS}
	@ gcc ${FLAGS} ${OBJS} -o $@ ${MLXFLAGS} libs/libft/libft.a && echo "${GREEN}\n* ${NAME} compilation completed !!!\n${END}"

libs:
	${MAKE} -C lib/libft

%.o:	%.c ${HEADER}
	@ gcc ${FLAGS} -c $< -o $@ && echo "  $@"

clean:
	@ ${RM} ${OBJS} && echo "${RED} * object cleared..."

fclean: clean
	@ ${RM} ${NAME} && echo "${RED} * everything is cleared..."

re:	fclean
	${MAKE} all

sus:
	@echo "${BLUE}           ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀        ${END}"
	@echo "${BLUE}        ⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀     ${END}"
	@echo "${BLUE}        ⣼⣿⠋       ${WHITE}⢀⣀⣀${BLUE}⠈⢻⣿⣿⡄    ${END}"
	@echo "${BLUE}       ⣸⣿⡏   ${WHITE}⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄   ${END}"
	@echo "${BLUE}       ⣿⣿⠁  ${WHITE}⢰⣿⣿⣯⠁       ⠈⠙⢿⣷⡄ ${END}"
	@echo "${BLUE}  ⣀⣤⣴⣶⣶⣿⡟   ${WHITE}⢸⣿⣿⣿⣆          ⣿⣷ ${END}"
	@echo "${BLUE} ⢰⣿⡟⠋⠉⣹⣿⡇   ${WHITE}⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿ ${END}"
	@echo "${BLUE} ⢸⣿⡇  ⣿⣿⡇    ${WHITE}⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃ ${END}"
	@echo "${BLUE} ⣸⣿⡇  ⣿⣿⡇     ${WHITE}⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛${BLUE}⢻⣿⡇  ${END}"
	@echo "${BLUE} ⠸⣿⣧⡀ ⣿⣿⡇                ⣿⣿⠃  ${END}"
	@echo "${BLUE}  ⠛⢿⣿⣿⣿⣿⣇     ⣰⣿⣿⣷⣶⣶⣶⣶⠶ ⢠⣿⣿   ${END}"
	@echo "${BLUE}       ⣿⣿     ⣿⣿⡇ ⣽⣿⡏⠁  ⢸⣿⡇   ${END}"
	@echo "${BLUE}       ⣿⣿     ⣿⣿⡇ ⢹⣿⡆   ⣸⣿⠇   ${END}"
	@echo "${BLUE}       ⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁ ⠈⠻⣿⣿⣿⣿⡿⠏    ${END}"
	@echo "${BLUE}       ⠈⠛⠻⠿⠿⠿⠿⠋⠁              ${END}"
	@echo "$(IBLUE)         ░█▀▀░█░█░█▀▀         ${END}"
	@echo "$(IBLUE)         ░▀▀█░█░█░▀▀█         ${END}"
	@echo "$(IBLUE)         ░▀▀▀░▀▀▀░▀▀▀         ${END}"

.PHONY: all clean fclean re bonussh-5.1$ 
