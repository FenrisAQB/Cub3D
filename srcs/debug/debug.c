/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:06:19 by jbarbey           #+#    #+#             */
/*   Updated: 2025/03/20 11:29:01 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Print an array of strings
 * @details Print an array of strings with a why message
 *
 * @param cmd the array of strings
 * @param why the why message
 * @param whyColor the why color
 * @param silent whether to print or not
 */
void	db_str_arr(char **cmd, char *why, char *whyColor, int silent)
{
	int	i;
	int	size;

	if (DEBUG == 0 || silent == 1)
		return ;
	i = 0;
	size = 0;
	while (cmd[size])
		size++;
	if (why && whyColor)
		printf("\t%s%s%s\n", whyColor, why, RES);
	while (cmd[i])
	{
		if (size >= 10 && i < 10)
			printf(" ");
		printf("%s[%d] %s{%s}%s\n", BLUE, i, GREEN, cmd[i], RES);
		i++;
	}
}

/**
 * @brief Print a string
 * @details Print a string with a why message
 *
 * @param s the string
 * @param why the why message
 * @param whyColor the why color
 * @param silent whether to print or not
 */
void	db_str(char *s, char *why, char *whyColor, int silent)
{
	if (DEBUG == 0 || silent == 1)
		return ;
	if (why && whyColor)
		printf("\t%s%s%s ", whyColor, why, RES);
	printf("%s{%s}%s\n", GREEN, s, RES);
}

/**
 * @brief Print a number
 * @details Print a number with a why message
 *
 * @param nbr the number
 * @param why the why message
 * @param whyColor the why color
 * @param silent whether to print or not
 */
void	db_nbr(int nbr, char *why, char *whyColor, int silent)
{
	if (DEBUG == 0 || silent == 1)
		return ;
	if (why && whyColor)
		printf("\t%s%s%s ", whyColor, why, RES);
	printf("%s{%d}%s\n", GREEN, nbr, RES);
}

/**
 * @brief Print a float
 * @details Print a float with a why message
 *
 * @param nbr the float
 * @param why the why message
 * @param whyColor the why color
 * @param silent whether to print or not
 */
void	db_float(float nbr, char *why, char *whyColor, int silent)
{
	if (DEBUG == 0 || silent == 1)
		return ;
	if (why && whyColor)
		printf("\t%s%s%s ", whyColor, why, RES);
	printf("%s{%f}%s\n", GREEN, nbr, RES);
}

/**
 * @brief Print a pointer
 * @details Print a pointer with a why message
 *
 * @param ptr the pointer
 * @param why the why message
 * @param whyColor the why color
 * @param silent whether to print or not
 */
void	db_ptr(void *ptr, char *why, char *whyColor, int silent)
{
	if (DEBUG == 0 || silent == 1)
		return ;
	if (why && whyColor)
		printf("\t%s%s%s ", whyColor, why, RES);
	printf("%s{%p}%s\n", GREEN, ptr, RES);
}
