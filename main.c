/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtamayo- <dtamayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:50:55 by azapata           #+#    #+#             */
/*   Updated: 2023/06/22 14:01:20 by dtamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->b_map[i])
	{
		free(map->b_map[i]);
		i++;
	}
	free(map->b_map);
}

//free_map(&map);
void	use_input(char *files)
{
	char	filepath[MAX_BUFF];
	int		arg_len;
	t_map	map;

	while (*files)
	{
		arg_len = mod_strlen(files, ' ');
		mod_strlcpy(filepath, files, arg_len + 1);
		write(1, &filepath, arg_len + 1);
		write(1, "\n", 1);
		map = check_map(filepath);
		if (map.status)
			solver(map, 2);
		else
			write(1, "Invalid map or path to file\n", 29);
		write(1, "\n", 1);
		files += arg_len + 1;
	}
}

void	get_input(void)
{
	char	l;
	char	files[MAX_BUFF];
	int		i;

	i = 0;
	write(0, "Path to map file: ", 19);
	while (read(0, &l, 1) && l != '\n')
	{
		files[i] = l;
		i++;
	}
	files[i] = '\0';
	use_input(files);
}

//free_map(&map);
int	main(int argc, char *argv[])
{
	int		i;
	t_map	map;

	i = 1;
	if (argc == 1)
		get_input();
	else
	{
		while (i < argc)
		{
			write(1, argv[i], str_len(argv[i]));
			write(1, "\n", 1);
			map = check_map(argv[i]);
			if (map.status)
				solver(map, 2);
			else
				write(1, "Invalid map or path to file\n", 29);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
