/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:21:53 by jbadaire          #+#    #+#             */
/*   Updated: 2023/09/18 08:54:49 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_get_address(va_list param, char *base_array)
{
	size_t		number;
	int			value;

	number = va_arg(param, size_t);
	value = 0;
	if (number == 0)
		return (ft_putstr_fd("(nil)", 1));
	value += ft_putstr_fd("0x", 1);
	value += ft_base(number, 16, base_array, 0);
	return (value);
}
