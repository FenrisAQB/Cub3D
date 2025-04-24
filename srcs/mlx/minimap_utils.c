/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:56:48 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/17 16:56:48 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Draw a cell on the minimap.
 *
 * @param data the main data structure
 * @param screen_x the x position of the cell on the screen
 * @param screen_y the y position of the cell on the screen
 * @param color the color of the cell
 */
void	draw_cell(t_data *data, int screen_x, int screen_y, int color)
{
	int	x;
	int	y;
	int	cell_width;
	int	cell_height;

	cell_width = (W_WIDTH - 200) / data->map.map_width + 1;
	cell_height = (W_HEIGHT - 200) / data->map.map_height + 1;
	if (cell_width < 2)
		cell_width = 2;
	if (cell_height < 2)
		cell_height = 2;
	x = 0;
	while (x < cell_width)
	{
		y = 0;
		while (y < cell_height)
			pix_to_img(&data->img, screen_x + x, screen_y + y++, color);
		x++;
	}
}
