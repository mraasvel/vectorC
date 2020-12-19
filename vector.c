/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 19:54:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 20:07:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

static void	*vector_memcpy(void *dest, void *src, size_t n)
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

t_vector	*vector_init(size_t initial_size, unsigned int data_type)
{
	t_vector	*vector;

	if (initial_size == 0)
		initial_size = 2;
	vector = malloc(initial_size * sizeof(t_vector));
	if (vector == NULL)
		return (NULL);
	vector->table = malloc(initial_size * data_type);
	if (vector->table == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->nmemb = 0;
	vector->data_size = data_type;
	vector->size = initial_size;
	return (vector);
}

void		free_vector(t_vector *vector, void (*del)(void*))
{
	size_t	i;

	if (del != NULL)
	{
		i = 0;
		while (i < vector->nmemb)
		{
			del(((void**)vector->table)[i]);
			i++;
		}
	}
	free(vector->table);
	free(vector);
}

static int	vector_realloc(t_vector *vector)
{
	void	*new_table;

	vector->size *= 2;
	new_table = malloc(vector->size * vector->data_size);
	if (new_table == NULL)
		return (-1);
	vector_memcpy(new_table, vector->table, vector->nmemb * vector->data_size);
	free(vector->table);
	vector->table = new_table;
	return (0);
}

int			vector_pushback(t_vector *vector, void *data)
{
	if (vector->nmemb == vector->size)
	{
		if (vector_realloc(vector) == -1)
			return (-1);
	}
	vector_memcpy(vector->table + vector->nmemb, data, vector->data_size);
	vector->nmemb += 1;
	return (0);
}
