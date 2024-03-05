/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:42:35 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/29 14:47:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_uint	pars_file(t_cub_context *cubx, t_str path);
t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, t_uint n);
t_uint	check_map(t_cub_context *cubx);
t_uint	add_map_to_lst(t_cub_context *cubx, t_str line);
t_uint	find_sizes(t_cub_context *cubx);
t_uint	remplace_tab_space(t_cub_context *cubx);
t_uint	create_tab_map(t_cub_context *cubx);
t_uint	check_valid_map(t_cub_context *cubx);
t_uint	back_to_normal_map(t_cub_context *cubx);
t_uint	find_we_no(t_cub_context *cubx, t_str line);
t_uint	find_ea_so(t_cub_context *cubx, t_str line);
t_uint	find_color(t_cub_context *cubx, t_str line);
t_uint	pars_color(t_cub_context *cubx, t_str line, int bg);
t_uint	ft_strcub(const char *haystack);
t_uint	check_char(t_cub_context *cubx);
t_uint	is_finish(t_cub_context *cubx, t_str line);
bool	is_player(char c);

#endif
