/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:24:32 by mohammoh          #+#    #+#             */
/*   Updated: 2023/07/10 22:24:32 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long)); 
	else if (format == 'd')
		print_length += ft_print_nbr(va_arg(args, long long));
	else if (format == 'i')
		print_length += ft_print_nbr(va_arg(args, long long));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		print_length += ft_print_precent();
	else
		print_length += ft_print_str("Error: Unrecognized format specifier");
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_length;
	va_list	args;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++; 
		}
		else
			print_length += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
