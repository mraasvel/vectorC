/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vect.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 19:54:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 22:52:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libvect.h"

static void	*vect_memcpy(void *dest, void *src, size_t n)
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

t_vect	*vect_init(size_t initial_size, unsigned int data_type)
{
	t_vect	*vect;

	if (initial_size == 0)
		initial_size = 2;
	vect = malloc(sizeof(t_vect));
	if (vect == NULL)
		return (NULL);
	vect->table = malloc(initial_size * data_type);
	if (vect->table == NULL)
	{
		free(vect);
		return (NULL);
	}
	vect->nmemb = 0;
	vect->data_size = data_type;
	vect->size = initial_size;
	return (vect);
}

void		vect_free(t_vect *vect, void (*del)(void*))
{
	size_t	i;

	if (del != NULL)
	{
		i = 0;
		while (i < vect->nmemb)
		{
			del(((void**)vect->table)[i]);
			i++;
		}
	}
	free(vect->table);
	free(vect);
}

static int	vect_realloc(t_vect *vect)
{
	void	*new_table;

	vect->size *= 2;
	new_table = malloc(vect->size * vect->data_size);
	if (new_table == NULL)
		return (-1);
	vect_memcpy(new_table, vect->table, vect->nmemb * vect->data_size);
	free(vect->table);
	vect->table = new_table;
	return (0);
}

int			vect_pushback(t_vect *vect, void *data)
{
	unsigned char	*ptr;

	if (vect->nmemb == vect->size)
	{
		if (vect_realloc(vect) == -1)
			return (-1);
	}
	ptr = ((unsigned char*)vect->table) + vect->nmemb * vect->data_size;
	vect_memcpy(ptr, data, vect->data_size);
	vect->nmemb += 1;
	return (0);
}
