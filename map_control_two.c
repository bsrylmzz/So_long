/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:50:31 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/07/16 15:13:15 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_control(t_game *general)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (general->map->mappin[++i])
	{
		while (general->map->mappin[i][++j])
		{
			if (general->map->mappin[i][j] != '0'
				&& general->map->mappin[i][j] != '1'
				&& general->map->mappin[i][j] != 'P'
				&& general->map->mappin[i][j] != 'C'
				&& general->map->mappin[i][j] != 'E')
			{
				write(1, "Haritada Tanimlanamayan Karakter Var\n", 38);
				close_frame(general);
			}
		}
		j = 0;
	}
}

void	coin_control(t_game *general)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (general->map->mappin[++i])
	{
		while (general->map->mappin[i][++j])
		{
			if (general->map->mappin[i][j] == 'C')
			{
				general->map->coin_count++;
			}
		}
		j = 0;
	}
	if (general->map->b_h_count < 1)
	{
		write(1, "En Az Bir Tane Toplanabilir Nesne Olmali\n", 42);
		close_frame(general);
	}
}
