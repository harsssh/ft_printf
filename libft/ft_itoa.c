/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:07:46 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/20 20:00:04 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*reverse(char *s, size_t len)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
	return (s);
}

static size_t	count_width(unsigned int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	store_digit(unsigned int n, char *buf, size_t len)
{
	size_t	i;

	if (n == 0)
	{
		buf[0] = '0';
		return ;
	}
	i = 0;
	while (n && i < len)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	reverse(buf, len - 1);
}

char	*ft_itoa(int n)
{
	char			*buf;
	unsigned int	num;
	size_t			buf_len;

	num = ft_abs(n);
	buf_len = count_width(num) + 1;
	if (n < 0)
		buf_len++;
	buf = ft_calloc(buf_len, sizeof(char));
	if (buf == NULL)
		return (NULL);
	if (n < 0)
	{
		buf[0] = '-';
		store_digit(num, buf + 1, buf_len - 1);
	}
	else
		store_digit(num, buf, buf_len);
	return (buf);
}
