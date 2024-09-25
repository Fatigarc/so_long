/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:49:53 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 07:42:14 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_end_game(t_game *game, int x, int y)
{
	if (game->collec->items == game->collec->total_collec
		&& game->map_ref->map_readed[y][x] == 'E')
	{
		ft_printf(WINS);
		close_game(game);
	}
}

void	move_up(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->map_ref->main_char.posx;
	y = game->map_ref->main_char.posy;
	if (map->map_readed[y - 1][x] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures->backg_xpm, x * 72, y * 72);
		if (map->map_readed[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->textures->exit_house_xpm, x * 72, y * 72);
		game->map_ref->main_char.posy--;
		y--;
		if (map->map_readed[y][x] == 'C')
		{
			map->map_readed[y][x] = '0';
			game->collec->items++;
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures->dog_xpm, x * 72, y * 72);
		game->player.steps++;
		ft_printf("Moves: %d\n", game->player.steps);
		check_end_game(game, x, y);
	}
}

void	move_down(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->map_ref->main_char.posx;
	y = game->map_ref->main_char.posy;
	if (map->map_readed[y + 1][x] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures->backg_xpm, x * 72, y * 72);
		if (map->map_readed[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->textures->exit_house_xpm, x * 72, y * 72);
		game->map_ref->main_char.posy++;
		y++;
		if (map->map_readed[y][x] == 'C')
		{
			map->map_readed[y][x] = '0';
			game->collec->items++;
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures->dog_xpm, x * 72, y * 72);
		game->player.steps++;
		ft_printf("Moves: %d\n", game->player.steps);
		check_end_game(game, x, y);
	}
}

void	move_right(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->map_ref->main_char.posx;
	y = game->map_ref->main_char.posy;
	if (map->map_readed[y][x + 1] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures->backg_xpm, x * 72, y * 72);
		if (map->map_readed[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->textures->exit_house_xpm, x * 72, y * 72);
		game->map_ref->main_char.posx++;
		x++;
		if (map->map_readed[y][x] == 'C')
		{
			map->map_readed[y][x] = '0';
			game->collec->items++;
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures->dog_xpm, x * 72, y * 72);
		game->player.steps++;
		ft_printf("Moves: %d\n", game->player.steps);
		check_end_game(game, x, y);
	}
}

void	move_left(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->map_ref->main_char.posx;
	y = game->map_ref->main_char.posy;
	if (map->map_readed[y][x - 1] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures->backg_xpm, x * 72, y * 72);
		if (map->map_readed[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->textures->exit_house_xpm, x * 72, y * 72);
		game->map_ref->main_char.posx--;
		x--;
		if (map->map_readed[y][x] == 'C')
		{
			map->map_readed[y][x] = '0';
			game->collec->items++;
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures->dog_xpm, x * 72, y * 72);
		game->player.steps++;
		ft_printf("Moves: %d\n", game->player.steps);
		check_end_game(game, x, y);
	}
}
