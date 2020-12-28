/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvect.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:29:17 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/27 20:54:27 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECT_H
# define LIBVECT_H

# include <stddef.h>

/*
** Integer vectors
** Can use t_vector instead if you don't mind typecasting
*/

typedef struct	s_int32vect
{
	int		*table;
	size_t	nmemb;
	size_t	size;
}				t_int32vect;

int				int32vect_pushback(int value, t_int32vect *vector);
void			int32vect_free(t_int32vect *vector);
t_int32vect		*int32vect_init(size_t initial_size);

typedef struct	s_uint32vect
{
	unsigned int	*table;
	size_t			nmemb;
	size_t			size;
}				t_uint32vect;

int				uint32vect_pushback(unsigned int value, t_uint32vect *vector);
void			uint32vect_free(t_uint32vect *vector);
t_uint32vect	*uint32vect_init(size_t initial_size);

typedef struct	s_int64vect
{
	long long	*table;
	size_t		nmemb;
	size_t		size;
}				t_int64vect;

int				int64vect_pushback(long long value, t_int64vect *vector);
void			int64vect_free(t_int64vect *vector);
t_int64vect		*int64vect_init(size_t initial_size);

typedef struct	s_uint64vect
{
	unsigned long long	*table;
	size_t				nmemb;
	size_t				size;
}				t_uint64vect;

int				uint64vect_pushback(unsigned long long value,
				t_uint64vect *vector);
void			uint64vect_free(t_uint64vect *vector);
t_uint64vect	*uint64vect_init(size_t initial_size);

/*
** Floating point vectors
*/

typedef struct	s_fltvect
{
	float	*table;
	size_t	nmemb;
	size_t	size;
}				t_fltvect;

int				fltvect_pushback(t_fltvect *vector, float data);
void			fltvect_free(t_fltvect *vector);
t_fltvect		*fltvect_init(size_t initial_size);

typedef struct	s_dblvect
{
	double	*table;
	size_t	nmemb;
	size_t	size;
}				t_dblvect;

int				dblvect_pushback(t_dblvect *vector, double data);
void			dblvect_free(t_dblvect *vector);
t_dblvect		*dblvect_init(size_t initial_size);

typedef struct	s_ldblvect
{
	long double	*table;
	size_t		nmemb;
	size_t		size;
}				t_ldblvect;

int				ldblvect_pushback(t_ldblvect *vector, long double data);
void			ldblvect_free(t_ldblvect *vector);
t_ldblvect		*ldblvect_init(size_t initial_size);

/*
** Vector that can take any data type
** Send own delete function for
** freeing contents of void* (like free for strings/pointers)
*/

typedef struct	s_vect
{
	void	*table;
	size_t	data_size;
	size_t	nmemb;
	size_t	size;
}				t_vect;

t_vect			*vect_init(size_t initial_size, unsigned int data_type);
int				vect_pushback(t_vect *vector, void *data);
void			vect_free(t_vect *vector, void (*del)(void*));
void			*vect_add(t_vect *vector);

typedef struct	s_vpvect
{
	void	**table;
	size_t	nmemb;
	size_t	size;
}				t_vpvect;

#endif
