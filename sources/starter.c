/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:12:34 by goda-sil          #+#    #+#             */
/*   Updated: 2023/11/23 11:20:54 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_init(t_game *play)
{
	play->mlx = 0;
	play->window = 0;
}

void	start(t_game *play)
{
	play->mlx = mlx_init();
	play->window = mlx_new_window(play->mlx, 32, 32, "so_long");
}