/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:28:46 by jbadaire          #+#    #+#             */
/*   Updated: 2023/01/17 17:51:18 by jbadaire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mlc;
	size_t	index;
	size_t	s_size;

	if (!s || s[0] == '\0')
		return (ft_strdup(""));
	s_size = ft_strlen(s);
	if (start >= s_size)
		return (ft_strdup(""));
	if (len > (s_size - start))
		len = s_size - start;
	mlc = malloc(sizeof (char) * (len + 1));
	if (!mlc)
		return (NULL);
	index = 0;
	while (s[index] && index < len)
	{
		mlc[index] = s[start];
		start++;
		index++;
	}
	mlc[index] = '\0';
	return (mlc);
}
