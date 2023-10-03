/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:49:43 by jbadaire          #+#    #+#             */
/*   Updated: 2023/01/17 17:49:46 by jbadaire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		index;
	char				*mlc;

	index = 0;
	mlc = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!mlc)
		return (NULL);
	while (s[index])
	{
		mlc[index] = f(index, s[index]);
		index++;
	}
	mlc[index] = '\0';
	return (mlc);
}
