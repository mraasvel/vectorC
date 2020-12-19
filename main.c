/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 14:03:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 21:02:22 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include "vectors.h"

int	main(void)
{
	t_ldblvect	*vector;
	
	
	vector = ldblvect_init(0);
	ldblvect_pushback(vector, 234.394857389475);
	printf("%Lf\n", vector->table[0]);
	ldblvect_free(vector);
	return (0);
}
