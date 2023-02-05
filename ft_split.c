/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:34:43 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 15:33:33 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

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

int	ft_cal_word_size(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

void	ft_free_split(char **split, int j)
{
	if (!split[j])
		free(split[j]);
	return ;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**split;
	int		word_size;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	split = (char **)malloc((word + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		word_size = ft_cal_word_size(s, c, i);
		split[j] = ft_substr(s, i, word_size);
		ft_free_split (split, j);
		i += word_size;
	}
	split[j] = 0;
	return (split);
}
