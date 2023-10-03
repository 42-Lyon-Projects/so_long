/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:28:54 by jbadaire          #+#    #+#             */
/*   Updated: 2023/01/17 17:50:41 by jbadaire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = (int)ft_strlen(s);
	while (index >= 0)
	{
		if ((unsigned char )s[index] == (char)c)
		{
			return ((char *) s + index);
		}
		index--;
	}
	return (NULL);
}
