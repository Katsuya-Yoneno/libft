/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:42:19 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/09 22:42:31 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	size_t			count;

	count = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (count < n)
	{
		dst_tmp[count] = src_tmp[count];
		count++;
	}
	return (dst);
}
