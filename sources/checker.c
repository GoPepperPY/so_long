/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:43 by goda-sil          #+#    #+#             */
/*   Updated: 2024/01/03 15:09:58 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_is_rectangular(t_game *play)
{
	int	counter_one;
	int	temporary;

	temporary = ft_strlen(play->map[0]);
	counter_one = 0;
	while (play->map[counter_one])
	{
		if ((int)ft_strlen(play->map[counter_one]) != temporary)
			return (1);
		counter_one++;
	}
	return (0);
}

int	map_wall_escape(t_game *play)
{
	int	counter_one;

	counter_one = -1;
	while (play->map[0][++counter_one])
	{
		if (play->map[0][counter_one] != '1')
			return (1);
	}
	counter_one = 0;
	while (++counter_one < play->window_row)
	{
		if (play->map[counter_one][0] != '1' || play->map[counter_one] \
		[play->window_col - 1] != '1')
			return (1);
	}
	counter_one = -1;
	while (play->map[play->window_row - 1][++counter_one])
	{
		if (play->map[play->window_row - 1][counter_one] != '1')
			return (1);
	}
	return (0);
}

int	check_the_intruder(t_game	*play)
{
	int	counter_one;
	int	counter_two;

	counter_one = -1;
	while (play->map[++counter_one])
	{
		counter_two = -1;
		while (play->map[counter_one][++counter_two])
		{
			if (play->map[counter_one][counter_two] != '1' && play->map \
			[counter_one][counter_two] != '0' && play->map[counter_one] \
			[counter_two] != 'P' && play->map[counter_one][counter_two] != 'E' \
			&& play->map[counter_one][counter_two] != 'C')
				return (1);
		}
	}
	return (0);
}

int	everything_needed(t_game *play)
{
	int	counter_one;
	int	counter_two;

	counter_one = -1;
	while (play->map[++counter_one])
	{
		counter_two = -1;
		while (play->map[counter_one][++counter_two])
		{
			if (play->map[counter_one][counter_two] == 'E')
				play->E_numbers++;
			if (play->map[counter_one][counter_two] == 'C')
				play->C_numbers++;
			if (play->map[counter_one][counter_two] == 'P')
				play->P_numbers++;
		}
	}
	if (play->C_numbers == 0 || play->E_numbers == 0 || play->P_numbers == 0)
		return (1);
	if (play->P_numbers != 1)
	{
		free_map(play->map, play);
		exit (1);
	}
	return (0);
}

int	handle_exit(t_game *play)
{
	get_out(play);
	exit(0);
}

void	action(t_game *play)
{
	mlx_hook(play->window, KeyPress, KeyPressMask, &handle_hook, play);
	mlx_hook(play->window, DestroyNotify, ButtonPressMask, &handle_exit, play);
	mlx_loop(play->mlx);
}
