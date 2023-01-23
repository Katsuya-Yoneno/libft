/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:26:22 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/18 22:26:00 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	char	*res;
	unsigned int		i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	res = (char *)malloc(i * sizeof(char));
	if (!res)
		return (0);
	while (i > 0)
	{
		res[i] = f(i, s[i]);
		i--;
	}
	return (res);
}
