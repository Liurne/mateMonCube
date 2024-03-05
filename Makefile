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

NAME		= cub3D

LIBFT		= libft.a

LIBMLX		= libmlx.a

# ---- Directories ---- #

HEADER			= ./ 

DIR_OBJS		= .objs/

DIR_SRCS		= src/

DIR_UTILS		= ${DIR_SRCS}utils/

DIR_GARBAGE		= ${DIR_UTILS}garbage_collector/

DIR_CORE		= ${DIR_SRCS}core/

DIR_RENDERER	= ${DIR_SRCS}renderer/

DIR_EVENT		= ${DIR_SRCS}event/

DIR_PARS		= ${DIR_SRCS}parsing/

DIR_MLX			= minilibx-linux/

DIR_LIBFT		= ${DIR_UTILS}Libft/

DIR_LST			= ${DIR_UTILS}list/

LIBFT_A 		= $(DIR_LIBFT)$(LIBFT)

MLXLIB_A 		= $(DIR_MLX)$(LIBMLX)

# ---- Colors ---- #

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

SRCS	=	main.c \
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
			${DIR_RENDERER}display_utils.c \
			${DIR_RENDERER}raycast.c \
			${DIR_RENDERER}raycast_calcul.c \
			${DIR_EVENT}move.c \
			${DIR_EVENT}rotate.c \
			${DIR_EVENT}event_manager.c \
			${DIR_PARS}pars_color.c \
			${DIR_PARS}find.c \
			${DIR_PARS}ft_strcub.c \
			${DIR_PARS}check_player.c \
			${DIR_UTILS}parsing_utils.c \


OBJS = ${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

DEPS = ${SRCS:%.c=${DIR_OBJS}%.d}

# ---- Compilation ---- #

DEPS_FLAGS	= -MMD -MP

CC			= cc

CFLAGS		= ${DEPS_FLAGS} -Wall -Wextra -Werror -g3 #-fsanitize=address

# ---- Commands ---- #

RM		= rm -rf
MKDIR	= mkdir -p

# ********* RULES ******** #

all		: ${NAME}

$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT} -j4

$(MLXLIB_A): force
	@ ${MAKE} ${LIBMLX} -C ${DIR_MLX} -j4

.PHONY:	all clean fclean re fclean_lib fclean_all force sus

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			@ ${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft -L${DIR_MLX} -lmlx_Linux -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz && echo "${GREEN}\n* ${NAME} compilation completed !!!\n${END}" || ${MAKE} sus

# ---- Compiled Rules ---- #

-include ${DEPS}

${DIR_OBJS}%.o	:	%.c $(LIBFT_A) $(MLXLIB_A)
					@ $(MKDIR) $(shell dirname $@)
					@ ${CC} ${CFLAGS}  -I $(HEADER) -c $< -o $@ -I $(DIR_LIBFT) -I ${DIR_MLX} -Iminilibx -Ilibft && echo "  $@" || ${MAKE} sus

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT}
					make clean -C ${DIR_MLX}

clean			:
					@ ${RM} ${DIR_OBJS}  && echo "${RED} * clean: object cleared...${END}"

fclean			:	clean fclean_lib
					@ ${RM} ${NAME} && echo "${RED} * fclean: ${NAME} is fully cleared...${END}"

bonus			:	all

re				:	fclean
					$(MAKE)

sus:
	@echo "${RED}           ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀        ${END}"
	@echo "${RED}        ⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀     ${END}"
	@echo "${RED}        ⣼⣿⠋       ${WHITE}⢀⣀⣀${RED}⠈⢻⣿⣿⡄    ${END}"
	@echo "${RED}       ⣸⣿⡏   ${WHITE}⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄   ${END}"
	@echo "${RED}       ⣿⣿⠁  ${WHITE}⢰⣿⣿⣯⠁       ⠈⠙⢿⣷⡄ ${END}"
	@echo "${RED}  ⣀⣤⣴⣶⣶⣿⡟   ${WHITE}⢸⣿⣿⣿⣆          ⣿⣷ ${END}"
	@echo "${RED} ⢰⣿⡟⠋⠉⣹⣿⡇   ${WHITE}⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿ ${END}"
	@echo "${RED} ⢸⣿⡇  ⣿⣿⡇    ${WHITE}⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃ ${END}"
	@echo "${RED} ⣸⣿⡇  ⣿⣿⡇     ${WHITE}⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛${RED}⢻⣿⡇  ${END}"
	@echo "${RED} ⠸⣿⣧⡀ ⣿⣿⡇                ⣿⣿⠃  ${END}"
	@echo "${RED}  ⠛⢿⣿⣿⣿⣿⣇     ⣰⣿⣿⣷⣶⣶⣶⣶⠶ ⢠⣿⣿   ${END}"
	@echo "${RED}       ⣿⣿     ⣿⣿⡇ ⣽⣿⡏⠁  ⢸⣿⡇   ${END}"
	@echo "${RED}       ⣿⣿     ⣿⣿⡇ ⢹⣿⡆   ⣸⣿⠇   ${END}"
	@echo "${RED}       ⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁ ⠈⠻⣿⣿⣿⣿⡿⠏    ${END}"
	@echo "${RED}       ⠈⠛⠻⠿⠿⠿⠿⠋⠁              ${END}"
	@echo "$(IRED)         ░█▀▀░█░█░█▀▀         ${END}"
	@echo "$(IRED)         ░▀▀█░█░█░▀▀█         ${END}"
	@echo "$(IRED)         ░▀▀▀░▀▀▀░▀▀▀         ${END}"