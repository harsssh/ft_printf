/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:07:46 by kemizuki          #+#    #+#             */
/*   Updated: 2023/05/20 14:10:57 by kemizuki         ###   ########.fr       */
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

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*split_digit(unsigned int n)
{
	char	*buf;
	size_t	i;
	size_t	buf_len;

	if (n == 0)
		return (ft_strdup("0"));
	buf_len = count_width(n) + 1;
	buf = ft_calloc(buf_len, sizeof(char));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (n)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (reverse(buf, buf_len - 1));
}

char	*ft_itoa(int n)
{
	char			*res;
	char			*tmp;
	unsigned int	num;

	num = ft_abs(n);
	res = split_digit(num);
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		tmp = ft_strjoin("-", res);
		free(res);
		res = tmp;
	}
	return (res);
}
