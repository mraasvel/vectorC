/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uint32vect.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:53:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/16 13:54:23 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vectors.h"

static void	*vect_memcpy(void *dest, void *src, size_t size)
{
	size_t	i;

	if (dest == src)
		return (dest);
	i = 0;
	while (i < size)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

t_uint32vect	*uint32vect_init(size_t initial_size)
{
	t_uint32vect	*vector;

	if (initial_size == 0)
		initial_size = 2;
	vector = (t_uint32vect*)malloc(1 * sizeof(t_uint32vect));
	if (vector == NULL)
		return (NULL);
	vector->table = (unsigned int*)malloc(initial_size * sizeof(unsigned int));
	if (vector->table == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->size = initial_size;
	vector->nmemb = 0;
	return (vector);
}

void		uint32vect_free(t_uint32vect *vector)
{
	free(vector->table);
	free(vector);
}

static int	uint32vect_realloc(t_uint32vect *vector)
{
	size_t			new_size;
	unsigned int	*new_table;

	new_size = vector->size * 2;
	new_table = (unsigned int*)malloc(new_size * sizeof(unsigned int));
	if (new_table == NULL)
		return (-1);
	vect_memcpy(new_table, vector->table, vector->nmemb);
	free(vector->table);
	vector->table = new_table;
	vector->size = new_size;
	return (0);
}

int			uint32vect_pushback(unsigned int value, t_uint32vect *vector)
{
	if (vector->nmemb == vector->size)
	{
		if (uint32vect_realloc(vector) == -1)
		{
			uint32vect_free(vector);
			return (-1);
		}
	}
	vector->table[vector->nmemb] = value;
	vector->nmemb += 1;
	return (0);
}