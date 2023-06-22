/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtamayo- <dtamayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:31 by dtamayo-          #+#    #+#             */
/*   Updated: 2023/06/22 15:11:14 by dtamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int	i, int j)
{
	if (i < j)
		return (i);
	else
		return (j);
}

void	print_map(t_map map, t_coords b_sq, int sq_sz)
{
	t_coords	i;

	i.y = 1;
	i.x = 1;
	while (i.y <= map.rows + 1)
	{
		i.x = 1;
		while (i.x <= map.cols)
		{
			if (i.y >= b_sq.y && i.y <= b_sq.y + sq_sz - 1
				&& i.x >= b_sq.x && i.x <= b_sq.x + sq_sz - 1)
				write(1, &map.allowed[2], 1);
			else if (i.x == map.cols && i.y != map.rows)
				write(1, "\n", 1);
			else
				write(1, &map.b_map[i.y][i.x], 1);
			i.x++;
		}
		i.y++;
	}
}

int	find_square(t_coords cur, t_map map, int square_size)
{
	t_coords	iter;
	int			st_y;

	iter.x = 0;
	iter.y = 0;
	st_y = cur.y;
	while (iter.x < square_size)
	{
		iter.y = 0;
		cur.y = st_y;
		while (iter.y < square_size)
		{
			if (map.b_map[cur.y][cur.x] == map.allowed[1])
				return (0);
			cur.y++;
			iter.y++;
		}
		cur.x++;
		iter.x++;
	}
	return (1);
}

void	try_empty(t_map map, t_coords *sq_c, int *sq_sz)
{
	t_coords	c;

	c.x = 1;
	c.y = 1;
	if (find_square(c, map, min(map.rows, map.cols) - 1))
	{
		sq_c->x = 1;
		sq_c->y = 1;
		*sq_sz = min(map.rows, map.cols);
		if (find_square(c, map, min(map.rows, map.cols)))
			*sq_sz = min(map.rows, map.cols) + 1;
	}
	else
		return ;
}

void	solver(t_map map, int sq_sz)
{
	t_coords	sq_c;
	t_coords	cur;

	cur.x = 1;
	cur.y = 1;
	while (sq_sz < (map.rows - cur.y))
	{
		if (sq_sz <= (map.cols - cur.x) && find_square(cur, map, sq_sz))
		{
			sq_c.x = cur.x;
			sq_c.y = cur.y;
			sq_sz++;
		}
		else
			cur.x++;
		if (map.b_map[cur.y][cur.x] == '\n')
		{
			cur.x = 1;
			cur.y++;
		}
	}
	try_empty(map, &sq_c, &sq_sz);
	print_map(map, sq_c, sq_sz - 1);
}
