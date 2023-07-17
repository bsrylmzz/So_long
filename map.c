/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:51:06 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/07/16 18:27:28 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_element_one(char c, t_game *general, int x, int y)
{
	mlx_put_image_to_window(general->mlx, general->window, general->path, x, y);
	if (c == 'P')
	{
		general->chr->loc_x = x;
		general->chr->loc_y = y;
		mlx_put_image_to_window(general->mlx, general->window,
			general->chr->chr_chr, x, y);
	}
	if (c == '1')
		mlx_put_image_to_window(general->mlx, general->window,
			general->wall, x, y);
}

void	put_element(char c, t_game *general, int x, int y)
{
	put_element_one(c, general, x, y);
	if (c == 'C')
	{
		mlx_put_image_to_window(general->mlx, general->window,
			general->coin, x, y);
	}
	if (c == 'E')
	{
		general->map->loc_end_x = x;
		general->map->loc_end_y = y;
		mlx_put_image_to_window(general->mlx, general->window,
			general->black_hole, x, y);
	}
}

void	put_score(t_game *general)
{
	char	*score;

	score = ft_itoa(general->chr->point);
	mlx_string_put(general->mlx, general->window, 20, 20, 0xFFFFFFFF, score);
	free(score);
}

void	screen_print(t_game *general)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (general->map->mappin[i])
	{
		j = 0;
		x = 0;
		while (general->map->mappin[i][j])
		{
			put_element(general->map->mappin[i][j], general, x, y);
			put_score(general);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}
}
