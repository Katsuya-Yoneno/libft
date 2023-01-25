/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:49 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/25 22:19:58 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 数値を文字列に変換する関数

//再帰的に配列に文字を格納
void	ft_fill_num(long int n, char *res, int i)
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
	char	*res;
	int		n_size;
	//long型でintの最大値に対応
	int long		tmp;

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
