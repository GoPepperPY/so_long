/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:24:37 by goda-sil          #+#    #+#             */
/*   Updated: 2022/11/22 10:43:53 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	counter_one;
	unsigned int	counter_two;
	char			*pointer;

	counter_one = 0;
	if (!s1 || !s2)
		return (NULL);
	pointer = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (pointer == NULL)
		return (NULL);
	while (s1[counter_one])
	{
		pointer[counter_one] = s1[counter_one];
		counter_one++;
	}
	counter_two = 0;
	while (s2[counter_two])
	{
		pointer[counter_one] = s2[counter_two];
		counter_one++;
		counter_two++;
	}
	pointer[counter_one] = '\0';
	return (pointer);
}
/*
int		main()
{
	char *str1 = "tiago";
	char *str2 = "santos";
	char *str3;

	printf("%s\n%s\n", str1, str2);

	str3 = ft_strjoin(str1, str2);

	printf("%s", str3);
	return (0);
}*/
