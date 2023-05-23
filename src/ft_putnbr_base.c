/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:10:07 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/23 22:28:33 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putunbr_base(unsigned long long nbr, char *base)
{
	unsigned int	blen;

	blen = ft_strlen(base);
	if (nbr < blen)
	{
		ft_putchar_fd(base[nbr], STDOUT_FILENO);
	}
	else
	{
		ft_putunbr_base(nbr / blen, base);
		ft_putunbr_base(nbr % blen, base);
	}
}

void	ft_putnbr_base(long long nbr, char *base)
{
	unsigned int	blen;

	blen = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		ft_putunbr_base(-(nbr / blen), base);
		ft_putunbr_base(-(nbr % blen), base);
	}
	else
		ft_putunbr_base(nbr, base);
}
