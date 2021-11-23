/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:35:15 by chelmerd          #+#    #+#             */
/*   Updated: 2021/11/23 10:43:10 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	main(void)
{
	char	c;
	int		error;

	error = 0;
	c = 0;
	printf("Testing ft_isalpha\n");
	while (c <= 200 && error == 0)
	{
		if ((isalpha(c) == ft_isalpha(c))
			|| (isalpha(c) > 0 && ft_isalpha(c) > 0))
			error = 0;
		else
			error = 1;
	}
	if (error)
		printf("KO");
}
