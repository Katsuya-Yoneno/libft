/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:00:24 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/09 23:00:31 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			count;

	count = 0;
	temp = (unsigned char *)s;
	while (count < n)
	{
		if (temp[count] == (unsigned char)c)
			return (temp + count);
		count++;
	}
	return (0);
}
