/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:11:15 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/21 17:47:04 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_rect	rect(int x, int y, int w, int h)
{
	t_rect	res;

	res.pos.x = x;
	res.pos.y = y;
	res.w = w;
	res.h = h;
	return (res);
}

void	init_rect(t_rect *rect, t_vec *pos, int w, int h)
{
	rect->pos.x = pos->x;
	rect->pos.y = pos->y;
	rect->w = w;
	rect->h = h;
}
