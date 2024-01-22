/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:14:37 by goda-sil          #+#    #+#             */
/*   Updated: 2024/01/15 11:49:12 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_game{
	void	*mlx;
	void	*window;
	int		window_col;
	int		window_row;
	char	**map;
	int		c_numbers;
	int		e_numbers;
	int		p_numbers;
	int		p_x_start;
	int		p_y_start;
	char	**temp_map;
	void	*w_img;
	void	*a_img;
	void	*s_img;
	void	*d_img;
	void	*wall_img;
	void	*floor_img;
	void	*collect_img;
	void	*exit_img;
	int		img_height;
	int		img_width;
	int		collected;
	int		moves;
}	t_game;

# define W_BIND "./images/player.xpm"
# define S_BIND "./images/player.xpm"
# define A_BIND "./images/player.xpm"
# define D_BIND "./images/player.xpm"
# define COLLECT "./images/collectible.xpm"
# define FLOOR "./images/floor.xpm"
# define WALL "./images/wall.xpm"
# define EXIT "./images/exit.xpm"

/* Define keys: */
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

void	start(t_game *play);
void	check_map(t_game *play, char *argv);
void	attribute_char_map(t_game *play, char *argv);
void	map_viability_checker(t_game *play);
void	*ft_calloc(size_t	nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	init(t_game *play);
void	find_p(t_game *play);
void	the_way_out(t_game *play, char *argv);
void	init_temp_map(t_game *play, char *argv);
void	load_images(t_game *play);
void	draw_game(t_game *play);
void	drawing(t_game *play, void	*image, int x, int y);
void	action(t_game *play);
void	action_moves(char c, t_game *play);
void	body_in_motion(int x, int y, t_game *play);
void	get_out(t_game *play);
void	free_map(char **map, t_game *play);

// int		get_cols_number(char *argv);
int		get_line_number(char *argv);
int		map_is_rectangular(t_game *play);
int		map_wall_escape(t_game *play);
int		check_the_intruder(t_game	*play);
int		everything_needed(t_game *play);
int		identify_flag(va_list	argument, const char type);
int		ft_printf(const char *input, ...);
int		print_string(char *string);
int		print_decimal_integer(long number);
int		print_decimal_unsigned(unsigned int number);
int		print_hex(unsigned int number, char type);
int		put_hex(unsigned int number, char type);
int		pointer_length(unsigned long long pointer);
int		print_pointer_two(unsigned long long pointer);
int		print_pointer(unsigned long long pointer);
int		the_way_out_extension(t_game *play, char **map, int x, int y);
int		handle_hook(int key, t_game *play);
int		next_move_checker(int x, int y, t_game *play);
int		handle_exit(t_game *play);

char	*read_file(int fd, char *storage);
char	*clear(char *storage);
char	*stash(char *storage);
char	*get_next_line(int fd);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);

#endif
