/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:50:37 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/31 11:33:59 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum e_error
{
	MALLOC_FAIL = 1,
	MLX_INIT_FAIL,
	MLX_NEW_WIN_FAIL,
	MLX_NEW_IMG_FAIL,
	CONTINUE_PROC,
	STOP_PROC,
	MAP_ERROR,
	BAD_FD,
	IMG_INIT_FAIL,
	DONT_FUCK_WITH_ME,
	CUB_CONTEXT_INIT_FAIL,
	NULL_DATA,
};

#endif
