/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:44:21 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/29 00:52:20 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 説明
//        memmove() 関数は、メモリ領域 src からメモリ領域 dest へ n バイトをコピーする。 メモリ領域はオーバーラップしていても構いません。
//        src のバイトがまず src と dest に重複しない一時的な配列にコピーされ、その一時的な配列から dest にバイトがコピーされます。
//        にコピーされ、その一時配列からdestにコピーされます。

// 返り値
//        memmove()関数はdestへのポインタを返します
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		while (i < n)
		{
			(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			(((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1]);
			n--;
		}
	}
	return (dst);
}
