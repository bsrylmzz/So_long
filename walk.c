/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:51:54 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/07/16 15:13:47 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putchr(t_game *general, int keycode)
{
	if (keycode == KEY_D)
		general->chr->chr_chr = general->chr->chr_right;
	if (keycode == KEY_A)
		general->chr->chr_chr = general->chr->chr_left;
	if (keycode == KEY_W)
		general->chr->chr_chr = general->chr->chr_back;
	if (keycode == KEY_S)
		general->chr->chr_chr = general->chr->chr_front;
}

void	print_score(t_game *general)
{
	ft_printf("%d\n", general->chr->point);
}

void	move_p(t_game *general, int side, int x, int y)
{
	if (general->map->coin_count == 0 && general->map->mappin[y / 64]
		[x / 64] == 'E')
	{
		general->chr->point += 1;
		print_score(general);
		write(1, "Kazandiinn!", 13);
		close_frame(general);
	}
	if (general->map->mappin[y / 64][x / 64] != '1'
		&& general->map->mappin[y / 64][x / 64] != 'E')
	{
		putchr(general, side);
		general->chr->point += 1;
		if (general->map->mappin[y / 64][x / 64] == 'C')
			general->map->coin_count -= 1;
		general->map->mappin[general->chr->loc_y / 64]
		[general->chr->loc_x / 64] = '0';
		general->map->mappin[general->map->loc_end_y / 64]
		[general->map->loc_end_x / 64] = 'E';
		general->map->mappin[y / 64][x / 64] = 'P';
		print_score(general);
	}
}

int	walk(int keycode, t_game *general)
{
	mlx_clear_window(general->mlx, general->window);
	if (keycode == KEY_D)
		move_p(general, keycode, general->chr->loc_x + 64, general->chr->loc_y);
	if (keycode == KEY_A)
		move_p(general, keycode, general->chr->loc_x - 64, general->chr->loc_y);
	if (keycode == KEY_W)
		move_p(general, keycode, general->chr->loc_x, general->chr->loc_y - 64);
	if (keycode == KEY_S)
		move_p(general, keycode, general->chr->loc_x, general->chr->loc_y + 64);
	if (keycode == KEY_ESC)
		close_frame(general);
	screen_print(general);
	return (keycode);
}
