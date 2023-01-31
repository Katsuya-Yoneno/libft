/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:42:51 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/28 22:10:18 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 文字列s1とs2を比較する関数。一致していれば0、一致していなければ一致していない文字の差分を返す
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_t;
	const unsigned char	*s2_t;

	s1_t = s1;
	s2_t = s2;
	while (n > 0)
	{
		if (*s1_t != *s2_t)
			return (*s1_t - *s2_t);
		s1_t++;
		s2_t++;
		n--;
	}
	return (0);
}
