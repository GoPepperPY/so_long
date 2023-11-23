/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:14:37 by goda-sil          #+#    #+#             */
/*   Updated: 2023/11/23 15:18:53 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <stdlib.h>
#include "../sources/get_next_line/get_next_line.h"

typedef struct s_game{
	void	*mlx;
	void	*window;
	int		window_col;
}	t_game;

void	start_init(t_game *play);
void	start(t_game *play);
void	check_map(t_game *play, char *argv);
int	get_col_number(char *argv);

#endif
