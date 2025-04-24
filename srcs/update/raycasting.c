/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:17:04 by jbarbey           #+#    #+#             */
/*   Updated: 2025/04/08 12:07:25 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Initializes every relevant info for each ray at raycasting start
 * 
 * @param ray Ray structure
 * @param player Player structure
 * @param x The ray index
 */
static void	init_raycasting(t_ray *ray, t_player *player, int x)
{
	ray->cam_x = 2 * x / (double)W_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->cam_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->cam_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

/**
 * @brief Sets the correct values used during dda
 * 
 * @param ray Ray struct
 * @param player Player struct
 */
static void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

/**
 * @brief Actual DDA algorithm (finds wall hit and side)
 * 
 * @param data Data struct
 * @param ray Ray struct
 */
static void	perform_dda(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_y > map->map_height - 1.25
			|| ray->map_x < 0.25 || ray->map_x > map->map_width - 1.25)
			break ;
		if (map->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/**
 * @brief Calculates the wall height based on it's distance from player
 * 
 * @param data Data struct
 * @param player Player struct
 * @param ray Ray struct
 */
static void	calc_line_height(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
	ray->line_height = W_HEIGHT / ray->wall_dist;
	ray->draw_start = -ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_end >= W_HEIGHT)
		ray->draw_end = W_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

/**
 * @brief Main raycasting function, calls sub-functions
 * 
 * @param data Data struct
 */
void	raycasting(t_data *data)
{
	t_ray	ray;
	int		x;
	int		y;

	x = 0;
	while (x < W_WIDTH)
	{
		init_raycasting(&ray, &data->player, x);
		set_dda(&ray, &data->player);
		perform_dda(&ray, &data->map);
		calc_line_height(&data->player, &ray);
		y = 0;
		while (y < ray.draw_start)
			pix_to_img(&data->img, x, y++, data->map.c.color);
		get_pix_color(data, &data->tex, &ray, x);
		y = ray.draw_end;
		while (y < W_HEIGHT - 1)
			pix_to_img(&data->img, x, y++, data->map.f.color);
		x++;
	}
}
