/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dblvect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:55:24 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 21:10:43 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vectors.h"

static void	*dblvect_memcpy(void *dest, void *src, size_t n)
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

t_dblvect	*dblvect_init(size_t initial_size)
{
	t_dblvect	*vector;

	if (initial_size == 0)
		initial_size = 2;
	vector = malloc(initial_size * sizeof(t_dblvect));
	if (vector == NULL)
		return (NULL);
	vector->table = malloc(initial_size * sizeof(double));
	if (vector->table == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->nmemb = 0;
	vector->size = initial_size;
	return (vector);
}

void		dblvect_free(t_dblvect *vector)
{
	free(vector->table);
	free(vector);
}

static int	dblvect_realloc(t_dblvect *vector)
{
	double	*new_table;

	vector->size *= 2;
	new_table = malloc(vector->size * sizeof(double));
	if (new_table == NULL)
		return (-1);
	dblvect_memcpy(new_table, vector->table, vector->nmemb * sizeof(double));
	free(vector->table);
	vector->table = new_table;
	return (0);
}

int			dblvect_pushback(t_dblvect *vector, double data)
{
	if (vector->nmemb == vector->size)
	{
		if (dblvect_realloc(vector) == -1)
		{
			dblvect_free(vector);
			return (-1);
		}
	}
	vector->table[vector->nmemb] = data;
	vector->nmemb += 1;
	return (0);
}
