/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:40:05 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/15 10:17:37 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief main update loop
 *
 * @param data data struct
 */
int	update(t_data *data)
{
	move_player(data);
	if (!data->player.moved)
		return (0);
	data->player.moved = 0;
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	db_str(FOXMOJI, "DEBUG MODE ENABLED", BGREEN, 0);
	check_args(ac, av);
	init_data(&data);
	parse_and_check(&data, av[1]);
	create_window(&data);
	init_hooks(&data);
	init_textures(&data);
	assign_textures(&data, data.mlx_ptr, &data.tex, &data.map);
	raycasting(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.ptr, 0, 0);
	mlx_loop_hook(data.mlx_ptr, &update, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
