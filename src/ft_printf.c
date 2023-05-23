/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:42:37 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/23 23:01:40 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "libft.h"
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

static void	print_placeholder(const t_placeholder ph, va_list *ap)
{
	va_list	args;

	va_copy(args, *ap);
	if (ph.specifier == CHAR)
		ft_putchar_fd((unsigned char)(va_arg(args, int)), STDOUT_FILENO);
	else if (ph.specifier == STRING)
		ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
	else if (ph.specifier == DECIMAL)
		ft_putnbr_base(va_arg(args, int), DECIMAL_BASE);
	else if (ph.specifier == U_DECIMAL)
		ft_putunbr_base(va_arg(args, unsigned int), DECIMAL_BASE);
	else if (ph.specifier == HEX)
		ft_putunbr_base(va_arg(args, unsigned int), HEX_BASE);
	else if (ph.specifier == POINTER)
	{
		ft_putstr_fd("0x", STDOUT_FILENO);
		ft_putnbr_base((uintptr_t)va_arg(args, void *), HEX_BASE);
	}
	else if (ph.specifier == PERCENT)
		ft_putchar_fd('%', STDOUT_FILENO);
	va_end(args);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_placeholder	ph;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = parse_placeholder(&ph, format);
			print_placeholder(ph, &args);
		}
		else
			ft_putchar_fd(*format++, STDOUT_FILENO);
	}
	va_end(args);
	return (0);
}
