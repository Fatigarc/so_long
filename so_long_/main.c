/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:03:22 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 06:19:07 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux1/mlx.h"
#include "so_long.h"
#include <fcntl.h>

void	close_game(t_game *game)
{
	destroy_all_img(&game, game->textures);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

void	start_game(t_game *game)
{
	int	y;
	int	x;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return ;
	mlx_get_screen_size(game->mlx_ptr, &x, &y);
	if ((size_t)x < (game->map_ref->column_len * 72)
		|| (size_t)y < (game->map_ref->row_len * 72))
	{
		free(game->collec);
		error_resolution(game);
	}
	init_window(game);
	game->textures = ft_calloc(1, sizeof(t_image));
	if (!game->textures)
		error_msg("Problem asigning memory to image", &game, &game->map_ref);
	init_images(game, &game->map_ref);
	draw_images(game);
	mlx_hook(game->win_ptr, 17, 0, destroy_win_in_hook, game);
	mlx_hook(game->win_ptr, 2, 1L >> 0, key_press_hook, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map_placeholder;

	if (argc != 2)
	{
		ft_printf("Error\n Incorrect number of arguments.");
		exit(EXIT_FAILURE);
	}
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit(1);
	map_placeholder = NULL;
	game->map_ref = map_placeholder;
	read_map(&game, argv[1], &game->map_ref);
	start_game(game);
	close_game(game);
	return (0);
}
