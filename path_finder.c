/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyilmaz <buyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:51:16 by buyilmaz          #+#    #+#             */
/*   Updated: 2023/07/16 17:28:18 by buyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	recur_func(char **vmap, t_map *map, int x, int y)
{
	if (vmap[y][x] == 'C' || vmap[y][x] == 'P')
		map->read_count++;
	vmap[y][x] = '1';
	if (vmap[y + 1][x] != '1')
		recur_func(vmap, map, x, y + 1);
	if (vmap[y][x + 1] != '1')
		recur_func(vmap, map, x + 1, y);
	if (vmap[y - 1][x] != '1')
		recur_func(vmap, map, x, y - 1);
	if (vmap[y][x - 1] != '1')
		recur_func(vmap, map, x - 1, y);
	return (1);
}

static void	free_double_array(char **vmap, t_game *general)
{
	int	i;

	i = -1;
	while (++i < general->height / 64)
		free(vmap[i]);
	free(vmap);
}

void	placeholder(t_game *general, int x, int y)
{
	char	**vmap;
	int		i;
	int		j;

	i = -1;
	j = -1;
	vmap = malloc(sizeof(char *) * general->height / 64);
	while (++i < general->height / 64)
	{
		vmap[i] = malloc(sizeof(char) * general->width / 64);
		j = -1;
		while (++j < general->width / 64)
			vmap[i][j] = general->map->mappin[i][j];
	}
	recur_func(vmap, general->map, x, y);
	if (general->map->read_count != general->map->coin_count + 1)
	{
		write(1, "Harita Tamamlanabilir Degil..\n", 32);
		exit (1);
	}
	free_double_array(vmap, general);
}
