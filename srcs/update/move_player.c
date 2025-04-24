/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:36:43 by jbarbey           #+#    #+#             */
/*   Updated: 2025/04/15 10:25:05 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Rotates player angle
 *
 * @param player player struct
 * @param rot_dir rotation direction
 */
int	rotate_player(t_player *player, int rot_dir)
{
	double	rot;
	double	tmp_x;

	if (!rot_dir)
		return (0);
	rot = rot_dir * 0.015;
	tmp_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot) - player->dir_y * sin(rot);
	player->dir_y = tmp_x * sin(rot) + player->dir_y * cos(rot);
	tmp_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot) - player->plane_y * sin(rot);
	player->plane_y = tmp_x * sin(rot) + player->plane_y * cos(rot);
	return (1);
}

/**
 * @brief checks if move valid for collisions
 *
 * @param data data struct
 * @param p player struct
 * @param x coordinate
 * @param y coordinate
 */
static int	move_valid(t_data *data, t_player *p, float x, float y)
{
	if (x > 0.25 && x < data->map.map_width - 1.25
		&& (data->map.map[(int)p->pos_y][(int)x] == '0'
		|| ft_strchr(PLAYER, data->map.map[(int)p->pos_y][(int)x])))
		p->pos_x = x;
	if (y > 0.25 && y < data->map.map_height - 1.25
		&& (data->map.map[(int)y][(int)p->pos_x] == '0'
		|| ft_strchr(PLAYER, data->map.map[(int)y][(int)p->pos_x])))
		p->pos_y = y;
	if (p->pos_x != x && p->pos_y != y)
		return (0);
	return (1);
}

/**
 * @brief move player front and back
 *
 * @param data data struct
 * @param dir direction
 */
static int	move_front_back(t_data *data, int dir)
{
	double	tmp_x;
	double	tmp_y;

	if (dir == W)
	{
		tmp_x = data->player.pos_x + data->player.dir_x * 0.07;
		tmp_y = data->player.pos_y + data->player.dir_y * 0.07;
		return (move_valid(data, &data->player, tmp_x, tmp_y));
	}
	if (dir == S)
	{
		tmp_x = data->player.pos_x - data->player.dir_x * 0.07;
		tmp_y = data->player.pos_y - data->player.dir_y * 0.07;
		return (move_valid(data, &data->player, tmp_x, tmp_y));
	}
	return (0);
}

/**
 * @brief move player sideways
 *
 * @param data data struct
 * @param dir direction
 */
static int	move_sideways(t_data *data, int dir)
{
	double	tmp_x;
	double	tmp_y;

	if (dir == A)
	{
		tmp_x = data->player.pos_x + data->player.dir_y * 0.06;
		tmp_y = data->player.pos_y - data->player.dir_x * 0.06;
		return (move_valid(data, &data->player, tmp_x, tmp_y));
	}
	if (dir == D)
	{
		tmp_x = data->player.pos_x - data->player.dir_y * 0.06;
		tmp_y = data->player.pos_y + data->player.dir_x * 0.06;
		return (move_valid(data, &data->player, tmp_x, tmp_y));
	}
	return (0);
}

/**
 * @brief player movement handler
 *
 * @param data data struct
 */
void	move_player(t_data *data)
{
	if (data->player.keys[W] == 1)
		data->player.moved += move_front_back(data, W);
	if (data->player.keys[A] == 1)
		data->player.moved += move_sideways(data, A);
	if (data->player.keys[S] == 1)
		data->player.moved += move_front_back(data, S);
	if (data->player.keys[D] == 1)
		data->player.moved += move_sideways(data, D);
	data->player.moved += rotate_player(&data->player, data->player.rot);
}
