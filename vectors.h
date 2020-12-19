/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vectors.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:29:17 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/19 20:02:14 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stddef.h>

struct	s_int32vect
{
	int		*table;
	size_t	nmemb;
	size_t	size;
};

struct	s_uint32vect
{
	unsigned int		*table;
	size_t	nmemb;
	size_t	size;
};

struct	s_int64vect
{
	long long	*table;
	size_t		nmemb;
	size_t		size;
};

struct	s_uint64vect
{
	unsigned long long	*table;
	size_t				nmemb;
	size_t				size;
};

struct	s_charvect
{
	char	*str;
	size_t	nmemb;
	size_t	size;
};

struct	s_strvect
{
	char	**str;
	size_t	nmemb;
	size_t	size;
};

struct	s_fltvect
{
	float	*table;
	size_t	nmemb;
	size_t	size;
};

struct	s_dblvect
{
	double	*table;
	size_t	nmemb;
	size_t	size;
};

typedef struct	s_vector
{
	void	*table;
	size_t	data_size;
	size_t	nmemb;
	size_t	size;
}				t_vector;

typedef struct s_int64vect t_int32vect;
typedef struct s_uint32vect t_uint32vect;
typedef struct s_int64vect t_int64vect;
typedef struct s_uint64vect t_uint64vect;
typedef struct s_charvect t_charvect;
typedef struct s_strvect t_strvect;
typedef struct s_fltvect t_fltvect;
typedef struct s_dblvect t_dblvect;

#endif
