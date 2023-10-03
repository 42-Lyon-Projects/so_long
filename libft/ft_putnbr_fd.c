/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:30:42 by jbadaire          #+#    #+#             */
/*   Updated: 2022/11/24 17:05:37 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			ch;

	nb = (unsigned int)n;
	if (n < 0)
	{
		nb = nb * -1;
		write (fd, "-", 1);
	}
	if (nb <= 9)
	{
		ch = nb + '0';
		write(fd, &ch, 1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
