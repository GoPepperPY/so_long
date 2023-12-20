/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:12:34 by goda-sil          #+#    #+#             */
/*   Updated: 2023/12/20 19:26:23 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_game *play)
{
	int	*width;
	int	*height;

	width = &play->img_width;
	height = &play->img_height;
	play->w_img = mlx_xpm_file_to_image(play->mlx, W_BIND, width, height);
	play->a_img = mlx_xpm_file_to_image(play->mlx, A_BIND, width, height);
	play->s_img = mlx_xpm_file_to_image(play->mlx, S_BIND, width, height);
	play->d_img = mlx_xpm_file_to_image(play->mlx, D_BIND, width, height);
	play->floor_img = mlx_xpm_file_to_image(play->mlx, FLOOR, width, height);
	play->wall_img = mlx_xpm_file_to_image(play->mlx, WALL, width, height);
	play->collect_img = mlx_xpm_file_to_image(play->mlx, COLLECT, \
	width, height);
	play->exit_img = mlx_xpm_file_to_image(play->mlx, EXIT, width, height);
}

void	drawing(t_game *play, void	*image, int x, int y)
{
	x *= 32;
	y *= 32;
	mlx_put_image_to_window(play->mlx, play->window, image, x, y);
}

void	draw_game(t_game *play)
{
	int	counter_one;
	int	counter_two;

	counter_one = -1;
	while (play->map[++counter_one])
	{
		counter_two = -1;
		while (play->map[counter_one][++counter_two])
		{
			if (play->map[counter_one][counter_two] == '0')
				drawing(play, play->floor_img, counter_two, counter_one);
			if (play->map[counter_one][counter_two] == '1')
				drawing(play, play->wall_img, counter_two, counter_one);
			if (play->map[counter_one][counter_two] == 'E')
				drawing(play, play->exit_img, counter_two, counter_one);
			if (play->map[counter_one][counter_two] == 'C')
				drawing(play, play->collect_img, counter_two, counter_one);
			if (play->map[counter_one][counter_two] == 'P')
				drawing(play, play->w_img, counter_two, counter_one);
		}
	}
}

int		handle_hook(int key, t_game *play)
{
	if (key == XK_Escape)
		get_out(play);
	if (key == XK_w || key == XK_Up)
		action_moves('w', play);
	if (key == XK_a || key == XK_Left)
		action_moves('a', play);
	if (key == XK_s || key == XK_Down)
		action_moves('s', play);
	if (key == XK_d || key == XK_Right)
		action_moves('d', play);
	return (0);
}

void	action(t_game *play)
{
	mlx_hook(play->window, KeyPress, KeyPressMask, &handle_hook, play);
	mlx_loop(play->mlx);
}

void	start(t_game *play)
{
	int	rows;
	int	cols;

	rows = play->window_row * 32;
	cols = play->window_col * 32;
	play->mlx = mlx_init();
	load_images(play);
	play->window = mlx_new_window(play->mlx, cols, rows, "so_long");
	draw_game(play);
	action(play);
}
