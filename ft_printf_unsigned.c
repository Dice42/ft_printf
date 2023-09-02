/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:24:27 by mohammoh          #+#    #+#             */
/*   Updated: 2023/07/10 22:24:27 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(long n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_uitoa(unsigned int n)
{
	int			size;
	long		num;
	char		*nbr;
	const char	*base;

	num = n;
	base = "0123456789";
	size = get_size(num);
	nbr = (char *)malloc(sizeof(char) * (size + 1));
	if (!nbr)
		return (0);
	nbr[size] = 0;
	if (n == 0)
		nbr[0] = '0';
	while (num > 0)
	{
		nbr[--size] = base[num % 10];
		num /= 10;
	}
	return (nbr);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += ft_print_char('0');
	else
	{
		num = ft_uitoa(n);
		print_length += ft_print_str(num);
		free(num);
	}
	return (print_length);
}
