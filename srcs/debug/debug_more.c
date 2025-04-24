/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:59:45 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/03 16:35:30 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Print all variables after parsing
 *
 * @param data the main data structure
 * @param why the why message
 * @param whyColor the why color
 * @param silent whether to print or not
 */
void	db_check_parsing(t_data *data, char *why, char *whyColor, int silent)
{
	if (DEBUG == 0 || silent == 1)
		return ;
	if (why && whyColor)
		printf("\t%s%s%s\n", whyColor, why, RES);
	db_str(data->map.no.path, "NO", GREEN, 0);
	db_str(data->map.so.path, "SO", GREEN, 0);
	db_str(data->map.we.path, "WE", GREEN, 0);
	db_str(data->map.ea.path, "EA", GREEN, 0);
	db_hex(data->map.f.color, "F", GREEN, 0);
	db_hex(data->map.c.color, "C", GREEN, 0);
	db_str_arr(data->map.map, "Map", GREEN, 0);
	db_float(data->player.pos_x, "Player start x", GREEN, 0);
	db_float(data->player.pos_y, "Player start y", GREEN, 0);
	db_float(data->player.dir_x, "Player dir x", GREEN, 0);
	db_float(data->player.dir_y, "Player dir y", GREEN, 0);
	db_float(data->player.plane_x, "Player plane x", GREEN, 0);
	db_float(data->player.plane_y, "Player plane y", GREEN, 0);
}

/**
 * @brief Print a number in hex format
 *
 * @param nbr the number
 * @param why the why message
 * @param whyColor the why color
 * @param silent whether to print or not
 */
void	db_hex(int nbr, char *why, char *whyColor, int silent)
{
	if (DEBUG == 0 || silent == 1)
		return ;
	if (why && whyColor)
		printf("\t%s%s%s ", whyColor, why, RES);
	printf("%s{%#08X}%s\n", GREEN, nbr, RES);
}
