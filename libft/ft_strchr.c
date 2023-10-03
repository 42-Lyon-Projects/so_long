/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:30:28 by jbadaire          #+#    #+#             */
/*   Updated: 2023/01/17 16:52:20 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	if ((char)c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while ((char)s[index])
	{
		if ((char)s[index] == (char)c)
			return ((char *) s + index);
		index++;
	}
	return (NULL);
}
