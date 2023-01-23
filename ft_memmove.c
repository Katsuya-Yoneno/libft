/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:44:21 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/09 22:44:22 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			count;

	count = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
	{
		while (count < n)
		{
			(((unsigned char *)dst)[count] = ((unsigned char *)src)[count]);
			count++;
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
