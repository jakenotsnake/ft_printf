/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:15:24 by jtanner           #+#    #+#             */
/*   Updated: 2022/06/16 19:35:08 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
int		ft_printchar(int c);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnum(int n);
int		ft_printperc(void);
int		ft_hexlen(unsigned int n);
void	ft_puthex(unsigned int ptr, char format);
int		ft_printhex(unsigned int n, char format);
int		ft_ptrlen(uintptr_t ptr);
void	ft_putptr(uintptr_t ptr);
int		ft_printptr(unsigned long long ptr);
int		ft_uitoalen(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_printf_unsigned(unsigned int n);
int		len(long nb);
char	*ft_itoa(int n);
char 	*itoastr(long n, char *str, int *i);
#endif
