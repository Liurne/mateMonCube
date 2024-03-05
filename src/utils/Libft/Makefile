# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:23:52 by bfaure            #+#    #+#              #
#    Updated: 2024/02/21 18:01:05 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

NAME = libft.a

SRCS =	ft_isalpha.c\
		ft_isprint.c\
		ft_memcpy.c\
		ft_strchr.c\
		ft_strlen.c\
		ft_strlen_int.c\
		ft_strlen_line.c\
		ft_strrchr.c\
		ft_bzero.c\
		ft_isascii.c\
		ft_memchr.c\
		ft_memmove.c\
		ft_strlcat.c\
		ft_strncmp.c\
		ft_strcmp.c\
		ft_tolower.c\
		ft_isalnum.c\
		ft_isdigit.c\
		ft_memcmp.c\
		ft_memset.c\
		ft_strlcpy.c\
		ft_strnstr.c\
		ft_toupper.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strfjoin.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strcspn.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_printf.c \
		ft_putchar_printf.c\
		ft_putnbr_base_printf.c\
		ft_putnbr_printf.c\
		ft_putptr_printf.c\
		ft_putstr_printf.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_isspace.c\
		ft_free_tab.c \
		ft_strlen_to_char.c \
		ft_strdup_char.c \
		ft_split.c\
		ft_strndup.c\
		ft_str_isdigit.c\

DIR_SRCS	= src/

DIR_OBJS	= .objs/

DIR_HEAD	= headers/

OBJS		= ${SRCS:%.c=${DIR_OBJS}%.o}


CC = cc

MKDIR = mkdir -p

HEADERS	= 	libft.h\
			get_next_line.h\
			ft_printf.h\

CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=address

all :		${NAME}

clean :
			@rm -rf ${DIR_OBJS} && echo "${RED} * clean: object cleared...${END}"

fclean :	clean
			rm -rf ${NAME} && echo "${RED} * fclean: ${NAME} is fully cleared...${END}"

re :		fclean
			$(MAKE) all

${DIR_OBJS}%.o: 	${DIR_SRCS}%.c	${addprefix ${DIR_HEAD}, ${HEADERS}} | ${DIR_OBJS}
					@${CC} ${CFLAGS} -I${DIR_HEAD} -I../../../ -c $< -o $@ && echo "  $@"

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

${NAME} :	${OBJS}
			@ ar -rc ${NAME} ${OBJS} && echo "${GREEN}\n* ${NAME} compilation completed !!!\n${END}"

.PHONY:		all clean fclean re