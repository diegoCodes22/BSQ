/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtamayo- <dtamayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:50:55 by azapata           #+#    #+#             */
/*   Updated: 2023/06/21 18:14:15 by dtamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*remove_fl(char *filename, int map_sz)
{
	char	l;
	char	*buffer;
	int		nl_count;
	int		i;
	int		file;

	buffer = (char *)malloc(map_sz);
	if (!(buffer))
		return ((char *)0);
	nl_count = 0;
	i = 0;
	file = open(filename, O_RDONLY);
	while (read(file, &l, 1))
	{
		if (l == '\n')
			nl_count++;
		if (nl_count == 0)
			continue ;
		buffer[i] = l;
		i++;
	}
	close(file);
	return (buffer);
}

void	allowed_chars(int fd, t_map *map)
{
	int		pos;
	char	perm[16];
	char	letter;

	pos = 0;
	while (read(fd, &letter, 1))
	{
		if (letter == '\n')
			break ;
		perm[pos] = letter;
		pos++;
	}
	map->allowed[0] = perm[pos - 3];
	map->allowed[1] = perm[pos - 2];
	map->allowed[2] = perm[pos - 1];
	map->allowed[3] = '\n';
	if (!(check_dupes(map->allowed) || check_non_printable(map->allowed)))
		map->status = 0;
	else
		map->status = 1;
}

int	map_size_info(int file, t_map *map, int col_len)
{
	char	letter;

	map->map_sz = 0;
	map->rows = 0;
	while (read(file, &letter, 1))
	{
		if (letter == '\n')
		{
			map->rows++;
			if (map->rows == 2)
				map->cols = col_len;
			else if (col_len != map->cols && map->rows > 2)
				return (map->status = 0);
			col_len = 0;
		}
		col_len++;
		map->map_sz++;
	}
	map->rows++;
	map->map_sz++;
	if (!(map->map_sz))
		return (map->status = 0);
	else
		return (map->status = 1);
}

int	make_map(char *map_nfl, t_map *map)
{
	int		rc;
	int		cc;

	map->b_map = (char **)malloc((map->rows + 1) * sizeof(char *));
	if (map->b_map == ((char **)0))
		return (map->status = 0);
	rc = 0;
	while (*map_nfl)
	{
		if (*map_nfl == '\n' && rc != map->rows)
		{
			rc++;
			map->b_map[rc] = (char *)malloc(map->cols + 1);
			if (map->b_map[rc] == ((char *)0))
				return (map->status = 0);
			cc = 0;
		}
		if (!(mod_strstr2(map->allowed, *map_nfl)))
			return (map->status = 0);
		map->b_map[rc][cc] = *map_nfl;
		cc++;
		map_nfl++;
	}
	return (map->status = 1);
}

t_map	check_map(char *filename)
{
	int		file;
	t_map	map;
	int		trash;
	char	*no_fl;

	file = open(filename, O_RDONLY);
	if (file < 1)
	{
		map.status = 0;
		return (map);
	}
	allowed_chars(file, &map);
	if (!(map.status))
		return (map);
	trash = map_size_info(file, &map, 0);
	if (!(map.status))
		return (map);
	no_fl = remove_fl(filename, map.map_sz);
	make_map(no_fl, &map);
	free(no_fl);
	close(file);
	return (map);
}
