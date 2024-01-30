/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:49:44 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/30 14:55:30 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_line line(int x1, int y1, int x2, int y2)
{
	t_line	res;

	res.p1.x = x1;
	res.p1.y = y1;
	res.p2.x = x2;
	res.p2.y = y2;
	return (res);
}

void init_line(t_line *line, int x1, int y1, int x2, int y2)
{
	line->p1.x = x1;
	line->p1.y = y1;
	line->p2.x = x2;
	line->p2.y = y2;
}
