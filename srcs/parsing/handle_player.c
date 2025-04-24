/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:48:47 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/03 16:36:15 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Handle the player assignment
 *
 * @param data the main data structure
 * @param c the character to handle
 * @param x the x position
 * @param y the y position
 */
void	handle_player(t_data *data, char c, int x, int y)
{
	data->player.pos_x = x;
	data->player.pos_y = y;
	if (c == 'N')
	{
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
	}
	else if (c == 'S')
	{
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
	}
	else if (c == 'W')
	{
		data->player.dir_x = -1;
		data->player.plane_y = -0.66;
	}
	else if (c == 'E')
	{
		data->player.dir_x = 1;
		data->player.plane_y = 0.66;
	}
}
