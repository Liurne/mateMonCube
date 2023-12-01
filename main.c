/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:56 by liurne            #+#    #+#             */
/*   Updated: 2023/11/29 01:14:07 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cube3d.h"

int	main(int ac, char **av)
{
	t_data	cub;

	init_window(cub, WIN_W, WIN_H);
	if (ac < 2 || ac > 2)
		return (error(&cub, ERR_ARG));
	if (load_file(&cub, av[1]))
		return (1);
	if (parsing(&cub))
		return (1);
	return (0);
}