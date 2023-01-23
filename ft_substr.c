/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:56:16 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/10 00:22:50 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	char	*cut_str;
	size_t		i;

	length = len - start + 1;
	cut_str = malloc(length + 1);
	if (cut_str == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		cut_str[i] = s[start + i];
		i++;
	}
	return (cut_str);
}
