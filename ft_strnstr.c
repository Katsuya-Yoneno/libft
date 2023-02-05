/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:01:04 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 15:36:50 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		len_little;
	size_t		i;

	i = 0;
	len_little = ft_strlen((char *)little);
	if (len_little == 0)
		return ((char *)big);
	if (len_little > len)
		return (0);
	while (i <= len - len_little)
	{
		if (ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	return (0);
}
