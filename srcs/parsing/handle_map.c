/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:25:35 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/11 19:11:37 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Get the size of the map
 *
 * @param data the data structure
 * @param arr the map
 */
static void	get_map_size(t_data *data, char **arr, int i)
{
	int	height;
	int	len;

	len = 0;
	height = 0;
	while (arr[i])
	{
		if ((int)ft_strlen(arr[i]) > len)
			len = ft_strlen(arr[i]);
		height++;
		i++;
	}
	data->map.map_width = len;
	data->map.map_height = height;
}

/**
 * @brief Handle the map assignation
 *
 * @param data the data structure
 * @param arr the map
 * @param i the index of the map
 * @return int 0 if success, 1 if error
 */
int	handle_map(t_data *data, char **arr, int i)
{
	char	**tmp;
	int		j;
	int		k;

	k = 0;
	get_map_size(data, arr, i);
	tmp = ft_calloc(data->map.map_height + 1, sizeof(char *));
	if (!tmp)
		return (err_msg("Could not allocate memory"), 1);
	while (arr[i])
	{
		j = 0;
		tmp[k] = ft_calloc(data->map.map_width + 1, sizeof(char));
		if (!tmp[k])
			return (free_tab(tmp), err_msg("Could not allocate memory"), 1);
		while (arr[i][j])
		{
			tmp[k][j] = arr[i][j];
			j++;
		}
		tmp[k++][j] = '\0';
		i++;
	}
	return (tmp[k] = NULL, data->map.map = tmp, 0);
}
