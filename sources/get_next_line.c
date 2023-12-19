/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:34:47 by goda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 20:18:52 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// fd(file descriptor) - abstract indicator to indicate a file
// storage - it's where will store our temporary data
// when read returns 0 means that there is not more data

char	*read_file(int fd, char	*storage)
{
	char	*temporary;
	char	*temp;
	int		read_bytes;

	read_bytes = 1;
	temporary = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (!ft_strchr(storage, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, temporary, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temporary);
			return (NULL);
		}
		temp = storage;
		temporary[read_bytes] = '\0';
		storage = ft_strjoin(storage, temporary);
		free(temp);
	}
	free(temporary);
	return (storage);
}

char	*clear(char *storage)
{
	int		counter;
	char	*line;

	counter = 0;
	if (!storage[counter])
		return (NULL);
	while (storage[counter] && storage[counter] != '\n')
		counter++;
	line = ft_calloc((counter + 2), sizeof(char));
	counter = -1;
	while (storage[++counter] && storage[counter] != '\n')
		line[counter] = storage[counter];
	line[counter] = storage[counter];
	return (line);
}

char	*stash(char *storage)
{
	int		counter_one;
	int		counter_two;
	char	*string;

	counter_one = 0;
	while (storage[counter_one] && storage[counter_one] != '\n')
		counter_one++;
	if (!storage[counter_one])
	{
		free(storage);
		return (NULL);
	}
	string = ft_calloc((ft_strlen(storage) - counter_one + 1), sizeof(char));
	counter_one++;
	counter_two = 0;
	while (storage[counter_one])
		string[counter_two++] = storage[counter_one++];
	free(storage);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!storage)
		storage = ft_calloc(1, sizeof(char));
	storage = read_file(fd, storage);
	if (!storage)
		return (NULL);
	line = clear(storage);
	storage = stash(storage);
	return (line);
}
