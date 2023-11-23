/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:15 by goda-sil          #+#    #+#             */
/*   Updated: 2023/11/23 15:47:15 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void initialise_map(t_game *play, char *argv)
{
	
}

void	check_map(t_game *play, char *argv)
{
	play->window_col = get_lines_number(argv);
	initialise_map(play, argv);
}