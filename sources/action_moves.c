/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:48:23 by goda-sil          #+#    #+#             */
/*   Updated: 2023/12/06 15:38:44 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_move_checker(int x, int y, t_game *play)
{
	if (play->map[y][x] == '1')
		return (1);
	return (0);
}

void	body_in_motion(int x, int y, t_game *play)
{
	drawing(play, play->w_img, x, y);
	drawing(play, play->floor_img, play->P_x_start, play->P_y_start);
	play->P_x_start = x;
	play->P_y_start = y;
}

void	action_moves(char c, t_game *play)
{
	int	x;
	int	y;

	x = play->P_x_start;
	y = play->P_y_start;
	
	if (c == 'w' && next_move_checker(x, y - 1, play) == 0)
		body_in_motion(x, y - 1, play);
    if (c == 'a' && next_move_checker(x - 1, y, play) == 0)
        body_in_motion(x - 1, y, play);
    if (c == 's' && next_move_checker(x, y + 1, play) == 0)
        body_in_motion(x, y + 1, play);
    if (c == 'd' && next_move_checker(x + 1, y, play) == 0)
        body_in_motion(x + 1, y, play);
}