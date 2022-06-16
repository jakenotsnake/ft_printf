/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:03:04 by jtanner           #+#    #+#             */
/*   Updated: 2022/06/16 18:33:11 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_uitoalen(unsigned int n)
{
	int	i;

	i = 0;
	while (!n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		i;
	long	nbr;

	i = 0;
	nbr = n;
	num = (char *)malloc(sizeof(char) * (len(nbr) + 1));
	if (!num)
		return (NULL);
	if (nbr < 0)
	{
		num[i++] = '-';
		nbr *= -1;
	}
	num = itoastr(nbr, num, &i);
	num[i] = '\0';
	return (num);
}

int	ft_printf_unsigned(unsigned int n)
{
	char	*num;
	int		i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		num = ft_uitoa(n);
		i += ft_printstr(num);
		free(num);
	}
	return (i);
}
