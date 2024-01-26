# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:11:13 by jcoquard          #+#    #+#              #
#    Updated: 2024/01/26 17:47:53 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ : NAME de la regle
# $^ : tous les OBJS
# $< : premiere dependance

GREY		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
ORANGE		= \033[33m
BLUE		= \033[34m
PURPLE		= \033[35m
LIGHTBLUE	= \033[36m
WHITE		= \033[37m
IRED		= \033[41m
IWHITE		= \033[47m
IBLUE		= \033[44m
IPURPLE		= \033[45m
END			= \033[0m

NAME		= cub3D
DISPLAY		= display

FLAGS		= -Wall -Wextra  -I incl/ -I libs/minilibx/ -I libs/libft -g3 -fsanitize=address
MLXFLAGS	= -Llibs/minilibx/ -L/usr/lib -lmlx -lXext -lX11 -lm -lz
MLX			= libs/minilibx/libmlx.a

SRCS		=	src/main.c \
				src/core/window.c \
				src/core/keyboard.c \
				src/core/process.c \
				src/display/display.c \
				src/display/raycast.c \
				src/parsing/parsing.c \
				src/parsing/init.c \
				src/parsing/transfocube.c \
				src/parsing/loading.c \
				src/entity/entity.c \
				src/utils/vec.c \
				src/map/map.c
OBJS		= ${SRCS:.c=.o}

HEADER		= incl/cub3D.h \
				incl/define.h

all:	libs ${NAME}


${NAME}:	${OBJS}
	@ gcc ${FLAGS} -o $@ ${OBJS} libs/libft/libft.a ${MLXFLAGS} && echo "${GREEN}\n* ${NAME} compilation completed !!!\n${END}"

libs:
	${MAKE} -C libs/libft
#${MAKE} -C libs/minilibx

%.o: %.c ${HEADER}
	@ gcc ${FLAGS} ${HEAD} -c $< -o $@ && echo "  $@"

clean:
	@ ${RM} ${OBJS} && echo "${RED} * object cleared...${END}"

fclean: clean
	@ ${RM} ${NAME} && echo "${RED} * everything is cleared...${END}"
	$(MAKE) fclean -C libs/libft


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

.PHONY: all libs clean fclean re$ 
