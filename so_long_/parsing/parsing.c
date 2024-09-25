/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:55:37 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 08:42:26 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	duplicate_map(t_map **map)
{
	size_t	y;

	y = 0;
	(*map)->map_dup = ft_calloc((*map)->row_len + 1, sizeof(char *));
	while (y <= ((*map)->row_len))
	{
		if ((*map)->map_readed[y] == NULL)
		{
			(*map)->map_dup[y] = NULL;
			break ;
		}
		(*map)->map_dup[y] = ft_strdup((*map)->map_readed[y]);
		if ((*map)->map_dup[y] == NULL)
			free_empty_lines((*map)->map_dup, y);
		y++;
	}
}

void	check_player_exit(int nb_p, int nb_e, t_game **game, t_map **map)
{
	if (nb_p != 1)
		error_msg("Must have exactly one player", game, map);
	if (nb_e != 1)
		error_msg("Must have exactly one exit", game, map);
}

void	valid_character(t_game **game, t_map **map)
{
	size_t	count_x;
	size_t	count_y;
	int		nb_p;
	int		nb_e;
	char	*allowed;

	count_y = 0;
	nb_p = 0;
	nb_e = 0;
	allowed = "01PEC";
	while (count_y < (*map)->row_len)
	{
		count_x = 0;
		while (count_x < (*map)->column_len)
		{
			if (ft_strchr(allowed, (*map)->map_readed[count_y][count_x]) == 0)
				error_msg("Not valid character", game, map);
			nb_p += ((*map)->map_readed[count_y][count_x] == 'P');
			nb_e += ((*map)->map_readed[count_y][count_x] == 'E');
			count_x++;
		}
		count_y++;
	}
	check_player_exit(nb_p, nb_e, game, map);
}

void	map_parsing(t_map **map, t_game **game)
{
	(*game)->collec = ft_calloc(1, sizeof(t_collec));
	if ((*game)->collec == NULL)
		error_msg("Failed to allocate memory for collec", game, map);
	if (((*map)->column_len >= 150) && ((*map)->row_len >= 150))
		error_msg("The map is too big", game, map);
	valid_character(game, map);
	verify_object(game, map);
	verify_wall(map, game);
	duplicate_map(map);
	verify_valid_path(map, game);
	free_dup_map (map);
}

void	read_map(t_game **game, const char *file_name, t_map **map)
{
	int		fd;
	char	*line;
	size_t	rw_len;

	*map = ft_calloc(1, sizeof (t_map));
	if (!*map)
		error_msg("Memory allocation failed", game, map);
	(*game)->map_ref = *map;
	verify_extension(file_name, game, map);
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		error_msg("The file could not be opened", game, map);
	count_map_row(map, fd, file_name, game);
	(*map)->map_readed = ft_calloc((*map)->row_len + 1, sizeof(char *));
	count_map_column(map, fd, file_name, game);
	line = get_next_line(fd);
	rw_len = 0;
	while (line != NULL && rw_len < (*map)->row_len)
	{
		(*map)->map_readed[rw_len] = line;
		rw_len++;
		line = get_next_line(fd);
	}
	map_parsing (map, game);
	close (fd);
}
