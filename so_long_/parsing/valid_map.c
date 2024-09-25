/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:26:53 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 06:32:18 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_map **map, int y, int x, int initial)
{
	if (x < 0 || (size_t)x >= (*map)->column_len || y < 0 || \
			(size_t) y >= (*map)->row_len)
		return ;
	if ((*map)->map_dup[y][x] == '1')
		return ;
	if (!initial && (*map)->map_dup[y][x] == 'P')
		return ;
	if (!initial)
		(*map)->map_dup[y][x] = 'P';
	flood_fill (map, y + 1, x, 0);
	flood_fill (map, y - 1, x, 0);
	flood_fill (map, y, x + 1, 0);
	flood_fill (map, y, x - 1, 0);
}

void	verify_valid_path(t_map **map, t_game **game)
{
	int	y;
	int	x;

	start_flood_fill(map);
	y = 0;
	while ((*map)->map_dup && (*map)->map_dup[y])
	{
		x = 0;
		while ((size_t) x < (*map)->column_len)
		{
			if ((*map)->map_dup[y][x] == 'E' || (*map)->map_dup[y][x] == 'C')
			{
				free_dup_map(map);
				error_msg("The map does not have a possible solution", \
				game, map);
			}
			x++;
		}
		y++;
	}
}

void	verify_wall(t_map **map, t_game **game)
{
	size_t	pos_x;
	size_t	pos_y;

	pos_x = 0;
	while (pos_x <= (*map)->column_len - 1)
	{
		if ((*map)->map_readed[0][pos_x] != '1')
			error_msg("Map must be surrounded by walls", game, map);
		pos_x++;
	}
	pos_y = 0;
	while ((pos_y <= (*map)->row_len - 1))
	{
		if ((*map)->map_readed[pos_y][0] != '1' || \
		((*map)->map_readed[pos_y][(*map)->column_len -1] != '1'))
			error_msg("Map must be surrounded by walls", game, map);
		pos_y++;
	}
	pos_x = 0;
	while (pos_x <= (*map)->column_len - 1)
	{
		if ((*map)->map_readed[(*map)->row_len -1][pos_x] != '1')
			error_msg("Map must be surrounded by walls", game, map);
		pos_x++;
	}
}

void	verify_extension(const char *argv, t_game **game, t_map **map)
{
	size_t	len;

	len = ft_strlen(argv);
	if (ft_strnstr(argv, ".ber", len) == 0)
		error_msg("The file is not '.ber' extension", game, map);
}

void	verify_object(t_game **game, t_map **map)
{
	int		collectibles;
	size_t	countx;
	size_t	county;

	county = 0;
	collectibles = 0;
	while (county < (*map)->row_len)
	{
		countx = 0;
		while (countx < (*map)->column_len)
		{
			if ((*map)->map_readed[county][countx] == 'C')
				collectibles++;
			countx++;
		}
		county++;
	}
	(*game)->collec->total_collec = collectibles;
	if (collectibles == 0)
		error_msg("There is not at least one collectable", \
			game, map);
}
