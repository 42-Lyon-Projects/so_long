/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:47 by jbadaire          #+#    #+#             */
/*   Updated: 2023/01/17 17:11:31 by jbadaire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(int character)
{
	return ((character >= 9 && character <= 13) || character == ' ');
}

static int	ft_is_sign(int character)
{
	return (character == '+' || character == '-');
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	is_pos;

	index = 0;
	is_pos = 1;
	result = 0;
	while (ft_is_space(nptr[index]))
		index++;
	while (ft_is_sign(nptr[index]))
	{
		if (index > 0 && ft_is_sign(nptr[index -1]))
			return (0);
		if (nptr[index++] == '-')
			is_pos = 0;
	}
	while (ft_isdigit(nptr[index]))
	{
		if (result != ((result * 10 + (is_pos * (nptr[index] - '0'))) / 10))
			return ((int)((is_pos + 1) / 2 / -1));
		result = result * 10 + (nptr[index++] - 48);
	}
	if (!is_pos)
		result = 0 - result;
	return (result);
}
