/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:49 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/15 15:21:09 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cal_size_num(int n)
{
	int	len;
	
	len = 0;
	if (n < 0)
	{
		len++;
		n = 0 - n;
	}	
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len_n;
	int		mod;

	len_n = cal_size_num(n);
	res = (char *)malloc((len_n + 1) * sizeof(char));
	if (!res)
		return (0);
	if (n < 0)
	{
		*res = '-';
		res++;
		len_n--;
	}
	res[len_n + 1] = '\0';
	while (len_n > 1)
	{
		mod = n % 10;
		res[len_n] = mod + '0';
		n = n / 10;
		len_n--;
	}
	return (res);
}