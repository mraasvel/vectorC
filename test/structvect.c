/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structvect.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 20:28:35 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/20 20:55:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "test.h"

static void			*VECTOR_TYPEvect_memcpy(void *dest, void *src, size_t n)
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

t_VECTOR_TYPEvect	*VECTOR_TYPEvect_init(size_t initial_size)
{
	t_VECTOR_TYPEvect	*new;

	if (initial_size == 0)
		initial_size = 2;
	new = malloc(1 * sizeof(t_VECTOR_TYPEvect));
	if (new == NULL)
		return (NULL);
	new->table = malloc(initial_size * sizeof(VECTOR_TYPE));
	if (new->table == NULL)
	{
		free(new);
		return (NULL);
	}
	new->size = initial_size;
	new->nmemb = 0;
	return (new);
}

static int			VECTOR_TYPEvect_realloc(t_VECTOR_TYPEvect *vector)
{
	
}

int					VECTOR_TYPEvect_pushback(VECTOR_TYPE data, t_VECTOR_TYPEvect *vector)
{
	if (vector->nmemb == vector->size)
	{
		if (VECTOR_TYPEvect_realloc(vector) == -1)
		{
			VECTOR_TYPEvect_free(vector);
			return (-1);
		}
	}
	vector->table[vector->nmemb] = data;
	vector->nmemb += 1;
	return (0);
}

void				VECTOR_TYPEvect_free(t_VECTOR_TYPEvect *vector)
{
	free(vector->table);
	free(vector);
}
