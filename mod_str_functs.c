/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_str_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtamayo- <dtamayo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:23:41 by azapata           #+#    #+#             */
/*   Updated: 2023/06/21 17:54:51 by dtamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	mod_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	mod_strstr2(char *str, char to_find)
{
	while (*str)
	{
		if (*str == to_find)
			return (1);
		str++;
	}
	return (0);
}

int	mod_strlen(char *str, char separator)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == separator || str[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

void	mod_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}
