/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:51:28 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/10 00:14:41 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	limit;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize <= d_len || dstsize == 0)
		return (dstsize + s_len);
	i = 0;
	limit = d_len;
	while (src[i] && i < (dstsize - d_len - 1))
	{
		dst[limit] = src[i];
		i++;
		limit++;
	}
	dst[limit] = '\0';
	return (d_len + s_len);
}
