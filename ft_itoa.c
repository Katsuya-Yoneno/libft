/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:49 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 16:44:23 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_num(long int n, char *res, int i)
{
	long int		num;

	if (n < 0)
	{
		num = -n;
		res[0] = '-';
	}
	else
		num = n;
	if (num >= 10)
	{
		ft_fill_num(num / 10, res, i - 1);
		ft_fill_num(num % 10, res, i);
	}
	if (num < 10)
	{
		num = num + '0';
		res[i] = num;
	}
}

char	*ft_itoa(int n)
{
	char		*res;
	int			n_size;
	int long	tmp;

	tmp = n;
	n_size = 0;
	while (tmp != 0)
	{
		if (tmp < 0)
		{
			n_size++;
			tmp = tmp * (-1);
		}
		tmp = tmp / 10;
		n_size = n_size + 1;
	}
	if (n == 0)
		n_size = 1;
	res = (char *)malloc(n_size * sizeof(char));
	if (!res)
		return (0);
	res[n_size] = '\0';
	ft_fill_num(n, res, n_size - 1);
	return (res);
}
