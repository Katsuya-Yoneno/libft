/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:44:21 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 15:27:30 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

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
