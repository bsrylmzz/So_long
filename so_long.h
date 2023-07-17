/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:26:40 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/07/16 15:18:24 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

typedef struct s_chr
{
	int		loc_x;
	int		loc_y;
	int		point;
	void	*chr_front;
	void	*chr_back;
	void	*chr_left;
	void	*chr_right;
	void	*chr_chr;
}	t_chr;

typedef struct s_map
{
	char	**mappin;
	int		height;
	int		width;
	int		coin_count;
	int		plyr_count;
	int		b_h_count;
	int		loc_end_x;
	int		loc_end_y;
	int		read_count;
	int		r;
	int		b;
	int		l;
	int		t;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	t_chr	*chr;
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	void	*black_hole;
	void	*wall;
	void	*coin;
	void	*path;
}	t_game;

void	character_control(t_game *general);
void	player_control(t_game *general);
void	map_size_control(t_game *general);
void	frame_control(t_game *general);
void	black_hole_control(t_game *general);
void	coin_control(t_game *general);
void	map_empty_control(char *argv_incoming);
void	map_ber_control(char *argv_incoming);
void	map_file_control(char *argv_incoming);
char	*read_file(char *argv_incoming);
t_map	*read_map(char *argv_incoming);
void	put_element(char c, t_game *general, int x, int y);
void	put_score(t_game *general);
void	screen_print(t_game *general);
void	open_windows(t_game *general, char *argv_incoming);
void	putchr(t_game *pnc, int keycode);
void	print_score(t_game *pnc);
void	move_p(t_game *pnc, int side, int x, int y);
int		walk(int keycode, t_game *general);
void	get_image(t_game *general, int x, int y);
void	xpm_control_obje(void);
void	xpm_control_character(void);
int		close_frame(void *deneme);
int		str_len(char *str);
void	put_element_one(char c, t_game *general, int x, int y);
void	placeholder(t_game *general, int x, int y);
#endif
