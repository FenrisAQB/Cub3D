/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:46:58 by cdorig            #+#    #+#             */
/*   Updated: 2025/03/27 15:51:21 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Check that the map is closed off
 *
 * @param data the main data structure
 */
static void	check_map_validity(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = data->map.map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr(PLAYER, map[y][x]) || map[y][x] == '0')
			{
				if (x == 0 || map[y][x + 1] == '\0'
				|| x + 1 == data->map.map_width)
					exit_msg(data, "Map is not correctly closed", 1, 1);
				if (map[y][x - 1] == ' ' || map[y][x + 1] == ' '
				|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
					exit_msg(data, "Map is not correctly closed", 1, 1);
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief Check the first and last line of the map
 *
 * @param data the main data structure
 */
static void	check_map_first_last(t_data *data)
{
	int		i;
	int		y;
	char	**map;

	i = 0;
	map = data->map.map;
	while (map[0][i])
	{
		if (map[0][i] != ' ' && map[0][i] != '1')
			exit_msg(data, "Top of map is not correctly closed", 1, 1);
		i++;
	}
	i = 0;
	y = data->map.map_height - 1;
	while (map[y][i])
	{
		if (map[y][i] != ' ' && map[y][i] != '1')
			exit_msg(data, "Bottom of map is not correctly closed", 1, 1);
		i++;
	}
	check_map_validity(data);
}

/**
 * @brief Check the contents of the map
 *
 * @param data the main data structure
 */
void	check_map_contents(t_data *data)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (!ft_strchr(MAP_CHARS, data->map.map[y][x]))
				exit_msg(data, "Invalid map character", 1, 1);
			if (ft_strchr(PLAYER, data->map.map[y][x]))
			{
				handle_player(data, data->map.map[y][x], x, y);
				player++;
			}
			x++;
		}
		y++;
	}
	if (player != 1)
		exit_msg(data, "Invalid number of players", 1, 1);
	check_map_first_last(data);
}

/**
 * @brief Check if the files can be read && if the colors exist
 *
 * @param data the main data structure
 */
void	check_textures(t_data *data)
{
	int	fd;

	fd = 0;
	if (!data->map.no.path || !data->map.so.path || !data->map.we.path
		|| !data->map.ea.path)
		exit_msg(data, "Missing texture path", 1, 1);
	fd = open(data->map.no.path, O_RDONLY);
	if (fd < 0)
		exit_msg(data, "Could not open NO texture", 1, 1);
	close(fd);
	fd = open(data->map.so.path, O_RDONLY);
	if (fd < 0)
		exit_msg(data, "Could not open SO texture", 1, 1);
	close(fd);
	fd = open(data->map.we.path, O_RDONLY);
	if (fd < 0)
		exit_msg(data, "Could not open WE texture", 1, 1);
	close(fd);
	if (open(data->map.ea.path, O_RDONLY) < 0)
		exit_msg(data, "Could not open EA texture", 1, 1);
	close(fd);
	if (data->map.f.color == -1)
		exit_msg(data, "Missing floor color", 1, 1);
	if (data->map.c.color == -1)
		exit_msg(data, "Missing ceiling color", 1, 1);
}
