/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:03:17 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 07:12:03 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_all_img(t_game **game, t_image *image)
{
	if (image->lemon_tree_xpm)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->textures->lemon_tree_xpm);
	if (image->heartsnack_xpm)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->textures->heartsnack_xpm);
	if (image->backg_xpm)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->textures->backg_xpm);
	if (image->dog_xpm)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->textures->dog_xpm);
	if (image->exit_house_xpm)
		mlx_destroy_image((*game)->mlx_ptr, (*game)->textures->exit_house_xpm);
	mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);
	mlx_loop_end((*game)->mlx_ptr);
	mlx_destroy_display((*game)->mlx_ptr);
	free ((*game)->textures);
	free ((*game)->collec);
	free((*game)->mlx_ptr);
	(*game)->mlx_ptr = NULL;
	free_map(*game);
	*game = NULL;
	exit(0);
}

void	free_map_error(t_game **game, t_map **map)
{
	size_t	y;

	if (game && *game && (*game)->map_ref)
	{
		if ((*game)->map_ref->map_readed)
		{
			y = 0;
			while (y < (*map)->row_len && (*game)->map_ref->map_readed[y])
			{
				free((*game)->map_ref->map_readed[y]);
				(*game)->map_ref->map_readed[y] = NULL;
				y++;
			}
			free((*game)->map_ref->map_readed);
			(*game)->map_ref->map_readed = NULL;
		}
		free((*game)->map_ref);
		(*game)->map_ref = NULL;
	}
	if ((*game)->collec)
		free((*game)->collec);
	(*game)->collec = NULL;
	free(*game);
	*game = NULL;
}

void	free_dup_map(t_map **map)
{
	int	y;

	y = 0;
	while ((*map)->map_dup[y] != NULL)
	{
		free((*map)->map_dup[y]);
		y++;
	}
	free ((*map)->map_dup);
	(*map)->map_dup = NULL;
}

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->map_ref->map_readed[y] != NULL)
	{
		free(game->map_ref->map_readed[y]);
		y++;
	}
	free(game->map_ref->map_readed);
	game->map_ref->map_readed = NULL;
	free (game->map_ref);
	game->map_ref = NULL;
	free (game);
}

void	free_empty_lines(char **map_dup, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(map_dup[i]);
		i++;
	}
	free(map_dup);
	map_dup = NULL;
}
