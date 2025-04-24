/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:06:25 by jbarbey           #+#    #+#             */
/*   Updated: 2025/04/15 10:07:05 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG 0
# define SILENT 1
# define RES "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BGREEN "\033[1;32m"
# define BLUE "\033[0;34m"
# define BBLUE "\033[1;34m"
# define FOXMOJI "🦊🐾🦔"

typedef struct s_data	t_data;

// debug.c
void	db_str_arr(char **cmd, char *why, char *whyColor, int silent);
void	db_str(char *s, char *why, char *whyColor, int silent);
void	db_nbr(int nbr, char *why, char *whyColor, int silent);
void	db_float(float nbr, char *why, char *whyColor, int silent);
void	db_ptr(void *ptr, char *why, char *whyColor, int silent);

// debug_more.c
void	db_check_parsing(t_data *data, char *why, char *whyColor, int silent);
void	db_hex(int nbr, char *why, char *whyColor, int silent);

#endif
