/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_placeholder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:55:18 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/24 11:46:38 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "libft.h"
#include <stdbool.h>

/**
 * parse a placeholder at the beginning of a given string
 * @return a pointer to the string after the placeholder
 */
char	*parse_placeholder(t_placeholder *p, const char *s)
{
	if (*s != '%')
		return ((char *)s);
	s++;
	p->flags = 0;
	p->exist_width = ft_isdigit(*s);
	if (p->exist_width)
	{
		p->width = ft_atol(s);
		while (*s && ft_isdigit(*s))
			s++;
	}
	if (*s)
	{
		p->specifier = to_specifier(*s);
		if (p->specifier != UNKNOWN)
			s++;
	}
	else
		p->specifier = UNKNOWN;
	return ((char *)s);
}
