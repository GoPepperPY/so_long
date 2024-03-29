/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:31:43 by goda-sil          #+#    #+#             */
/*   Updated: 2024/01/15 12:34:54 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_p(t_game *play)
{
	int	counter_one;
	int	counter_two;

	counter_one = -1;
	while (play->map[++counter_one])
	{
		counter_two = -1;
		while (play->map[counter_one][++counter_two])
		{
			if (play->map[counter_one][counter_two] == 'P')
			{
				play->p_x_start = counter_two;
				play->p_y_start = counter_one;
			}
		}
	}
}

void	init_temp_map(t_game *play, char *argv)
{
	char	*line;
	int		counter;
	int		file;

	counter = 0;
	line = 0;
	play->temp_map = (char **)malloc(sizeof(char *) * (play->window_row + 1));
	file = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(file);
		if (!line)
		{
			free(line);
			break ;
		}
		play->temp_map[counter] = ft_strtrim(line, "\n");
		free(line);
		counter++;
	}
	play->temp_map[counter] = 0;
	close(file);
}

int	the_way_out_extension(t_game *play, char **map, int x, int y)
{
	static int	collects;
	static int	exits;

	if (y < 0 || x < 0 || y > play->window_row || x > play->window_col
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{
		exits++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		collects++;
	map[y][x] = 'X';
	the_way_out_extension(play, map, x + 1, y);
	the_way_out_extension(play, map, x - 1, y);
	the_way_out_extension(play, map, x, y + 1);
	the_way_out_extension(play, map, x, y - 1);
	if (exits == 1 && collects == play->c_numbers)
		return (1);
	return (0);
}

int	handle_exit(t_game *play)
{
	get_out(play);
	exit(0);
}

void	the_way_out(t_game *play, char *argv)
{
	init_temp_map(play, argv);
	if (the_way_out_extension(play, play->temp_map, play->p_x_start, \
	play->p_y_start) == 0)
	{
		free_map(play->map, play);
		free_map(play->temp_map, play);
		ft_printf("Can't start the game!\n");
		exit (0);
	}
}
