/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:02:42 by cdorig            #+#    #+#             */
/*   Updated: 2025/03/23 18:49:01 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	ret = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!ret)
		return (free(s1), s1 = NULL, NULL);
	while (s1[j])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	return (free(s1), s1 = NULL, ret);
}

char	*read_loop(int fd, char *ret, char *buff)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, 1);
		if (bytes_read < 0)
			return (free(ret), ret = NULL, NULL);
		buff[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		tmp = ft_strjoin_gnl(ret, buff);
		if (!tmp)
			return (NULL);
		ret = tmp;
		if (ft_strchr(ret, '\n'))
			break ;
	}
	if (bytes_read == 0 && !ft_strlen(ret))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char	buff[2];
	char	*ret;
	char	*tmp;

	ret = ft_strdup("");
	if (!ret)
		return (NULL);
	tmp = read_loop(fd, ret, buff);
	if (!tmp)
		return (NULL);
	ret = tmp;
	return (ret);
}*/

void	update_buffer_and_line(char buffer[101], char *line)
{
	char	*nl;

	nl = ft_strchr(line, '\n');
	if (nl)
	{
		ft_strlcpy(buffer, nl + 1, ft_strlen(nl));
		*(nl + 1) = '\0';
	}
	else
		buffer[0] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[101];
	char		*line;
	char		*temp;
	int			by_read;

	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		by_read = read(fd, buffer, 100);
		if (by_read <= 0)
			break ;
		buffer[by_read] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (!line)
			return (NULL);
	}
	update_buffer_and_line(buffer, line);
	if (!line || !ft_strlen(line))
		return (free(line), NULL);
	return (line);
}
