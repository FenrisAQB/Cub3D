/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:05:20 by jbarbey           #+#    #+#             */
/*   Updated: 2025/04/11 19:43:48 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief sets pixel on mlx image
 * 
 * @param i image pointer
 * @param x coordinate
 * @param y coordinate
 * @param color color
 */
void	pix_to_img(t_img *i, int x, int y, int color)
{
	int	pixel;

	pixel = y * (i->ll / 4) + x;
	i->addr[pixel] = color;
}

/**
 * @brief set texture index
 * 
 * @param ray ray struct
 */
static int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x < 0)
		return (WEST);
	else if (ray->side == 0 && ray->dir_x > 0)
		return (EAST);
	else if (ray->side == 1 && ray->dir_y < 0)
		return (NORTH);
	else if (ray->side == 1 && ray->dir_y > 0)
		return (SOUTH);
	return (-1);
}

/**
 * @brief get relevant pixel color from texture
 * 
 * @param data data struct
 * @param t texture struct
 * @param ray ray struct
 * @param x current ray index on x axis
 */
void	get_pix_color(t_data *data, t_tex *t, t_ray *ray, int x)
{
	int	index;
	int	y;
	int	color;

	index = get_texture_index(ray);
	if (index == -1)
		return ;
	t->x = (int)(ray->wall_x * t->size);
	if (index == WEST || index == SOUTH)
		t->x = t->size - t->x - 1;
	t->step = 1.0 * t->size / ray->line_height;
	t->pos = (ray->draw_start - W_HEIGHT / 2 + ray->line_height / 2) * t->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		t->y = (int)t->pos & (t->size - 1);
		t->pos += t->step;
		color = t->texs[index].addr[t->size * t->y + t->x];
		if (index == NORTH || index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			pix_to_img(&data->img, x, y, color);
		y++;
	}
}
