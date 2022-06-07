/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:26:00 by jtanner           #+#    #+#             */
/*   Updated: 2022/06/07 14:08:49 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_hexlen(unsigned int	n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n/16;
		i++;
	}
	return (i);
}

void	ft_puthex(unsigned int n, format)
{
	if (format == 'x')
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
	if (format == 'X')
	{
		if (ptr >= 16)
		{
			ft_putptr(ptr / 16);
			ft_putptr(ptr % 16);         
		}
		else if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar((ptr - 10) + 'A');
	}
}
int	ft_printhex(unsigned int n, format)
{
	int i;
	
	i = 0;
 	i += write(1, "0x", 2);
	ft_puthex(n, format);
	i += ft_hexlen(n);
	return(i);
}
