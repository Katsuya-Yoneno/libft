/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:34:43 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/01 00:39:16 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_count_word(char const *s, char c)
// {
// 	int i;
// 	int word;

// 	i = 0;
// 	word = 0;
// 	while (s && s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			word++;
// 			// 区切り文字がなければポインタを進める
// 			while (s[i] != c && s[i])
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (word);
// }

// int	ft_cal_word_size(char const *s, char c, int i)
// {
// 	int	size;
	
// 	size = 0;
// 	while (s[i] && s[i] != c)
// 	{
// 		size++;
// 		i++;
// 	}
// 	return (size);
// }

// char		**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		word;
// 	char	**split;
// 	int		word_size;
// 	int		j;

// 	i = 0;
// 	j = -1;
// 	word = ft_count_word(s, c);
// 	split = (char **)malloc((word + 1) * sizeof(char *));
// 	if (!split)
// 		return (0);
// 	while (++j < word)
// 	{
// 		while (s[i] == c)
// 			i++;
// 		word_size = ft_cal_word_size(s, c, i);
// 		split[j] = ft_substr(s, i, word_size);
// 		printf(":%s\n", split[j]);
// 		if (!split[j])
// 		{
// 			free(split);
// 			return (0);
// 		}
// 		i += word_size;
// 	}
// 	split[j] = 0;
// 	return (split);
// }

static int	ft_count_word(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	if (!(strs = (char **)malloc((word + 1) * sizeof(char *))))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		if (!(strs[j] = ft_substr(s, i, size)))
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}
