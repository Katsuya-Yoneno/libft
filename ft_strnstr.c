/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:01:04 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/25 02:18:36 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			size_little;
	const char	*end;

	if (len == 0)
		return (0);
	if (!little)
		return ((char *)big);
	size_little = ft_strlen((char *)little);
	end = big + len;
	while (big < end)
	{
		if (*big == *little)
		{
			if (ft_memcmp(big, little, size_little) == 0)
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
