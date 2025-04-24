/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:37:15 by jbarbey           #+#    #+#             */
/*   Updated: 2025/04/03 16:38:56 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Print an error message
 * @details Print an error message in red
 *
 * @param msg the message to print
 */
void	err_msg(char *msg)
{
	ft_putstr_fd(RED, 2);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd(RES, 2);
}

/**
 * @brief Cleanly exit the program
 * @details Free all allocated memory and exit the program
 *
 * @param data the data structure
 * @param status the exit status
 */
void	clean_exit(t_data *data, int status)
{
	destroy_window(data);
	free_textures(data);
	free_tab(data->map.map);
	exit(status);
}

/**
 * @brief Exit the program
 * @details needed for the mouse hook
 *
 * @param data the data structure
 * @return int 0
 */
int	exit_program(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}

/**
 * @brief Print an error message and exit the program
 *
 * @param data the data structure
 * @param msg the message to print
 * @param status the exit status
 * @param code whether to exit or not
 */
void	exit_msg(t_data *data, char *msg, int status, int code)
{
	if (msg)
		err_msg(msg);
	if (code && data)
		clean_exit(data, status);
	else if (code)
		exit(status);
}
