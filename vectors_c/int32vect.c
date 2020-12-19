/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intvect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:42:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/16 13:52:34 by mraasvel      ########   odam.nl         */
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

t_int32vect	*int32vect_init(size_t initial_size)
{
	t_int32vect	*vector;

	if (initial_size == 0)
		initial_size = 2;
	vector = (t_int32vect*)malloc(1 * sizeof(t_int32vect));
	if (vector == NULL)
		return (NULL);
	vector->table = (int*)malloc(initial_size * sizeof(int));
	if (vector->table == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->size = initial_size;
	vector->nmemb = 0;
	return (vector);
}

void		int32vect_free(t_int32vect *vector)
{
	free(vector->table);
	free(vector);
}

static int	int32vect_realloc(t_int32vect *vector)
{
	size_t	new_size;
	int		*new_table;

	new_size = vector->size * 2;
	new_table = (int*)malloc(new_size * sizeof(int));
	if (new_table == NULL)
		return (-1);
	vect_memcpy(new_table, vector->table, vector->nmemb);
	free(vector->table);
	vector->table = new_table;
	vector->size = new_size;
	return (0);
}

int			int32vect_pushback(int value, t_int32vect *vector)
{
	if (vector->nmemb == vector->size)
	{
		if (int32vect_realloc(vector) == -1)
		{
			int32vect_free(vector);
			return (-1);
		}
	}
	vector->table[vector->nmemb] = value;
	vector->nmemb += 1;
	return (0);
}