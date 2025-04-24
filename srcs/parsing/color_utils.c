/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:59:30 by cdorig            #+#    #+#             */
/*   Updated: 2025/03/27 16:32:05 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Check if the content is an integer
 * @details Check if the content is an integer by converting it to an int
 * 			and back to a string and comparing the strings
 *
 * @param content the content to check
 * @return int 1 if integer, 0 if not
 */
static int	check_int(char *content)
{
	int		tmp;
	int		i;
	char	*test;

	i = 0;
	while (content[i])
	{
		if (!ft_isdigit(content[i]) || content[i] == '+')
			return (err_msg("Wrong characters in colors"), 1);
		i++;
	}
	tmp = ft_atoi(content);
	test = ft_itoa(tmp);
	if (!test)
		return (err_msg("Problem allocating in int test"), 1);
	if (tmp < 0 || tmp > 255)
		return (err_msg("Color out of range"), free(test), 1);
	if (!ft_strncmp(content, test, ft_strlen(test)))
		return (free(test), 0);
	return (err_msg("Wrong content for rgb codes"), free(test), 1);
}

/**
 * @brief Assign the color to the data structure
 *
 * @param data the data structure
 * @param colors the colors to assign
 * @param ident the identifier
 */
static void	assign_colors(t_data *data, char **colors, char *ident)
{
	int	r;
	int	g;
	int	b;
	int	rgb;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	rgb = (r << 16) | (g << 8) | b;
	if (!ft_strncmp(ident, "F", 2) && data->map.f.color == -1)
		data->map.f.color = rgb;
	else if (!ft_strncmp(ident, "C", 2) && data->map.c.color == -1)
		data->map.c.color = rgb;
}

/**
 * @brief Check the colors
 *
 * @param data the data structure
 * @param colors the colors to check
 * @param ident the identifier
 * @return int 1 if success, 0 if fail
 */
int	check_colors(t_data *data, char **colors, char *ident)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (check_int(colors[i]))
			return (1);
		i++;
	}
	if (i != 3)
		return (err_msg("Not RGB"), 1);
	assign_colors(data, colors, ident);
	return (0);
}
