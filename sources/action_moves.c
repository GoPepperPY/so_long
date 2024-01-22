/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:48:23 by goda-sil          #+#    #+#             */
/*   Updated: 2024/01/15 11:52:00 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_move_checker(int x, int y, t_game *play)
{
	if (play->map[y][x] == '1')
		return (1);
	if (play->map[y][x] == 'C')
	{
		play->collected++;
		play->map[y][x] = '0';
	}
	if (play->map[y][x] == 'E')
	{
		if (play->collected == play->c_numbers)
			get_out(play);
		else
			return (1);
	}
	return (0);
}

void	free_map(char **map, t_game *play)
{
	int	counter;

	counter = 0;
	while (counter < play->window_row)
	{
		free(map[counter]);
		counter++;
	}
	free(map);
}

void	get_out(t_game *play)
{
	free_map(play->temp_map, play);
	free_map(play->map, play);
	mlx_destroy_image(play->mlx, play->w_img);
	mlx_destroy_image(play->mlx, play->a_img);
	mlx_destroy_image(play->mlx, play->s_img);
	mlx_destroy_image(play->mlx, play->d_img);
	mlx_destroy_image(play->mlx, play->exit_img);
	mlx_destroy_image(play->mlx, play->collect_img);
	mlx_destroy_image(play->mlx, play->floor_img);
	mlx_destroy_image(play->mlx, play->wall_img);
	mlx_destroy_window(play->mlx, play->window);
	mlx_destroy_display(play->mlx);
	free(play->mlx);
	exit(0);
}

void	body_in_motion(int x, int y, t_game *play)
{
	drawing(play, play->w_img, x, y);
	drawing(play, play->floor_img, play->p_x_start, play->p_y_start);
	play->moves++;
	ft_printf("MOVES: %d\n", play->moves);
	play->p_x_start = x;
	play->p_y_start = y;
}

void	action_moves(char c, t_game *play)
{
	int	x;
	int	y;

	x = play->p_x_start;
	y = play->p_y_start;
	if (c == 'w' && next_move_checker(x, y - 1, play) == 0)
		body_in_motion(x, y - 1, play);
	if (c == 'a' && next_move_checker(x - 1, y, play) == 0)
		body_in_motion(x - 1, y, play);
	if (c == 's' && next_move_checker(x, y + 1, play) == 0)
		body_in_motion(x, y + 1, play);
	if (c == 'd' && next_move_checker(x + 1, y, play) == 0)
		body_in_motion(x + 1, y, play);
}
