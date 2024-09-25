/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:51:10 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 02:54:58 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(t_game *game)
{
	int	countx;
	int	county;

	county = 0;
	while ((size_t)county < game->map_ref->row_len)
	{
		countx = 0;
		while ((size_t)countx < game->map_ref->column_len)
		{
			if (game->map_ref->map_readed[county][countx] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->textures->lemon_tree_xpm, countx * 72, county * 72);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->textures->backg_xpm, countx * 72, county * 72);
			countx++;
		}
		county++;
	}
}

void	draw_collect(t_game *game)
{
	int	countx;
	int	county;

	county = 0;
	while ((size_t)county < game->map_ref->row_len)
	{
		countx = 0;
		while ((size_t)countx < game->map_ref->column_len)
		{
			if (game->map_ref->map_readed[county][countx] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->textures->heartsnack_xpm, countx * 72, county * 72);
			countx++;
		}
		county++;
	}
}

void	draw_exit(t_game *game)
{
	int	countx;
	int	county;

	county = 0;
	while ((size_t)county < game->map_ref->row_len)
	{
		countx = 0;
		while ((size_t)countx < game->map_ref->column_len)
		{
			if (game->map_ref->map_readed[county][countx] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->textures->exit_house_xpm, countx * 72, county * 72);
			countx++;
		}
		county++;
	}
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->map_ref->main_char.posx * IMG_WIDTH;
	y = game->map_ref->main_char.posy * IMG_HEIGHT;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->textures->dog_xpm, x, y);
}

void	draw_images(t_game *game)
{
	draw_background(game);
	draw_collect(game);
	draw_exit(game);
	draw_player(game);
}
