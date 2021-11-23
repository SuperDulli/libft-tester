/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:35:15 by chelmerd          #+#    #+#             */
/*   Updated: 2021/11/23 11:18:44 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include <stdio.h>

static int	test_char_testers(int (*ft)(int), int (*system_f)(int));

int	main(void)
{
	int	error;

	error = 0;
	printf("Testing ft_isalpha\n");
	error = test_char_testers(&ft_isalpha, &isalpha);
	printf("Testing ft_isdigit\n");
	error = test_char_testers(&ft_isdigit, &isdigit);
	printf("Testing ft_isalnum\n");
	error = test_char_testers(&ft_isalnum, &isalnum);
	printf("Testing ft_isascii\n");
	error = test_char_testers(&ft_isascii, &isascii);
	printf("Testing ft_isprint\n");
	error = test_char_testers(&ft_isprint, &isprint);
	return (error);
}

static int	test_char_testers(int (*ft)(int), int (*system_f)(int))
{
	int	c;
	int	error;

	error = 0;
	c = -1;
	while (c <= 200 && error == 0)
	{
		if (((ft)(c) == (system_f)(c))
			|| ((ft)(c) > 0 && (system_f)(c) > 0))
			c++;
		else
		{
			printf("error while trying to test value %d\n", c);
			error = 1;
		}
	}
	if (error)
		printf("KO\n");
	else
		printf("OK\n");
	printf("*****\n\n");
	return (error);
}
