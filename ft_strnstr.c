/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:01:04 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/25 18:21:18 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			len_little;
	size_t		i;

	i = 0;
	len_little = ft_strlen((char *)little);

	// littleがnullだった場合にbigを返す
	if (len_little == 0)
		return ((char *)big);
	// littleの長さが探す文字数よりも長い場合にnullを返す
	if (len_little > len)
		return (0);
	// 探す回数はlen-littleの文字数
	while (i <= len - len_little)
	{
		if (ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	return (0);
}
