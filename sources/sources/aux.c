/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:47:15 by goda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 16:42:53 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// return line numbers of the map
int	get_line_number(char *argv)
{
	char	*line;
	int		counter;
	int		file;

	counter = 0;
	file = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(file);
		if (line == NULL)
			break ;
		free(line);
		counter++;
	}
	free(line);
	close(file);
	return (counter);
}
