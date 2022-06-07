/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:15:10 by jtanner           #+#    #+#             */
/*   Updated: 2022/06/07 17:33:43 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>


void ft_printchar(int c)
{
	write(1, &c, 1);
}

int	ft_ptrlen(uintptr_t	ptr)
{
	int len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr/16;
		len ++;
	}
	return (len);
}


void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else if (ptr <= 9)
		ft_printchar(ptr + '0');
	else
		ft_printchar((ptr - 10) + 'a');
}



int	ft_printptr(unsigned long long ptr)
{
	int printlen;

	printlen = 0;
	printlen += write(1, "0x", 2);
	if (ptr == 0)
		printlen += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		printlen += ft_ptrlen(ptr);
	}
	return (printlen);
}

int main(void)
{
	unsiged *p;

	printf("\n%d\n", ft_printptr(p));
	printf("\n%p\n", p);
	return (0);
}
