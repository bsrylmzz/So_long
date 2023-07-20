/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:50:48 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/07/10 15:49:23 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	player_control(t_game *general)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	general->map->plyr_count = 0;
	while (general->map->mappin[++i])
	{
		while (general->map->mappin[i][++j])
		{
			if (general->map->mappin[i][j] == 'P')
			{
				general->map->plyr_count += 1;
			}
		}
		j = -1;
	}
	if (general->map->plyr_count != 1)
	{
		write(1, "Sadece Bir Tane Player Olmali\n", 31);
		close_frame(general);
	}
}

void	map_size_control(t_game *general)
{
	int	i;
	int	len;

	i = 0;
	len = general->map->width;
	while (general->map->mappin[i])
	{
		if (str_len(general->map->mappin[i]) != len)
		{
			write(1, "Map Uzunluklari Esit Degil\n", 28);
			close_frame(general);
		}
		i++;
	}
}

void	frame_control(t_game *general)
{
	int	i;
	int	end;

	i = -1;
	while (general->map->mappin[0][++i])
	{
		if (general->map->mappin[0][i] != '1' ||
			general->map->mappin[general->map->height - 1][i] != '1')
		{
			write(1, "Map Cerceve İle Kaplı Degil\n", 28);
			close_frame(general);
		}
	}
	i = -1;
	end = general->map->width -1;
	while (general->map->mappin[++i])
	{
		if (general->map->mappin[i][0] != '1'
			|| general->map->mappin[i][end] != '1')
		{
			write(1, "Map Cerceve İle Kapli Degil\n", 28);
			close_frame(general);
		}
	}
}

void	black_hole_control(t_game *general)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (general->map->mappin[++i])
	{
		while (general->map->mappin[i][++j])
		{
			if (general->map->mappin[i][j] == 'E')
				general->map->b_h_count++;
		}
		j = 0;
	}
	if (general->map->b_h_count != 1)
	{
		write(1, "Sadece Bir Tane Cikis Yolu Olmali\n", 34);
		close_frame(general);
	}
}
