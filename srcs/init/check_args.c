/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:58:29 by cdorig            #+#    #+#             */
/*   Updated: 2025/03/20 10:58:29 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Check the arguments for validity
 * @details Check the number of arguments, if the file exists
 * 			and if the file extension is .cub
 * @param ac the number of arguments
 * @param av the arguments
 */
void	check_args(int ac, char **av)
{
	int		fd;
	int		bytes_read;
	char	*buff;

	if (ac != 2)
		exit_msg(NULL, "Use : ./cub3D [path to .cub file]", 1, 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_msg(NULL, "Unable to read file or file not found", 1, 1);
	bytes_read = read(fd, &buff, 5);
	if (bytes_read < 0)
		exit_msg(NULL, "Unable to read file", 1, 1);
	if (bytes_read == 0)
		exit_msg(NULL, "File is empty", 1, 1);
	close(fd);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		exit_msg(NULL, "Invalid file extension, use .cub", 1, 1);
}
