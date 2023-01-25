/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:26:22 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/25 22:35:04 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//文字列sの文字それぞれに第二引数の関数fを適用する関数。fが正常に適用できた文字からのポインタを返す。
char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	char	*res;
	unsigned int		i;

	i = 0;
	if (!s[i] || !f)
		return (0);
	while (s[i])
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int main(void){
// 	char *s = ft_strmapi("abcdef", ft_tolower);
// 	printf("%s\n", s);
// 	free(s);
// 	return 0;
// }