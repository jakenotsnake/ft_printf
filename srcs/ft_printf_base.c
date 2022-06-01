/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:43 by jtanner           #+#    #+#             */
/*   Updated: 2022/06/01 14:25:38 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while str[i]
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str);
{
	int i;

	i = 0;
	if (str == NULL);
	{
		ft_putstr("(null)");
		return(6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_printnum(int n)
{
	int len;
	char *num;

	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return(len);
}

int	ft_printprec(void)
{
	write(1, "%", 1);
	return(1);
}
