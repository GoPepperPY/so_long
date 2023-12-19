/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:20:28 by goda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 18:19:07 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	pointer_length(unsigned long long pointer)
{
	int	length;

	length = 0;
	while (pointer != 0)
	{
		pointer = pointer / 16;
		length++;
	}
	return (length);
}

int	print_pointer_two(unsigned long long pointer)
{
	char	character;
	int		length;

	length = 0;
	if (pointer >= 16)
	{
		length += print_pointer_two(pointer / 16);
		length += print_pointer_two(pointer % 16);
	}
	else
	{
		if (pointer <= 9)
		{
			character = pointer + '0';
			length += write(1, &character, 1);
		}
		else
		{
			character = pointer - 10 + 'a';
			length += write(1, &character, 1);
		}
	}
	return (length);
}

int	print_pointer(unsigned long long pointer)
{
	int	length;

	length = 0;
	if (pointer == 0)
		length = length + write(1, "(nil)", 5);
	else
	{
		length = length + write(1, "0x", 2);
		print_pointer_two(pointer);
		length += pointer_length(pointer);
	}
	return (length);
}
