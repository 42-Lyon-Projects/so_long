/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:30:23 by jbadaire          #+#    #+#             */
/*   Updated: 2022/11/24 14:30:23 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *source)
{
	void	*v;
	int		index;

	v = malloc(ft_strlen(source) + 1 * sizeof (char));
	if (!v)
		return (v);
	index = 0;
	while (source[index])
	{
		((char *)v)[index] = source[index];
		index++;
	}
	((char *)v)[index] = '\0';
	return (v);
}
