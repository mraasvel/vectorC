/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 14:03:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 20:24:01 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vectors.h"

int	main(void)
{
	t_vector	*vector;
	void		*ptr;
	
	vector = vector_init(0, sizeof(char*));
	ptr = vector_add(vector);
	*(char**)ptr = strdup("abc");
	printf("%s\n", ((char**)vector->table)[0]);
	free_vector(vector, free);
	return (0);
}
