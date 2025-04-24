/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:24:09 by cdorig            #+#    #+#             */
/*   Updated: 2025/03/27 09:53:50 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Handle the path identifier
 *
 * @param data the data structure
 * @param line the line to handle
 * @param ident the identifier
 * @return int 0 if success, 1 if error
 */
static int	handle_path(t_data *data, char **arr)
{
	char	*content;

	if (arr[2])
		return (err_msg("Invalid identifier"), 1);
	content = ft_strdup(arr[1]);
	if (!content)
		return (err_msg("Memory allocation failed"), 1);
	if (!ft_strncmp(arr[0], "NO", 3) && !data->map.no.path)
		return (data->map.no.path = content, 0);
	else if (!ft_strncmp(arr[0], "SO", 3) && !data->map.so.path)
		return (data->map.so.path = content, 0);
	else if (!ft_strncmp(arr[0], "WE", 3) && !data->map.we.path)
		return (data->map.we.path = content, 0);
	else if (!ft_strncmp(arr[0], "EA", 3) && !data->map.ea.path)
		return (data->map.ea.path = content, 0);
	return (free(content), err_msg("Problem assigning texture paths"), 1);
}

/**
 * @brief Handle the color identifier
 *
 * @param data the data structure
 * @param line the line to handle
 * @param ident the identifier
 */
static int	handle_color(t_data *data, char **arr)
{
	char	**colors;

	if (arr[2])
		return (err_msg("Invalid identifier"), 1);
	colors = ft_split(arr[1], ',');
	if (!colors)
		return (err_msg("Could not split colors"), 1);
	if (check_colors(data, colors, arr[0]))
		return (free_tab(colors), 1);
	return (free_tab(colors), 0);
}

/**
 * @brief Handle the identifier
 *
 * @param data the data structure
 * @param line the line to handle
 * @return int 0 if success
 */
int	handle_identifier(t_data *data, char *line)
{
	int		ret;
	char	**arr;

	ret = 0;
	arr = ft_split(line, ' ');
	if (!arr)
		return (err_msg("Could not split identifier line"), 1);
	if (!ft_strncmp(arr[0], "NO", 3) || !ft_strncmp(arr[0], "SO", 3)
		|| !ft_strncmp(arr[0], "WE", 3) || !ft_strncmp(arr[0], "EA", 3))
		ret = handle_path(data, arr);
	if (ret)
		return (free_tab(arr), ret);
	if (!ft_strncmp(arr[0], "F", 2) || !ft_strncmp(arr[0], "C", 2))
		ret = handle_color(data, arr);
	return (free_tab(arr), ret);
}
