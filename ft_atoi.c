/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:03:51 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 16:44:00 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(const char *nptr, int i)
{
	int	sign;

	sign = 0;
	while (nptr[i] == '+' || nptr[i] == '-' )
	{
		if (nptr[i] == '-')
			sign = '-';
		if (nptr[i] == '+')
			sign = '+';
		i++;
	}
	return (sign);
}

static int	ft_is_overflow(const char *nptr, int sign, long int num, int i)
{
	long int	ov_div;
	int			ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (sign)
		return (0);
	if (num > ov_div)
		return (1);
	if (num == ov_div)
	{
		i++;
		if (nptr[i] - '0' > ov_mod)
			return (1);
	}
	return (0);
}

static int	ft_is_underflow(const char *nptr, int sign, long int num, int i)
{
	long int	ov_div;
	int			ov_mod;

	ov_div = (-1) * (LONG_MIN / 10);
	ov_mod = (-1) * (LONG_MIN % 10);
	if (!sign)
		return (0);
	if (num > ov_div)
		return (1);
	if (num == ov_div)
	{
		i++;
		if (nptr[i] - '0' > ov_mod)
			return (1);
	}
	return (0);
}

static long	ft_add_num(const char *nptr, long int num, int i, int sign)
{
	long int	ov_div;

	ov_div = LONG_MAX / 10;
	while ('0' <= nptr[i] && nptr[i] <= '9' && nptr[i])
	{
		num = num * 10 + (nptr[i] - '0');
		if (num == ov_div)
		{
			i++;
			num = num * 10 + (nptr[i] - '0');
			return (num);
		}
		if (ft_is_overflow(nptr, sign, num, i))
			return (LONG_MAX);
		if (ft_is_underflow(nptr, sign, num, i))
			return (LONG_MIN);
		i++;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	i = 0;
	sign = 0;
	while (('\t' <= nptr[i] && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	sign = ft_sign(nptr, i);
	if (sign == '+' || sign == '-')
		i++;
	if (nptr[i])
		num = ft_add_num(nptr, num, i, sign);
	if (sign == '-')
		num = 0 - num;
	return ((int)num);
}
