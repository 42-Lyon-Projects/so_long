/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:39:32 by jbadaire          #+#    #+#             */
/*   Updated: 2023/09/18 08:23:56 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_args_handler(char c, va_list params)
{
	int	value;

	value = 0;
	if (c == 'c')
		value = ft_get_char(params);
	else if (c == 's')
		value = ft_get_string(params);
	else if (c == 'u')
		value = ft_get_unsigned_integer(params);
	else if (c == 'd' || c == 'i')
		value = ft_get_integer(params);
	else if (c == 'x')
		value = ft_get_base16(params, "0123456789abcdef");
	else if (c == 'X')
		value = ft_get_base16(params, "0123456789ABCDEF");
	else if (c == 'p')
		value = ft_get_address(params, "0123456789abcdef");
	else if (c == '%')
		value = ft_putchar_fd('%', 1);
	return (value);
}
