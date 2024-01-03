/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:35 by goda-sil          #+#    #+#             */
/*   Updated: 2022/11/21 11:31:35 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
		((unsigned char *)s)[counter++] = '\0';
}
