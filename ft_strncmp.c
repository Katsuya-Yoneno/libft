/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:56:53 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/25 02:23:10 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t	i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	
	i = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && new_s1[i] != '\0' && new_s2[i] != '\0')
	{
		if (new_s1[i] == new_s2[i])
			i++;
		else
			return (new_s1[i] - new_s2[i]);
	}
	if (i < n)
		return (new_s1[i] - new_s2[i]);
	return (0);
}
