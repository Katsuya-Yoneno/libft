/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:56:16 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/25 20:02:37 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s[start]からlenの長さだけ切り取った文字列を返す関数
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		i;
	size_t		j;

	sub_str = (char *)malloc((len + 1) * sizeof(*s));
	if (!sub_str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		// startの位置までsを進める
		//lenの長さだけs[start]からコピー
		if (i >= start && j < len)
		{
			sub_str[j] = s[i];
			j++;
		}
		i++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}
