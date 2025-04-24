/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:21 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/22 09:54:30 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Draw the background for the minimap.
 *
 * @param data the main data structure
 */
static void	minimap_background(t_data *data)
{
	int	x;
	int	y;

	x = 50;
	while (x < W_WIDTH - 50)
	{
		y = 50;
		while (y < W_HEIGHT - 50)
			pix_to_img(&data->img, x, y++, 0x00000000);
		x++;
	}
}

/**
 * @brief Draw the player on the minimap.
 *
 * @param data the main data structure
 */
static void	minimap_player(t_data *data)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	x = 100 + (int)(data->player.pos_x * (W_WIDTH - 200) / data->map.map_width);
	y = 100 + (int)(data->player.pos_y * (W_HEIGHT - 200)
			/ data->map.map_height);
	dx = 0;
	while (dx < 11)
	{
		dy = 0;
		while (dy < 11)
		{
			pix_to_img(&data->img, x + dx, y + dy, 0x00FF0000);
			dy++;
		}
		dx++;
	}
}

/**
 * @brief Draw the walls on the minimap.
 *
 * @param data the main data structure
 */
static void	minimap_walls(t_data *data)
{
	int	map_x;
	int	map_y;
	int	screen_x;
	int	screen_y;

	map_x = 0;
	while (map_x < data->map.map_width)
	{
		map_y = 0;
		while (map_y < data->map.map_height)
		{
			screen_x = 100 + (map_x * (W_WIDTH - 200) / data->map.map_width);
			screen_y = 100 + (map_y * (W_HEIGHT - 200) / data->map.map_height);
			if (data->map.map[map_y][map_x] == '1')
				draw_cell(data, screen_x, screen_y, 0x00FFFFFF);
			map_y++;
		}
		map_x++;
	}
}

/**
 * @brief Show the minimap on the window.
 *
 * @param data the main data structure
 */
void	show_minimap(t_data *data)
{
	db_str(FOXMOJI, "SHOW_MINIMAP", BGREEN, SILENT);
	minimap_background(data);
	minimap_walls(data);
	minimap_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

/**
 * @brief Hide the minimap on the window.
 *
 * @param data the main data structure
 */
void	hide_minimap(t_data *data)
{
	db_str(FOXMOJI, "HIDE_MINIMAP", BGREEN, SILENT);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}
