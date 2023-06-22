/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtamayo- <dtamayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:03:48 by dtamayo-          #+#    #+#             */
/*   Updated: 2023/06/21 17:54:38 by dtamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlcat(char *dest, char *src, int size)
{
	int	ds;
	int	ss;
	int	i;

	ds = str_len(dest);
	ss = str_len(src);
	i = 0;
	if (size <= ds)
		return (size + ss);
	while (src[i] != '\0' && ds + 1 < size)
	{
		dest[ds] = src[i];
		i++;
		ds++;
	}
	dest[ds] = '\0';
	return (ds + str_len(&src[i]));
}
