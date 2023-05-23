/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:09:45 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/23 15:11:46 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include <stdbool.h>

enum							e_flag
{
	HYPHEN,
	ZERO,
	PLUS,
	SPACE,
	HASH,
};
typedef enum e_flag				t_flag;

enum							e_spec
{
	UNKNOWN,
	U_CHAR,    // c
	STRING,    // s
	DECIMAL,   // d, i
	U_DECIMAL, // u
	U_HEX,     // x, X
	POINTER,   // p
	PERCENT,   // %
};
typedef enum e_spec				t_spec;

// conversion specification
// %[flags][width].[precision][length modifier][specifier]
// omit precision, length modifier
struct							s_placeholder
{
	t_flag						*flags;
	bool						exist_width;
	unsigned long				width;
	t_spec						specifier;
};
typedef struct s_placeholder	t_placeholder;

char							*parse_placeholder(t_placeholder *p,
									const char *s);
t_spec							to_specifier(char c);

#endif
