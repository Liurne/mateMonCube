/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:50:37 by bfaure            #+#    #+#             */
/*   Updated: 2024/03/01 12:46:54 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum e_error
{
	MALLOC_FAIL = 1,
	LOAD_IMG_FAIL,
	MLX_INIT_FAIL,
	WIN_INIT_FAIL,
	MLX_NEW_WIN_FAIL,
	MLX_NEW_IMG_FAIL,
	CONTINUE_PROC,
	STOP_PROC,
	MAP_ERROR,
	BAD_FD,
	IMG_INIT_FAIL,
	BAD_COLOR_FORMAT,
	CUB_CONTEXT_INIT_FAIL,
	NULL_DATA,
	INIT_FAIL,
	TOO_MANY_TX_ID,
	TOO_MANY_CO_ID,
	BAD_ID,
	PLAYER_ERROR,
	WRONG_CHAR,
};

#endif
