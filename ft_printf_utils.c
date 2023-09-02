/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:24:38 by mohammoh          #+#    #+#             */
/*   Updated: 2023/07/10 22:24:38 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

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

char	*ft_itoa(int n)
{
	long		size;
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
	if (n < 0)
	{
		nbr[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		nbr[--size] = base[num % 10];
		num /= 10;
	}
	return (nbr);
}

int	ft_print_nbr(long long n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_str(num);
	free (num);
	return (len);
}
