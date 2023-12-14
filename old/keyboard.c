/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:05 by liurne            #+#    #+#             */
/*   Updated: 2023/12/14 16:27:53 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_data *sl)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		close_window(sl);
	if ((keycode == 119 || keycode == 65362) && !sl->keys.down)
		sl->keys.up = 1;
	if ((keycode == 115 || keycode == 65364) && !sl->keys.up)
		sl->keys.down = 1;
	if ((keycode == 97 || keycode == 65361) && !sl->keys.right)
		sl->keys.left = 1;
	if ((keycode == 100 || keycode == 65363) && !sl->keys.left)
		sl->keys.right = 1;
	return (keycode);
}

int	key_release(int keycode, t_data *sl)
{
	if (keycode == 119 || keycode == 65362)
		sl->keys.up = 0;
	if (keycode == 115 || keycode == 65364)
		sl->keys.down = 0;
	if (keycode == 97 || keycode == 65361)
		sl->keys.left = 0;
	if (keycode == 100 || keycode == 65363)
		sl->keys.right = 0;
	return (keycode);
}
