/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:18:11 by mohammoh          #+#    #+#             */
/*   Updated: 2023/07/10 22:18:11 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, format);
		ft_put_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + 48), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((n - 10) + 'a', 1);
			else if (format == 'X')
				ft_putchar_fd((n - 10) + 'A', 1);
		}
	}
}

int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
		ft_putchar_fd('0', 1);
	else
		ft_put_hex(n, format);
	return (ft_hex_len(n));
}

int	ft_print_precent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
