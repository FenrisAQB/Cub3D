/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:40:20 by jbarbey           #+#    #+#             */
/*   Updated: 2025/04/11 19:38:07 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Key press handler
 *
 * @param key Keycode
 * @param data data struct
 */
static int	key_press(int key, t_data *data)
{
	if (DEBUG == 1)
		db_nbr(key, "Key Code pressed", BBLUE, 0);
	if (key == XK_Escape)
		clean_exit(data, 0);
	if (key == XK_w && !data->minimap_mode)
		data->player.keys[W] = 1;
	if (key == XK_a && !data->minimap_mode)
		data->player.keys[A] = 1;
	if (key == XK_s && !data->minimap_mode)
		data->player.keys[S] = 1;
	if (key == XK_d && !data->minimap_mode)
		data->player.keys[D] = 1;
	if ((key == XK_Left || key == XK_q) && !data->minimap_mode)
		data->player.rot = -1;
	if ((key == XK_Right || key == XK_e) && !data->minimap_mode)
		data->player.rot = 1;
	if (key == XK_m)
	{
		data->minimap_mode = !data->minimap_mode;
		if (data->minimap_mode)
			show_minimap(data);
		else
			hide_minimap(data);
	}
	return (0);
}

/**
 * @brief Key release handler
 *
 * @param key Keycode
 * @param data data struct
 */
static int	key_release(int key, t_data *data)
{
	if (key == XK_w)
		data->player.keys[W] = 0;
	if (key == XK_a)
		data->player.keys[A] = 0;
	if (key == XK_s)
		data->player.keys[S] = 0;
	if (key == XK_d)
		data->player.keys[D] = 0;
	if (key == XK_Left || key == XK_q)
		data->player.rot = 0;
	if (key == XK_Right || key == XK_e)
		data->player.rot = 0;
	return (0);
}

/**
 * @brief mouse handler
 *
 * @param x coordinate
 * @param y coordinate
 * @param data data struct
 */
static int	mouse_handler(int x, int y, t_data *data)
{
	static int	old_x = W_WIDTH / 2;

	if (data->minimap_mode)
		return (0);
	if (x > W_WIDTH - 20)
	{
		x = 20;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	}
	if (x < 20)
	{
		x = W_WIDTH - 20;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	}
	if (x == old_x)
		return (0);
	if (x < old_x)
		data->player.moved += rotate_player(&data->player, -1);
	else if (x > old_x)
		data->player.moved += rotate_player(&data->player, 1);
	old_x = x;
	return (0);
}

/**
 * @brief init mlx hooks
 *
 * @param data data struct
 */
void	init_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	mlx_hook(data->win_ptr, 2, KeyPressMask, key_press, data);
	mlx_hook(data->win_ptr, 3, KeyReleaseMask, key_release, data);
	mlx_hook(data->win_ptr, 6, PointerMotionMask, mouse_handler, data);
}
