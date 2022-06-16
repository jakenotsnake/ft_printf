/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:26:00 by jtanner           #+#    #+#             */
/*   Updated: 2022/06/16 19:00:26 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_puthex(unsigned int ptr, char format)
{
	if (format == 'x')
	{
		if (ptr >= 16)
		{
			ft_puthex(ptr / 16, format);
			ft_puthex(ptr % 16, format);
		}
		else if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar((ptr - 10) + 'a');
	}
	if (format == 'X')
	{
		if (ptr >= 16)
		{
			ft_puthex(ptr / 16, format);
			ft_puthex(ptr % 16, format);
		}
		else if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar((ptr - 10) + 'A');
	}
}

int	ft_printhex(unsigned int n, char format)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_puthex(n, format);
	i += ft_hexlen(n);
	return (i);
}
