/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ldblvect.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:55:24 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 20:59:56 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vectors.h"

static void	*ldblvect_memcpy(void *dest, void *src, size_t n)
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

t_ldblvect	*ldblvect_init(size_t initial_size)
{
	t_ldblvect	*vector;

	if (initial_size == 0)
		initial_size = 2;
	vector = malloc(initial_size * sizeof(t_ldblvect));
	if (vector == NULL)
		return (NULL);
	vector->table = malloc(initial_size * sizeof(long double));
	if (vector->table == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->nmemb = 0;
	vector->size = initial_size;
	return (vector);
}

void		ldblvect_free(t_ldblvect *vector)
{
	free(vector->table);
	free(vector);
}

static int	ldblvect_realloc(t_ldblvect *vector)
{
	long double	*new_table;

	vector->size *= 2;
	new_table = malloc(vector->size * sizeof(long double));
	if (new_table == NULL)
		return (-1);
	ldblvect_memcpy(new_table, vector->table, vector->nmemb * sizeof(long double));
	free(vector->table);
	vector->table = new_table;
	return (0);
}

int			ldblvect_pushback(t_ldblvect *vector, long double data)
{
	if (vector->nmemb == vector->size)
	{
		if (ldblvect_realloc(vector) == -1)
		{
			ldblvect_free(vector);
			return (-1);
		}
	}
	vector->table[vector->nmemb] = data;
	vector->nmemb += 1;
	return (0);
}
