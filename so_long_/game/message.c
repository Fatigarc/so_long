/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:55:49 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 06:43:49 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_creating_img(t_game **game, t_map **map)
{
	if ((*game)->textures->lemon_tree_xpm == NULL || \
			(*game)->textures->heartsnack_xpm == NULL || \
			(*game)->textures->backg_xpm == NULL || \
			(*game)->textures->dog_xpm == NULL || \
			(*game)->textures->exit_house_xpm == NULL)
	{
		error_msg("Error creating images", game, map);
		destroy_all_img(game, (*game)->textures);
	}
}

void	error_resolution(t_game *game)
{
	ft_printf("ERROR: \n Resolution, %d x %d \n", \
	game->map_ref->column_len, game->map_ref->row_len);
	mlx_loop_end(game->mlx_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game);
	exit (1);
}

void	error_msg(char	*str, t_game **game, t_map **map)
{
	ft_printf("ERROR:\n %s \n", str);
	if (game && *game)
	{
		if ((*game)->map_ref->map_readed)
			free_map_error(game, map);
		else
		{
			free((*game)->map_ref);
			(*game)->map_ref = NULL;
		}
		free(*game);
		*game = NULL;
	}
	exit(1);
}
