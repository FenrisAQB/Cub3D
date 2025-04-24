/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:20:59 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/03 16:46:19 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Check if line starts with an identifier
 *
 * @param line the line to check
 * @return int 1 if identifier, 0 if not
 */
static int	is_identifier(char *line)
{
	if (((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
				|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
			&& !ft_is_whitespace(line[2])) || ((!ft_strncmp(line, "C", 1)
				|| !ft_strncmp(line, "F", 1)) && !ft_is_whitespace(line[1])))
		return (0);
	return (1);
}

/**
 * @brief Check if there are consecutive newlines or empty lines in map
 *
 * @param content the content of the file
 * @return int 0 if success, 1 if error
 */
int	is_empty_line(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
		{
			if (content[i + 1] == '\n')
				return (err_msg("Empty lines in map"), 1);
			while (content[i] != '\n')
			{
				if (ft_is_whitespace(content[i]))
					i++;
				else
					return (err_msg("Empty lines in map"), 1);
			}
		}
		i++;
	}
	return (0);
}

/**
 * @brief Check if line is a map
 *
 * @param line the line to check
 * @return int 0 if map, 1 if not
 */
int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr(MAP_CHARS, line[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

/**
 * @brief Check the line and handle it
 *
 * @param data the data structure
 * @param line the line to check
 * @return int 0 if empty, 1 if identifier, 2 if map, -1 if invalid
 */
int	check_line(t_data *data, char **arr)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (arr[i])
	{
		db_str(arr[i], "Line to check", RED, SILENT);
		if (!is_identifier(arr[i]))
		{
			ret = handle_identifier(data, arr[i]);
			if (ret)
				return (ret);
		}
		else if (!is_map(arr[i]))
		{
			ret = handle_map(data, arr, i);
			break ;
		}
		else
			return (err_msg("Invalid line"), 1);
		i++;
	}
	return (ret);
}
