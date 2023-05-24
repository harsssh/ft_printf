/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:09:45 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/24 13:10:25 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H
#include <stddef.h>
# define DECIMAL_BASE "0123456789"
# define HEX_BASE "0123456789abcdef"
# define HEX_BASE_UP "0123456789ABCDEF"

# include <stdbool.h>
#include <stddef.h>

enum							e_flag
{
	HYPHEN = 1,
	ZERO = 1 << 2,
	PLUS = 1 << 3,
	SPACE = 1 << 4,
	HASH = 1 << 5,
};
typedef enum e_flag				t_flag;

enum							e_spec
{
	UNKNOWN,
	CHAR,
	STRING,
	DECIMAL,
	U_DECIMAL,
	HEX,
	HEX_UP,
	POINTER,
	PERCENT,
};
typedef enum e_spec				t_spec;

// conversion specification
// %[flags][width].[precision][length modifier][specifier]
// omit precision, length modifier
struct							s_placeholder
{
	unsigned long long			flags;
	bool						exist_width;
	unsigned long long			width;
	t_spec						specifier;
};
typedef struct s_placeholder	t_placeholder;

char	*parse_placeholder(t_placeholder *p, const char *s);
t_spec	to_specifier(char c);
size_t	ft_putnbr_base(long long nbr, char *base);
size_t	ft_putunbr_base(unsigned long long nbr, char *base);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);

#endif
