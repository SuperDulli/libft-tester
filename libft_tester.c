/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:35:15 by chelmerd          #+#    #+#             */
/*   Updated: 2021/11/23 13:49:31 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

static int	test_char_testers(int (*ft)(int), int (*system_f)(int));
static int	test_strlen(void);
static int	test_memset(void);
static int	test_bzero(void);
static int	test_memcpy(void);
static int	test_memmove(void);
static int	test_strlcpy(void);
static int	test_strlcat(void);
static int	test_toupper(void);
static int	test_tolower(void);
static int	test_strchr(void);
static int	test_strrchr(void);


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
	printf("Testing ft_strlen\n");
	error = test_strlen();
	printf("Testing ft_memset\n");
	error = test_memset();
	printf("Testing ft_bzero\n");
	error = test_bzero();
	printf("Testing ft_memcpy\n");
	error = test_memcpy();
	printf("Testing ft_memmove\n");
	error = test_memmove();
	printf("Testing ft_strlcpy\n");
	error = test_strlcpy();
	printf("Testing ft_strlcat\n");
	error = test_strlcat();
	printf("Testing ft_toupper\n");
	error = test_toupper();
	printf("Testing ft_tolower\n");
	error = test_tolower();
	printf("Testing ft_strchr\n");
	error = test_strchr();
	printf("Testing ft_strrchr\n");
	error = test_strrchr();
	return (error);
}

static void	print_result(int error)
{
	if (error == 0)
		printf("OK\n");
	else
		printf("\033[1;31m KO with error %d\n\033[0m", error);
	printf("*****\n\n");
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
	print_result(error);
	return (error);
}

static int	test_strlen(void)
{
	int		error;
	char	*str;

	error = 0;
	str = "123";
	if ((ft_strlen(str) == strlen(str))
		|| (ft_strlen("") == strlen(""))
		|| (ft_strlen(NULL) == strlen(NULL))
		|| (ft_strlen("test\0hidden") == strlen("test\0hidden")))
		error = 0;
	else
		error = 1;
	print_result(error);
	return (error);
}

static int	test_memset(void)
{
	int		error;
	char	tab[100];
	int		i;

	error = 0;
	memset(tab, 0, 100);
	ft_memset(tab, 'A', 0);
	if (tab[0] != 0)
		error = 1;
	ft_memset(tab, 'A', 42);
	i = 0;
	while (i < 100 && tab[i] == 'A')
	{
		i++;
	}
	if (i != 42 || tab[42] != 0)
		error = 2;
	print_result(error);
	return (error);
}

static int	test_bzero(void)
{
	int		error;
	char	tab[100];
	int		i;

	error = 0;
	// 1
	memset(tab, 'A', 100);
	ft_bzero(tab, 0);
	if (tab[0] != 'A')
		error = 1;
	// 2
	ft_bzero(tab, 42);
	i = 0;
	while (i < 100 && tab[i] == 0)
	{
		i++;
	}
	if (i != 42 || tab[42] != 'A')
		error = 2;
	// 3
	memset(tab, 'A', 100);
	tab[0] = 0;
	ft_bzero(tab, 42);
	i = 0;
	while (i < 100 && tab[i] == 0)
	{
		i++;
	}
	if (i != 42 || tab[42] != 'A')
		error = 3;
	print_result(error);
	return (error);
}

static int	test_memcpy(void)
{
	int		error;
	char	str[20];
	char	dst[20];

	error = 0;
	// 1
	strcpy(str, "Hello World!");
	ft_memcpy(str, str + 6, 5);
	if (strncmp(str, "World World!", 12) != 0)
		error = 1;
	// 2
	memset(dst, 'A', 20);
	ft_memcpy(dst, "something", 0);
	if (dst[0] != 'A')
		error = 2;
	print_result(error);
	return (error);
}

static int	test_memmove(void)
{
	int		error;
	char	str[20];
	char	dst[20];

	error = 0;
	// 1
	strcpy(str, "Hello World!");
	ft_memmove(str, str + 6, 5);
	if (strncmp(str, "World World!", 12) != 0)
		error = 1;
	// 2
	memset(dst, 'A', 20);
	ft_memmove(dst, "something", 0);
	if (dst[0] != 'A')
		error = 2;
	// 3
	strcpy(str, "Hello World!");
	ft_memmove(str + 2, str, 5);
	if (strcmp(str, "HeHelloorld!") != 0)
		error = 3;
	// 4
	strcpy(str, "Hello World!");
	ft_memmove(str, str + 2, 5);
	if (strcmp(str, "llo W World!") != 0)
		error = 4;
	print_result(error);
	return (error);
}

static int	test_strlcpy(void)
{
	int		error;
	char	*str;
	char	dst[20];
	char	dst2[20];
	size_t	r1;
	size_t	r2;

	error = 0;
	str = "Hello World!";
	// 1
	memset(dst, 'A', 20);
	r1 = ft_strlcpy(dst, str, 0);
	if (dst[0] != 'A')
		error = 1;
	// 2
	r2 = strlcpy(dst, str, 0);
	if (r1 != r2)
		error = 2;
	// 3
	memset(dst, 'A', 20);
	memset(dst2, 'A', 20);
	r1 = ft_strlcpy(dst, str, 5);
	r2 = strlcpy(dst2, str, 5);
	if (memcmp(dst, dst2, 20) != 0 || r1 != r2)
		error = 3;
	// 4
	memset(dst, 'A', 20);
	memset(dst2, 'A', 20);
	r1 = ft_strlcpy(dst, str, 13);
	r2 = strlcpy(dst2, str, 13);
	if (memcmp(dst, dst2, 20) != 0 || r1 != r2)
		error = 4;
	// 5
	memset(dst, 'A', 20);
	memset(dst2, 'A', 20);
	r1 = ft_strlcpy(dst, str, 14);
	r2 = strlcpy(dst2, str, 14);
	if (memcmp(dst, dst2, 20) != 0 || r1 != r2)
		error = 5;
	// 6
	memset(dst, 'A', 20);
	memset(dst2, 'A', 20);
	r1 = ft_strlcpy(dst, "", 5);
	r2 = strlcpy(dst2, "", 5);
	if (memcmp(dst, dst2, 20) != 0 || r1 != r2)
		error = 3;
	print_result(error);
	return (error);
}

static int	test_strlcat(void)
{
	int		error;
	char	*str;
	char	dst[20];
	char	dst2[20];
	size_t	r1;
	size_t	r2;

	error = 0;
	str = "World!";
	// 1
	memset(dst, 'A', 20);
	strcpy(dst, "Hello");
	strcpy(dst2, "Hello");
	r1 = ft_strlcat(dst, str, 0);
	if (dst[0] != 'H')
		error = 1;
	// 2
	r2 = strlcat(dst, str, 0);
	if (r1 != r2)
		error = 2;
	// 3
	memset(dst, 'A', 20);
	memset(dst2, 'A', 20);
	strcpy(dst, "Hello");
	strcpy(dst2, "Hello");
	r1 = ft_strlcat(dst, str, 5);
	r2 = strlcat(dst2, str, 5);
	if (memcmp(dst, dst2, 20) != 0 || r1 != r2)
		error = 3;
	// 4
	memset(dst, 'A', 20);
	memset(dst2, 'A', 20);
	strcpy(dst, "Hello");
	strcpy(dst2, "Hello");
	r1 = ft_strlcat(dst, str, 13);
	r2 = strlcat(dst2, str, 13);
	if (memcmp(dst, dst2, 20) != 0 || r1 != r2)
		error = 4;
	// 5
	memset(dst, 'A', 20);
	memset(dst2, 'A', 20);
	strcpy(dst, "Hello");
	strcpy(dst2, "Hello");
	r1 = ft_strlcat(dst, str, 14);
	r2 = strlcat(dst2, str, 14);
	if (memcmp(dst, dst2, 20) != 0 || r1 != r2)
		error = 5;
	// 6
	memset(dst, 'A', 20);
	memset(dst2, 'A', 20);
	strcpy(dst, "Hello");
	strcpy(dst2, "Hello");
	r1 = ft_strlcat(dst, "", 5);
	r2 = strlcat(dst2, "", 5);
	if (memcmp(dst, dst2, 20) != 0 || r1 != r2)
		error = 3;
	print_result(error);
	return (error);
}

static int	test_toupper(void)
{
	int	error;
	int	c;
	int r1;
	int	r2;

	error = 0;
	// 1
	c = 'a';
	r1 = ft_toupper(c);
	r2 = toupper(c);
	if (r1 != r2)
		error = 1;
	// 2
	c = 'A';
	r1 = ft_toupper(c);
	r2 = toupper(c);
	if (r1 != r2)
		error = 2;
	// 3
	c = ' ';
	r1 = ft_toupper(c);
	r2 = toupper(c);
	if (r1 != r2)
		error = 3;
	// 4
	c = '%';
	r1 = ft_toupper(c);
	r2 = toupper(c);
	if (r1 != r2)
		error = 4;
	// 5
	c = -1;
	r1 = ft_toupper(c);
	r2 = toupper(c);
	if (r1 != r2)
		error = 5;
	print_result(error);
	return (error);
}

static int	test_tolower(void)
{
	int	error;
	int	c;
	int r1;
	int	r2;

	error = 0;
	// 1
	c = 'a';
	r1 = ft_tolower(c);
	r2 = tolower(c);
	if (r1 != r2)
		error = 1;
	// 2
	c = 'A';
	r1 = ft_tolower(c);
	r2 = tolower(c);
	if (r1 != r2)
		error = 2;
	// 3
	c = ' ';
	r1 = ft_tolower(c);
	r2 = tolower(c);
	if (r1 != r2)
		error = 3;
	// 4
	c = '%';
	r1 = ft_tolower(c);
	r2 = tolower(c);
	if (r1 != r2)
		error = 4;
	// 5
	c = -1;
	r1 = ft_tolower(c);
	r2 = tolower(c);
	if (r1 != r2)
		error = 5;
	print_result(error);
	return (error);
}

static int	test_strchr(void)
{
	int			error;
	const char	*str;
	int			c;
	char		*r1;
	char		*r2;

	error = 0;
	// 1
	str = "Hello World!";
	c = 'l';
	r1 = ft_strchr(str, c);
	r2 = strchr(str, c);
	if (r1 != r2)
		error = 1;
	// 2
	c = '\0';
	r1 = ft_strchr(str, c);
	r2 = strchr(str, c);
	if (r1 != r2)
		error = 2;
	// 3
	str = "Hello \0World!";
	c = '!';
	r1 = ft_strchr(str, c);
	r2 = strchr(str, c);
	if (r1 != r2)
		error = 3;
	// 4
	str = "";
	c = '!';
	r1 = ft_strchr(str, c);
	r2 = strchr(str, c);
	if (r1 != r2)
		error = 4;
	// 5
	str = "";
	c = '\0';
	r1 = ft_strchr(str, c);
	r2 = strchr(str, c);
	if (r1 != r2)
		error = 5;
	// 6
	c = 'l' + 256;
	r1 = ft_strchr(str, c);
	r2 = strchr(str, c);
	if (r1 != r2)
		error = 6;
	print_result(error);
	return (error);
}

static int	test_strrchr(void)
{
	int			error;
	const char	*str;
	int			c;
	char		*r1;
	char		*r2;

	error = 0;
	// 1
	str = "Hello World!";
	c = 'l';
	r1 = ft_strrchr(str, c);
	r2 = strrchr(str, c);
	if (r1 != r2)
		error = 1;
	// 2
	c = '\0';
	r1 = ft_strrchr(str, c);
	r2 = strrchr(str, c);
	if (r1 != r2)
		error = 2;
	// 3
	str = "Hello \0World!";
	c = '!';
	r1 = ft_strrchr(str, c);
	r2 = strrchr(str, c);
	if (r1 != r2)
		error = 3;
	// 4
	str = "";
	c = '!';
	r1 = ft_strrchr(str, c);
	r2 = strrchr(str, c);
	if (r1 != r2)
		error = 4;
	// 5
	str = "";
	c = '\0';
	r1 = ft_strrchr(str, c);
	r2 = strrchr(str, c);
	if (r1 != r2)
		error = 5;
	// 6
	c = 'l' + 256;
	r1 = ft_strrchr(str, c);
	r2 = strrchr(str, c);
	if (r1 != r2)
		error = 6;
	print_result(error);
	return (error);
}