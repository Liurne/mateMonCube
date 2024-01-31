/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:13:02 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 18:58:47 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_vec	vec(int x, int y)
{
	t_vec	res;

	res.x = x;
	res.y = y;
	return (res);
}

void	init_vec(t_vec *vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
}

t_dvec	dvec(double x, double y)
{
	t_dvec	res;

	res.x = x;
	res.y = y;
	return (res);
}

void	init_dvec(t_dvec *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}
