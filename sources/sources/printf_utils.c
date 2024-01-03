/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:13 by goda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 18:19:03 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_string(char *string)
{
	int	counter;

	counter = 0;
	if (string == NULL)
		return (write(1, "(null)", 6));
	while (string[counter])
	{
		write(1, &string[counter], 1);
		counter++;
	}
	return (counter);
}

int	print_decimal_integer(long number)
{
	char	character;
	int		length;

	length = 0;
	if (number < 0)
	{
		length += write(1, "-", 1);
		number = number * -1;
	}
	if (number > 9)
	{
		length += print_decimal_integer(number / 10);
		length += print_decimal_integer(number % 10);
	}
	else
	{
		character = number + '0';
		length += write(1, &character, 1);
	}
	return (length);
}

int	print_decimal_unsigned(unsigned int number)
{
	char	character;
	int		length;

	length = 0;
	if (number > 9)
	{
		length += print_decimal_integer(number / 10);
		length += print_decimal_integer(number % 10);
	}
	else
	{
		character = number + '0';
		length += write(1, &character, 1);
	}
	return (length);
}

int	print_hex(unsigned int number, char type)
{
	int	length;

	length = 0;
	if (number >= 16)
	{
		length += print_hex((number / 16), type);
		length += print_hex((number % 16), type);
	}
	else
	{
		if (number <= 9)
		{
			number = number + '0';
			length += write(1, &number, 1);
		}
		else
			length += put_hex(number, type);
	}
	return (length);
}

int	put_hex(unsigned int number, char type)
{
	int		length;
	char	character;

	length = 0;
	if (type == 'x')
		character = number - 10 + 'a';
	if (type == 'X')
		character = number - 10 + 'A';
	length += write(1, &character, 1);
	return (length);
}
