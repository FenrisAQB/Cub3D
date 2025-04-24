/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:03:51 by jbarbey           #+#    #+#             */
/*   Updated: 2025/04/15 10:17:41 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Assign textures to the data struct
 *
 * @param data data struct
 * @param m mlx pointer
 * @param t texture struct
 * @param map map struct
 */
void	assign_textures(t_data *data, void *m, t_tex *t, t_map *map)
{
	t_img	*i;

	t->size = TILE;
	i = t->texs;
	i[0].ptr = mlx_xpm_file_to_image(m, map->no.path, &t->size, &t->size);
	if (!i[0].ptr)
		exit_msg(data, "mlx_xpm_file_to_image failed", 1, 1);
	i[1].ptr = mlx_xpm_file_to_image(m, map->so.path, &t->size, &t->size);
	if (!i[1].ptr)
		exit_msg(data, "mlx_xpm_file_to_image failed", 1, 1);
	i[2].ptr = mlx_xpm_file_to_image(m, map->we.path, &t->size, &t->size);
	if (!i[2].ptr)
		exit_msg(data, "mlx_xpm_file_to_image failed", 1, 1);
	i[3].ptr = mlx_xpm_file_to_image(m, map->ea.path, &t->size, &t->size);
	if (!i[3].ptr)
		exit_msg(data, "mlx_xpm_file_to_image failed", 1, 1);
	i[0].addr = (int *)mlx_get_data_addr(i[0].ptr, &i[0].b, &i[0].ll, &i[0].e);
	i[1].addr = (int *)mlx_get_data_addr(i[1].ptr, &i[1].b, &i[1].ll, &i[1].e);
	i[2].addr = (int *)mlx_get_data_addr(i[2].ptr, &i[2].b, &i[2].ll, &i[2].e);
	i[3].addr = (int *)mlx_get_data_addr(i[3].ptr, &i[3].b, &i[3].ll, &i[3].e);
}

/**
 * @brief Create the mlx window
 *
 * @param data data struct
 */

void	create_window(t_data *data)
{
	t_img	*t;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_msg(data, "mlx_init failed", 1, 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, W_NAME);
	if (!data->win_ptr)
		exit_msg(data, "mlx_new_window failed", 1, 1);
	t = &data->img;
	t->ptr = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!t->ptr)
		exit_msg(data, "mlx_new_image failed", 1, 1);
	t->addr = (int *)mlx_get_data_addr(t->ptr, &t->b, &t->ll, &t->e);
}

/**
 * @brief destroy mlx window and exit
 *
 * @param data data struct
 */
int	destroy_window(t_data *data)
{
	if (data->tex.texs[NORTH].ptr)
		mlx_destroy_image(data->mlx_ptr, data->tex.texs[NORTH].ptr);
	if (data->tex.texs[SOUTH].ptr)
		mlx_destroy_image(data->mlx_ptr, data->tex.texs[SOUTH].ptr);
	if (data->tex.texs[WEST].ptr)
		mlx_destroy_image(data->mlx_ptr, data->tex.texs[WEST].ptr);
	if (data->tex.texs[EAST].ptr)
		mlx_destroy_image(data->mlx_ptr, data->tex.texs[EAST].ptr);
	if (data->img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	return (0);
}
