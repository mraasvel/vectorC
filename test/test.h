/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 20:28:37 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/20 20:30:34 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <stddef.h>

typedef struct	s_test
{
	int	x;
	int	y;
	int	z;
}				t_test;

#define VECTOR_TYPE t_test

typedef struct	s_VECTOR_TYPEvect
{
	VECTOR_TYPE	*table;
	size_t		nmemb;
	size_t		size;
}				t_VECTOR_TYPEvect;

#endif
