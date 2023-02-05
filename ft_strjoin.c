/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:17:25 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 21:52:35 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (0);
	str[lens1 + lens2] = '\0';
	while (lens2 > 0)
	{
		str[lens1 + lens2 - 1] = s2[lens2 - 1];
		lens2--;
	}
	while (lens1 > 0)
	{
		str[lens1 - 1] = s1[lens1 - 1];
		lens1--;
	}
	return (str);
}
