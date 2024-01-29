/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:11:15 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/29 16:13:41 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


t_rect rect(int x, int y, int w, int h)
{
	t_rect	res;

	res.pos.x = x;
	res.pos.y = y;
	res.w = w;
	res.h = h;
	return (res);
}

void init_rect(t_rect *rect, int x, int y, int w, int h)
{
	rect->pos.x = x;
	rect->pos.y = y;
	rect->w = w;
	rect->h = h;
}