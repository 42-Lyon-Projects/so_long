/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:38 by jbadaire          #+#    #+#             */
/*   Updated: 2023/01/17 17:57:42 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*t;

	if (count > 0 && size > SIZE_MAX / count)
		return (0);
	t = malloc(count * size);
	if (t != NULL)
		ft_bzero(t, count * size);
	return (t);
}
