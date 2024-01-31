/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:49:44 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 18:58:09 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_line	line(int x1, int y1, int x2, int y2)
{
	t_line	res;

	res.p1.x = x1;
	res.p1.y = y1;
	res.p2.x = x2;
	res.p2.y = y2;
	return (res);
}

void	init_line(t_line *line, t_vec *p1, t_vec *p2)
{
	line->p1.x = p1->x;
	line->p1.y = p1->y;
	line->p2.x = p2->x;
	line->p2.y = p2->y;
}
