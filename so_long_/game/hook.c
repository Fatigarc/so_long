/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:32:08 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 02:56:37 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destroy_win_in_hook(t_game *game)
{
	destroy_all_img(&game, game->textures);
	exit(1);
	return (0);
}

int	key_press_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_all_img(&game, game->textures);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game, game->map_ref);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game, game->map_ref);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game, game->map_ref);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game, game->map_ref);
	return (0);
}
