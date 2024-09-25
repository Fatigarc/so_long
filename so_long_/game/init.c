/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:15:20 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 03:01:03 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_window(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		(game->map_ref->column_len * IMG_WIDTH), \
		(game->map_ref->row_len * IMG_HEIGHT), "So_Long");
	game->player.steps = 0;
	game->collec->items = 0;
}

void	init_images(t_game *game, t_map **map)
{
	int	x;
	int	y;

	game->textures->lemon_tree_xpm = \
		mlx_xpm_file_to_image(game->mlx_ptr, WALL, &x, &y);
	game->textures->heartsnack_xpm = \
		mlx_xpm_file_to_image(game->mlx_ptr, SNACK, &x, &y);
	game->textures->backg_xpm = \
		mlx_xpm_file_to_image(game->mlx_ptr, BACKGROUND, &x, &y);
	game->textures->dog_xpm = \
		mlx_xpm_file_to_image(game->mlx_ptr, BORDER_COLLIE, &x, &y);
	game->textures->exit_house_xpm = \
		mlx_xpm_file_to_image(game->mlx_ptr, EXIT_HOUSE, &x, &y);
	error_creating_img(&game, map);
}
