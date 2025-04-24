/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:18:21 by cdorig            #+#    #+#             */
/*   Updated: 2025/03/20 22:18:21 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Free the textures
 *
 * @param data the data structure
 */
void	free_textures(t_data *data)
{
	if (data->map.no.path)
		free(data->map.no.path);
	if (data->map.so.path)
		free(data->map.so.path);
	if (data->map.we.path)
		free(data->map.we.path);
	if (data->map.ea.path)
		free(data->map.ea.path);
}

/**
 * @brief Free a tab
 *
 * @param tab the tab to free
 */
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab);
}
