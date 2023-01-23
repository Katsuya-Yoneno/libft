/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:03:51 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/09 23:05:02 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	num;
	int	counter;

	num = 0;
	counter = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
	{
		str++;
	}
	while (*str == '+' || *str == '-' )
	{
		if (*str == '-')
			counter++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (counter % 2 == 1)
		num = 0 - num;
	return (num);
}
