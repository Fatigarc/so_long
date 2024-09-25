/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:01:23 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 08:17:00 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_flood_fill(t_map **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < (*map)->row_len)
	{
		x = 0;
		while (x < (*map)->column_len)
		{
			if ((*map)->map_dup[y][x] == 'P')
			{
				(*map)->main_char.posx = x;
				(*map)->main_char.posy = y;
				flood_fill(map, y, x, 1);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_map_row(t_map **map, int fd, const char *file_name, t_game **game)
{
	size_t	row_len;
	char	*temp;

	row_len = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		return (error_msg("The file could not be opened", game, map));
	temp = get_next_line(fd);
	while (temp)
	{
		row_len++;
		free(temp);
		temp = get_next_line(fd);
	}
	free (temp);
	(*map)->row_len = row_len;
	close(fd);
}

void	check_number_column(char *line, int *fd, t_game **game, t_map **map)
{
	int		first_line;
	size_t	previous_len;
	size_t	column_len;

	column_len = 0;
	first_line = 1;
	previous_len = 0;
	while (line)
	{
		column_len = ft_strlen(line);
		if (column_len > 0 && line[column_len - 1] == '\n')
			column_len--;
		if (first_line)
			previous_len = column_len;
		if (previous_len != column_len)
		{
			free(line);
			error_msg("It is not a rectangle", game, map);
			return ;
		}
		first_line = 0;
		free(line);
		line = get_next_line(*fd);
	}
	(*map)->column_len = column_len;
}

void	count_map_column(t_map **map, int fd, const char *file_name, \
						t_game **game)
{
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		error_msg("The file could not be read", game, map);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		error_msg("Empty file", game, map);
	}
	check_number_column(line, &fd, game, map);
	close(fd);
}
