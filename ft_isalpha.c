/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:03:56 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/09 22:24:31 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(char *str)
{
	int	i;
	int	res;

	i = 0;
	if (str[0] == '\0')
		res = 1;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
			res = 1;
		else if ('A' <= str[i] && str[i] <= 'Z')
			res = 1;
		else
		{
			res = 0;
			break ;
		}
		i++;
	}
	return (res);
}
