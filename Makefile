# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 19:22:29 by bfaure            #+#    #+#              #
#    Updated: 2024/01/08 19:22:29 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	cub3D

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	src/

DIR_UTILS	=	${DIR_SRCS}utils/

DIR_GARBAGE	=	${DIR_UTILS}garbage_collector/

DIR_CORE	=	${DIR_SRCS}core/

DIR_DISPLAY	=	${DIR_SRCS}display/

DIR_EVENT	=	${DIR_SRCS}event/

DIR_PARS	= 	${DIR_SRCS}parsing/

DIR_MLX		=	minilibx-linux/

DIR_LIBFT	=	${DIR_UTILS}Libft/

DIR_LST		=	${DIR_UTILS}list/

LIBFT_A = $(DIR_LIBFT)$(LIBFT)

MLXLIB_A = $(DIR_MLX)$(LIBMLX)

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

# ---- Files ---- #

SRCS			=	main.c \
					${DIR_GARBAGE}gc_fonc.c \
					${DIR_GARBAGE}gc_init.c \
					${DIR_CORE}init_ctx.c \
					${DIR_PARS}pars_graphic_path.c \
					${DIR_CORE}win_init.c \
					${DIR_LST}dlst_add.c \
					${DIR_LST}dlst_base_func.c \
					${DIR_LST}dlst_del.c \
					${DIR_LST}dlst_set_get.c \
					${DIR_LST}lst_add.c \
					${DIR_LST}lst_base_func.c \
					${DIR_LST}lst_del.c \
					${DIR_LST}lst_set_get.c \
					${DIR_LST}lst_check.c \
					${DIR_PARS}cp_map_list.c \
					${DIR_PARS}check_map.c \
					${DIR_PARS}create_tab_map.c \
					${DIR_PARS}check_valid_map.c \
					${DIR_CORE}ft_clear.c \
					${DIR_CORE}process.c \
					${DIR_PARS}pars_file.c \
					${DIR_UTILS}vec.c \
					${DIR_UTILS}rect.c \
					${DIR_UTILS}line.c \
					${DIR_DISPLAY}display_utils.c \
					${DIR_DISPLAY}raycast.c \
					${DIR_DISPLAY}raycast_calcul.c \
					${DIR_EVENT}move.c \
					${DIR_EVENT}rotate.c \
					${DIR_EVENT}event_manager.c \


OBJS = ${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

DEPS = ${SRCS:%.c=${DIR_OBJS}%.d}

# ---- Compilation ---- #

DEPS_FLAGS = -MMD -MP

CC		=	cc

CFLAGS	=	${DEPS_FLAGS} -Wall -Wextra -Werror -g3 -fsanitize=address

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all		: ${NAME}

$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT} -j4

$(MLXLIB_A): force
	@ ${MAKE} ${LIBMLX} -C ${DIR_MLX} -j4

.PHONY:	all clean fclean re fclean_lib fclean_all force sus

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft -L${DIR_MLX} -lmlx_Linux -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz || ${MAKE} sus

# ---- Compiled Rules ---- #

-include ${DEPS}

${DIR_OBJS}%.o	:	%.c $(LIBFT_A) $(MLXLIB_A)
					$(MKDIR) $(shell dirname $@)
					${CC} ${CFLAGS}  -c $< -o $@ -I $(DIR_LIBFT) -I ${DIR_MLX} -Iminilibx -Ilibft || ${MAKE} sus

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT}
					make clean -C ${DIR_MLX}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean fclean_lib
					${RM} ${NAME}

bonus			:	all

re				:	fclean
					$(MAKE)

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