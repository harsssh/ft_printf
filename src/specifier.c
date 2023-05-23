/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:02:37 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/23 15:11:41 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

t_spec to_specifier(char c)
{
	if (c == 'c')
		return U_CHAR;
	if (c == 's')
		return STRING;
	if (c == 'd' || c == 'i')
		return DECIMAL;
	if (c == 'u')
		return U_DECIMAL;
	if (c == 'x' || c == 'X')
		return U_HEX;
	if (c == 'p')
		return POINTER;
	if (c == '%')
		return PERCENT;
	return UNKNOWN;
}
