/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:41:37 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 14:05:21 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			all;
	size_t			i;

	if (nmemb > SIZE_MAX / size)
		return (0);
	all = nmemb * size;
	printf("all	: %zu\n", all);
	ptr = (void *)malloc(all);
	if (!ptr)
		return (0);
	i = 0;
	while (i < all)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
