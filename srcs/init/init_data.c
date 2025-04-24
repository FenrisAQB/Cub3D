/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:11:08 by jbarbey           #+#    #+#             */
/*   Updated: 2025/04/15 10:01:42 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Initialize the texture structure
 * @details Set paths to NULL and color to -1
 *
 * @param tex the texture structure
 */
static void	init_texture_path(t_texpath *tex)
{
	tex->path = NULL;
	tex->color = -1;
}

/**
 * @brief Initialize the map structure
 * @details Set map pointer to NULL and call init_texture
 *
 * @param map the map structure
 */
static void	init_map(t_map *map)
{
	init_texture_path(&map->no);
	init_texture_path(&map->so);
	init_texture_path(&map->we);
	init_texture_path(&map->ea);
	init_texture_path(&map->f);
	init_texture_path(&map->c);
	map->map = NULL;
	map->map_width = -1;
	map->map_height = -1;
}

/**
 * @brief Initialize the player structure
 * @details Set all values to 0 and keys to 0
 *
 * @param player the player structure
 */
static void	init_player(t_player *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->rot = 0;
	player->moved = 0;
	ft_bzero(player->keys, 20);
}

/**
 * @brief Initialize the textures structure
 * @details Set all pointers to NULL and address to 0
 *
 * @param data the data structure
 */
void	init_textures(t_data *data)
{
	t_img	*i;

	data->tex.size = TILE;
	i = data->tex.texs;
	i[0].ptr = NULL;
	i[1].ptr = NULL;
	i[2].ptr = NULL;
	i[3].ptr = NULL;
	i[0].addr = 0;
	i[1].addr = 0;
	i[2].addr = 0;
	i[3].addr = 0;
}

/**
 * @brief Initialize the data structure
 * @details Set all pointers to NULL and call init_map
 *
 * @param data the data structure
 */
void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.ptr = NULL;
	data->img.addr = NULL;
	data->minimap_mode = 0;
	init_map(&data->map);
	init_player(&data->player);
	init_textures(data);
}
