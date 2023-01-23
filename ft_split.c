/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:07:56 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/12 19:53:44 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	judge(char str, char *charset)
{
	int	i;

	i = 0;
	if (str == '\0')
		return (1);
	while (charset[i])
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*make_src(char *from, char *charset)
{
	int		i;
	char	*src;
	int		srclen;
	char	*f1;

	srclen = 0;
	f1 = from;
	while (judge(*f1, charset) == 0)
	{
		f1++;
		srclen++;
	}
	i = 0;
	src = (char *)malloc(sizeof(char) * (srclen + 1));
	while (judge(from[i], charset) == 0)
	{
		src[i] = from[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

void	judge_false(char **str, char **from, int *i, char **res)
{
	if (*str)
		(*str)++;
	if (**str == '\0')
	{
		res[*i] = make_src(*from, *str);
		(*i)++;
	}
}

void	put_res(char **res, char *str, char *charset)
{
	char	*from;
	int		i;

	from = str;
	i = 0;
	while (*str != '\0')
	{
		if (judge(*str, charset) == 1 && (str - from > 0))
		{
			res[i] = make_src(from, charset);
			str++;
			from = str;
			i++;
		}
		else if (judge(*str, charset) == 1 && (str - from <= 0))
		{
			str++;
			from = str;
		}
		else
			judge_false(&str, &from, &i, res);
	}
	res[i] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		nb_of_splits;
	char	**res;
	int		i;

	i = 0;
	nb_of_splits = 0;
	while (str[i])
	{
		if (judge(str[i], charset) == 0 && judge(str[i + 1], charset) == 1)
			nb_of_splits++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (nb_of_splits + 1));
	put_res(res, str, charset);
	return (res);
}
