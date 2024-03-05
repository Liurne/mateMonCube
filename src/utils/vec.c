/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:13:02 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/21 17:47:33 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

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
