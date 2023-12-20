/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:15:43 by goda-sil          #+#    #+#             */
/*   Updated: 2023/12/20 18:29:37 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init(t_game *play)
{
	play->C_numbers = 0;
	play->E_numbers = 0;
	play->P_numbers = 0;
	play->img_width = 32;
	play->img_height = 32;
	play->collected = 0;
}

int	main(int argc, char **argv)
{
	t_game	play;

	(void) argc;
	init(&play);
	check_map(&play, argv[1]);
	start(&play);
}
