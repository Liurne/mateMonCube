/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:54:50 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/26 17:04:36 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "../../xenocube.h"

void	rotate_left(t_cub_entity *entity);
void	rotate_right(t_cub_entity *entity);
void	move_forward(t_map *map, t_cub_entity *entity);
void	move_backward(t_map *map, t_cub_entity *entity);
void	move_right(t_map *map, t_cub_entity *entity);
void	move_left(t_map *map, t_cub_entity *entity);
int		key_press(int keycode, t_cub_context *cubx);
int		key_release(int keycode, t_cub_context *cubx);
void	player_manager(t_cub_context *cubx);
#endif