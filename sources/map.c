/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:15 by goda-sil          #+#    #+#             */
/*   Updated: 2023/12/04 20:22:17 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check if is everything good with the map
void	map_viability_checker(t_game *play)
{
	if (map_is_rectangular(play) == 1)
	{
		ft_printf("The lines must be the same length!\n");
		exit(1);
	}
	if (map_wall_escape(play) == 1)
	{
		ft_printf("Missing bricks in the border!\n");
		exit(1);
	}
	if (check_the_intruder(play) == 1)
	{
		ft_printf("Intruder!\n");
		exit(1);
	}
	if (everything_needed(play) == 1)
	{
		ft_printf("Missing material!\n");
		exit(1);
	}
}

// writing the character of the items to the map array
void	attribute_char_map(t_game *play, char *argv)
{
	char	*line;
	int		counter;
	int		file;

	counter = 0;
	line = 0;
	play->map = (char **)malloc(sizeof(char *) * (play->window_row + 1));
	file = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(file);
		if (!line)
		{
			free(line);
			break ;
		}
		play->map[counter] = ft_strtrim(line, "\n");
		free(line);
		counter++;
	}
	play->map[counter] = 0;
	close(file);
}

// initializate the map
void	check_map(t_game *play, char *argv)
{
	play->window_row = get_line_number(argv);
	attribute_char_map(play, argv);
	play->window_col = ft_strlen(play->map[0]);
	map_viability_checker(play);
	find_p(play);
	the_way_out(play, argv);
}
