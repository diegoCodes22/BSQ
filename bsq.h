/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtamayo- <dtamayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:56:02 by dtamayo-          #+#    #+#             */
/*   Updated: 2023/06/22 14:01:09 by dtamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

// LIBRARIES
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// VARIABLES
# define MAX_BUFF 2048

typedef struct s_map
{
	int		status;
	int		map_sz;
	int		cols;
	int		rows;
	char	**b_map;
	char	allowed[4];
}	t_map;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

// FUNCTIONS
t_map	check_map(char *filename);
void	solver(t_map map, int sq_sz);

// STR functions
char	*ft_strstr(char *str, char *to_find);
int		mod_strstr(char *str, char *to_find);
int		mod_strstr2(char *str, char to_find);
int		mod_strlen(char *str, char separator);
int		str_len(char *str);
int		check_dupes(char *str);
int		check_non_printable(char *str);
int		count_words(char *str);
void	mod_strlcpy(char *dest, char *src, int size);
int		ft_strlcat(char *dest, char *src, int size);
#endif