/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:08:19 by jbadaire          #+#    #+#             */
/*   Updated: 2023/01/17 17:50:54 by jbadaire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s_start;
	int		s_end;
	char	*mlc;

	s_start = 0;
	s_end = (int)ft_strlen(s1);
	while (s_start < s_end && ft_strchr(set, s1[s_start]) != NULL)
		s_start++;
	while (s_end > s_start && ft_strchr(set, s1[s_end - 1]) != NULL)
		s_end--;
	mlc = malloc(sizeof(char) * s_end - s_start + 1);
	if (!mlc)
		return (NULL);
	ft_memcpy(mlc, s1 + s_start, s_end - s_start);
	mlc[s_end - s_start] = *"\0";
	return (mlc);
}
