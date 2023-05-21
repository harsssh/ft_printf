/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:09:45 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/21 19:23:34 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

enum					e_flag
{
	HYPHEN,
	ZERO,
	PLUS,
	SPACE,
	HASH,
};
typedef enum e_flag		t_flag;

enum					e_spec
{
	U_CHAR,    // c
	STRING,    // s
	DECIMAL,   // d, i
	U_DECIMAL, // u
	U_HEX,     // x, X
	POINTER,   // p
	PERCENT,   // %
};
typedef enum e_spec		t_spec;

// conversion specification
// omit length modifier
struct					s_format
{
	t_flag				*flags;
	unsigned int		width;
	unsigned int		precision;
	t_spec				specifier;
};
typedef struct s_format	t_format;

#endif
