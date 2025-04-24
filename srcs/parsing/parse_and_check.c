/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:37:26 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/03 16:47:46 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Get the content of the file
 * @details Read the file line by line and concatenate the content
 *
 * @param fd the file descriptor
 * @param content the content of the file
 * @return char* the content of the file
 */
static char	*get_file_content(int fd, char *content)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
		return (free(content), close(fd), err_msg("Could not read file"), NULL);
	while (line)
	{
		tmp = ft_strjoin(content, line);
		free(content);
		free(line);
		content = NULL;
		line = NULL;
		if (!tmp)
			return (close(fd), err_msg("Could not allocate memory"), NULL);
		content = tmp;
		line = get_next_line(fd);
	}
	return (content);
}

/**
 * @brief Find the start of the map
 *
 * @param line the line to check
 * @return int 1 if map, 0 if not
 */
static int	is_map_start(char *content)
{
	int	i;
	int	line_start;

	i = 0;
	line_start = 0;
	while (content[i])
	{
		while (content[i] != '\n')
		{
			if (!is_map(content + line_start))
				return (line_start);
			i++;
		}
		if (content[i] == '\n')
			line_start = i + 1;
		i++;
	}
	return (1);
}

/**
 * @brief Check if there are consecutive newlines in map
 *
 * @param content the content of the file
 * @return int 0 if success, 1 if error
 */
static int	empty_lines(char *content)
{
	int	i;

	i = is_map_start(content);
	if (i < 6)
		return (err_msg("Could not identify map"), 1);
	if (is_empty_line(content + i))
		return (1);
	return (0);
}

/**
 * @brief Parse the file
 * @details Open the file, read line by line and split the content
 *
 * @param path the path to the file
 * @return char** the content of the file
 */
static char	**parse_file(char *path)
{
	int		fd;
	char	*content;
	char	*tmp;
	char	**arr;

	arr = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_msg(NULL, "Could not open file", 1, 1);
	content = ft_strdup("");
	if (!content)
		exit_msg(NULL, "Could not allocate memory", 1, 1);
	tmp = get_file_content(fd, content);
	if (!tmp)
		return (free(content), NULL);
	content = tmp;
	db_str(content, "Parsed file\n", BLUE, SILENT);
	close(fd);
	if (!empty_lines(content))
		return (arr = ft_split(content, '\n'), free(content), arr);
	return (free(content), NULL);
}

/**
 * @brief Parse and check the file
 * @details Open the file, read line by line and check the content
 *
 * @param data the data structure
 * @param path the path to the file
 */
void	parse_and_check(t_data *data, char *path)
{
	int		ret;
	char	**arr;

	ret = 0;
	arr = parse_file(path);
	if (!arr)
		exit_msg(NULL, NULL, 1, 1);
	db_str_arr(arr, "Parsed file array", RED, SILENT);
	ret = check_line(data, arr);
	free_tab(arr);
	if (ret)
		exit_msg(data, NULL, 1, 1);
	db_check_parsing(data, "Parsed not checked", BLUE, SILENT);
	check_textures(data);
	check_map_contents(data);
	db_check_parsing(data, "Parsed and checked", RED, 0);
}
