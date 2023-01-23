/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:22:20 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/11 00:00:21 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		new_len;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (s1 == NULL || set == NULL)
		return (0);
	while (start <= end && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	new_len = end - start + 1;
	trimmed = (char *)malloc(new_len * sizeof(char) + 1);
	if (!trimmed)
		return (0);
	ft_memcpy(trimmed, s1 + start, new_len);
	trimmed[new_len] = '\0';
	return (trimmed);
}
