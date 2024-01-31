/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:12:30 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 19:00:19 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../../xenocube.h"

t_vec	vec(int x, int y);
void	init_vec(t_vec *vec, int x, int y);
t_dvec	dvec(double x, double y);
void	init_dvec(t_dvec *vec, double x, double y);
t_rect	rect(int x, int y, int w, int h);
void	init_rect(t_rect *rect, t_vec *pos, int w, int h);
t_line	line(int x1, int y1, int x2, int y2);
void	init_line(t_line *line, t_vec *p1, t_vec *p2);

#endif