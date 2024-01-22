/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:15:43 by goda-sil          #+#    #+#             */
/*   Updated: 2024/01/15 12:17:17 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init(t_game *play)
{
	play->c_numbers = 0;
	play->e_numbers = 0;
	play->p_numbers = 0;
	play->img_width = 32;
	play->img_height = 32;
	play->collected = 0;
	play->moves = 0;
}

int	check_arguments(char *argv)
{
	int	length;

	length = ft_strlen(argv);
	if (argv[length - 4] != '.')
		return (0);
	if (argv[length - 3] != 'b')
		return (0);
	if (argv[length - 2] != 'e')
		return (0);
	if (argv[length - 1] != 'r')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	play;

	if (argc == 2)
	{
		if (check_arguments(argv[1]) == 0)
		{
			ft_printf("Invalid extension!\n");
			return (0);
		}
		init(&play);
		check_map(&play, argv[1]);
		start(&play);
	}
}
