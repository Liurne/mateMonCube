/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:16:06 by liurne            #+#    #+#             */
/*   Updated: 2023/11/29 01:19:16 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	clear_img(t_data *cub)
{
	destroy_img(cub, &(cub->map.tex[0]));
	destroy_img(cub, &(cub->map.tex[1]));
	destroy_img(cub, &(cub->map.tex[2]));
	destroy_img(cub, &(cub->map.tex[3]));
}