/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:03:04 by jtanner           #+#    #+#             */
/*   Updated: 2022/06/02 13:49:37 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_uitoalen(unsigned int n)
{
	int	i;

	i = 0;
	while (!n)
	{
		n = n / 10;
		i++;
	}
	return(i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int	len;

	len = ft_uitoalen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return(0);
	else
		num[len] = '\0';
	while (n != 0)
	{
		num[len-1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return(num);
}

int	ft_printf_unsigned(unsigned int n)
{
	char	*num;
	int	i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return(1);
	}
	else
	{
		num = ft_uitoa(n);
		i += ft_putstr(num);
		free(num);
	}
	return(i);
}
