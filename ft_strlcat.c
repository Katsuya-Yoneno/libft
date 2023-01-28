/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:51:28 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/25 23:31:31 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//srcをsize - strlen(dst) - 1バイト文字分dstの末尾に追記null止めする関数。
//sizeにdstのサイズ以上を指定すればバッファオーバーランしない。
//連結後の文字列の長さを返す。
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	if (!dst)
		return (0);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	j = d_len;
	// sizeが0より大きく、dstが終端文字を除いたsizeより小さい場合
	if (d_len < size - 1 && size > 0)
	{
		// srcが終端ではない、かつ、sizeの範囲内でループ
		while (src[i] && d_len + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';	
	}
	if (d_len >= size)
		d_len = size;
	return (d_len + s_len);
}
