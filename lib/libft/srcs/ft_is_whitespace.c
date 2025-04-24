/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:49:46 by cdorig            #+#    #+#             */
/*   Updated: 2025/03/20 14:49:46 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Check if a character is a whitespace
 * @details Check if a character is a whitespace
 *
 * @param c the character to check
 * @return int 1 if c is a whitespace, 0 otherwise
 */
int	ft_is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (0);
	return (1);
}
