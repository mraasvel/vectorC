/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uint64vect.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:55:22 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 21:09:37 by mraasvel      ########   odam.nl         */
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

t_uint64vect	*uint64vect_init(size_t initial_size)
{
	t_uint64vect	*vector;

	if (initial_size == 0)
		initial_size = 2;
	vector = (t_uint64vect*)malloc(1 * sizeof(t_uint64vect));
	if (vector == NULL)
		return (NULL);
	vector->table = (unsigned long long*)malloc(initial_size * sizeof(unsigned long long));
	if (vector->table == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->size = initial_size;
	vector->nmemb = 0;
	return (vector);
}

void		uint64vect_free(t_uint64vect *vector)
{
	free(vector->table);
	free(vector);
}

static int	uint64vect_realloc(t_uint64vect *vector)
{
	size_t				new_size;
	unsigned long long	*new_table;

	new_size = vector->size * 2;
	new_table = (unsigned long long*)malloc(new_size * sizeof(unsigned long long));
	if (new_table == NULL)
		return (-1);
	vect_memcpy(new_table, vector->table, vector->nmemb);
	free(vector->table);
	vector->table = new_table;
	vector->size = new_size;
	return (0);
}

int			uint64vect_pushback(unsigned long long value, t_uint64vect *vector)
{
	if (vector->nmemb == vector->size)
	{
		if (uint64vect_realloc(vector) == -1)
		{
			uint64vect_free(vector);
			return (-1);
		}
	}
	vector->table[vector->nmemb] = value;
	vector->nmemb += 1;
	return (0);
}
