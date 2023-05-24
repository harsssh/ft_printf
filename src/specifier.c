/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:02:37 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/24 11:41:19 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

t_spec	to_specifier(char c)
{
	if (c == 'c')
		return (CHAR);
	if (c == 's')
		return (STRING);
	if (c == 'd' || c == 'i')
		return (DECIMAL);
	if (c == 'u')
		return (U_DECIMAL);
	if (c == 'x')
		return (HEX);
	if (c == 'X')
		return (HEX_UP);
	if (c == 'p')
		return (POINTER);
	if (c == '%')
		return (PERCENT);
	return (UNKNOWN);
}
