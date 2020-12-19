/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fltvect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:55:24 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 21:11:10 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vectors.h"

static void	*fltvect_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

t_fltvect	*fltvect_init(size_t initial_size)
{
	t_fltvect	*vector;

	if (initial_size == 0)
		initial_size = 2;
	vector = malloc(initial_size * sizeof(t_fltvect));
	if (vector == NULL)
		return (NULL);
	vector->table = malloc(initial_size * sizeof(float));
	if (vector->table == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->nmemb = 0;
	vector->size = initial_size;
	return (vector);
}

void		fltvect_free(t_fltvect *vector)
{
	free(vector->table);
	free(vector);
}

static int	fltvect_realloc(t_fltvect *vector)
{
	float	*new_table;

	vector->size *= 2;
	new_table = malloc(vector->size * sizeof(float));
	if (new_table == NULL)
		return (-1);
	fltvect_memcpy(new_table, vector->table, vector->nmemb * sizeof(float));
	free(vector->table);
	vector->table = new_table;
	return (0);
}

int			fltvect_pushback(t_fltvect *vector, float data)
{
	if (vector->nmemb == vector->size)
	{
		if (fltvect_realloc(vector) == -1)
		{
			fltvect_free(vector);
			return (-1);
		}
	}
	vector->table[vector->nmemb] = data;
	vector->nmemb += 1;
	return (0);
}
