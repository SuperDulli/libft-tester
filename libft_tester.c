/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:35:15 by chelmerd          #+#    #+#             */
/*   Updated: 2021/11/25 13:09:38 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

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
static int	test_strncmp(void);
static int	test_memchr(void);
static int	test_memcmp(void);
static int	test_strnstr(void);
static int	test_atoi(void);
static int	test_calloc(void);
static int	test_strdup(void);
static int	test_substr(void);
static int	test_strjoin(void);
static int	test_strtrim(void);
static int	test_split(void);
static int	test_itoa(void);
static int	test_strmapi(void);
static int	test_striteri(void);
static int	test_putchar_fd(void);
static int	test_putstr_fd(void);
static int	test_putendl_fd(void);
static int	test_putnbr_fd(void);

int	main(void)
{
	int	error;

	error = 0;
	printf("Testing ft_isalpha\n");
	error += test_char_testers(&ft_isalpha, &isalpha);
	printf("Testing ft_isdigit\n");
	error += test_char_testers(&ft_isdigit, &isdigit);
	printf("Testing ft_isalnum\n");
	error += test_char_testers(&ft_isalnum, &isalnum);
	printf("Testing ft_isascii\n");
	error += test_char_testers(&ft_isascii, &isascii);
	printf("Testing ft_isprint\n");
	error += test_char_testers(&ft_isprint, &isprint);
	printf("Testing ft_strlen\n");
	error += test_strlen();
	printf("Testing ft_memset\n");
	error += test_memset();
	printf("Testing ft_bzero\n");
	error += test_bzero();
	printf("Testing ft_memcpy\n");
	error += test_memcpy();
	printf("Testing ft_memmove\n");
	error += test_memmove();
	printf("Testing ft_strlcpy\n");
	error += test_strlcpy();
	printf("Testing ft_strlcat\n");
	error += test_strlcat();
	printf("Testing ft_toupper\n");
	error += test_toupper();
	printf("Testing ft_tolower\n");
	error += test_tolower();
	printf("Testing ft_strchr\n");
	error += test_strchr();
	printf("Testing ft_strrchr\n");
	error += test_strrchr();
	printf("Testing ft_strncmp\n");
	error += test_strncmp();
	printf("Testing ft_memchr\n");
	error += test_memchr();
	printf("Testing ft_memcmp\n");
	error += test_memcmp();
	printf("Testing ft_strnstr\n");
	error += test_strnstr();
	printf("Testing ft_atoi\n");
	error += test_atoi();
	printf("Testing ft_calloc\n");
	error += test_calloc();
	printf("Testing ft_strdup\n");
	error += test_strdup();
	printf("Testing ft_substr\n");
	error += test_substr();
	printf("Testing ft_strjoin\n");
	error += test_strjoin();
	printf("Testing ft_strtrim\n");
	error += test_strtrim();
	printf("Testing ft_split\n");
	error += test_split();
	printf("Testing ft_itoa\n");
	error += test_itoa();
	printf("Testing ft_strmapi\n");
	error += test_strmapi();
	printf("Testing ft_striteri\n");
	error += test_striteri();
	printf("Testing ft_putchar_fd\n");
	error += test_putchar_fd();
	printf("Testing ft_putstr_fd\n");
	error += test_putstr_fd();
	printf("Testing ft_putendl_fd\n");
	error += test_putendl_fd();
	printf("Testing ft_putnbr_fd\n");
	error += test_putnbr_fd();
	printf("Total error value: %d\n", error);
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

static int	test_strncmp(void)
{
	int			error;
	const char	*s1;
	const char	*s2;
	int			r1;
	int			r2;

	error = 0;
	// 1
	s1 = "Hello World!";
	s1 = "Hello World!";
	r1 = ft_strncmp(s1, s2, 13);
	r2 = strncmp(s1, s2, 13);
	if (r1 != r2)
		error = 1;
	// 2
	s1 = "Hello World!";
	s1 = "Hello world!";
	r1 = ft_strncmp(s1, s2, 13);
	r2 = strncmp(s1, s2, 13);
	if (r1 != r2)
		error = 2;
	// 3
	s1 = "Hello world!";
	s1 = "Hello World!";
	r1 = ft_strncmp(s1, s2, 13);
	r2 = strncmp(s1, s2, 13);
	if (r1 != r2)
		error = 3;
	// 4
	s1 = "Hello world!";
	s1 = "Hello World!";
	r1 = ft_strncmp(s1, s2, 5);
	r2 = strncmp(s1, s2, 5);
	if (r1 != r2)
		error = 4;
	// 5
	s1 = "Hello!";
	s1 = "Hello World!";
	r1 = ft_strncmp(s1, s2, 13);
	r2 = strncmp(s1, s2, 13);
	if (r1 != r2)
		error = 5;
	s1 = "Hello World!\0 this is not here!";
	s1 = "Hello World!\0 different content";
	r1 = ft_strncmp(s1, s2, 32);
	r2 = strncmp(s1, s2, 32);
	if (r1 != r2)
		error = 5;
	print_result(error);
	return (error);
}

static int	test_memchr(void)
{
	int		error;
	char	str[20];
	int		c;
	char	*r1;
	char	*r2;

	error = 0;
	memset(str, 'A', 20);
	strcpy(str, "Hello World!");
	// 1
	c = 'l';
	r1 = ft_memchr(str, c, 0);
	r2 = memchr(str, c, 0);
	if (r1 != r2)
		error = 1;
	// 2
	r1 = ft_memchr(str, c, 20);
	r2 = memchr(str, c, 20);
	if (r1 != r2)
		error = 2;
	// 3
	c = 0;
	r1 = ft_memchr(str, c, 20);
	r2 = memchr(str, c, 20);
	if (r1 != r2)
		error = 3;
	// 4
	c = 'A';
	r1 = ft_memchr(str, c, 20);
	r2 = memchr(str, c, 20);
	if (r1 != r2)
		error = 4;
	// 5
	c = 'A';
	r1 = ft_memchr("", c, 20);
	r2 = memchr("", c, 20);
	if (r1 != r2)
		error = 5;
	print_result(error);
	return (error);
}

static int	test_memcmp(void)
{
	int			error;
	const char	*s1;
	const char	*s2;
	int			r1;
	int			r2;

	error = 0;
	// 1
	s1 = "Hello World!";
	s1 = "Hello World!";
	r1 = ft_memcmp(s1, s2, 13);
	r2 = memcmp(s1, s2, 13);
	if (r1 != r2)
		error = 1;
	// 2
	s1 = "Hello World!";
	s1 = "Hello world!";
	r1 = ft_memcmp(s1, s2, 13);
	r2 = memcmp(s1, s2, 13);
	if (r1 != r2)
		error = 2;
	// 3
	s1 = "Hello world!";
	s1 = "Hello World!";
	r1 = ft_memcmp(s1, s2, 13);
	r2 = memcmp(s1, s2, 13);
	if (r1 != r2)
		error = 3;
	// 4
	s1 = "Hello world!";
	s1 = "Hello World!";
	r1 = ft_memcmp(s1, s2, 5);
	r2 = memcmp(s1, s2, 5);
	if (r1 != r2)
		error = 4;
	// 5
	s1 = "Hello!";
	s1 = "Hello World!";
	r1 = ft_memcmp(s1, s2, 13);
	r2 = memcmp(s1, s2, 13);
	if (r1 != r2)
		error = 5;
	s1 = "Hello World!\0 this is not here!";
	s1 = "Hello World!\0 different content";
	r1 = ft_memcmp(s1, s2, 32);
	r2 = memcmp(s1, s2, 32);
	if (r1 != r2)
		error = 5;
	print_result(error);
	return (error);
}

static int	test_strnstr(void)
{
	int			error;
	const char	*haystack;
	const char	*needle;
	char		*r1;
	char		*r2;

	error = 0;
	// 1
	haystack = "Hello World!";
	needle = "World";
	r1 = ft_strnstr(haystack, needle, 13);
	r2 = strnstr(haystack, needle, 13);
	if (r1 != r2)
		error = 1;
	// 2
	r1 = ft_strnstr(haystack, needle, 7);
	r2 = strnstr(haystack, needle, 7);
	if (r1 != r2)
		error = 2;
	// 3
	haystack = "Hello World!\0 hidden";
	needle = "hidden";
	r1 = ft_strnstr(haystack, needle, 21);
	r2 = strnstr(haystack, needle, 21);
	if (r1 != r2)
		error = 3;
	// 4
	haystack = "Hello Wolfgang! Welcome to the World!";
	needle = "World";
	r1 = ft_strnstr(haystack, needle, 38);
	r2 = strnstr(haystack, needle, 38);
	if (r1 != r2)
		error = 4;
	// 5
	needle = "!";
	r1 = ft_strnstr(haystack, needle, 38);
	r2 = strnstr(haystack, needle, 38);
	if (r1 != r2)
		error = 5;
	// 6
	haystack = "";
	r1 = ft_strnstr(haystack, needle, 5);
	r2 = strnstr(haystack, needle, 5);
	if (r1 != r2)
		error = 5;
	print_result(error);
	return (error);
}

static int	test_atoi(void)
{
	int			error;
	const char	*str;
	int			r1;
	int			r2;
	
	error = 0;
	// 1
	str = "3";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 1;
	// 2
	str = "0";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 2;
	// 3
	str = "42";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 3;
	// 4
	str = "-42";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 4;
	// 5
	str = "2147483647";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 5;
	// 6
	str = "-2147483648";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 6;
	// 7
	str = "+ \t2147483647";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 7;
	// 8
	str = "\t\v\f\r\n \f+2147 83647";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 8;
	// 9
	str = "042";
	r1 = ft_atoi(str);
	r2 = atoi(str);
	if (r1 != r2)
		error = 9;
	print_result(error);
	return (error);
}

static int	test_calloc(void)
{
	int		error;
	void	*test;
	char	exp[4];

	error = 0;
	memset(exp, 0, 4);
	// 1
	test = ft_calloc(4, sizeof(char));
	if (memcmp(test, exp, 4) != 0)
		error = 1;
	free(test);
	// 2
	test = ft_calloc(2, 2);
	if (memcmp(test, exp, 4) != 0)
		error = 2;
	free(test);
	print_result(error);
	return (error);
}

static int	test_strdup(void)
{
	int			error;
	const char	*str;
	char		*dup;

	error = 0;
	str = "Hello World!";
	// 1
	dup = ft_strdup(str);
	if (strcmp(str, dup) != 0)
		error = 1;
	free(dup);
	// 2
	dup = ft_strdup("");
	if (strcmp("", dup) != 0)
		error = 2;
	free(dup);
	print_result(error);
	return (error);
}

static int test_substr(void)
{
	int			error;
	const char	*str;
	char		*sub;

	error = 0;
	str = "Hello World!";
	// 1
	sub = ft_substr(str, 0, strlen(str));
	if (strcmp(str, sub) != 0)
		error = 1;
	free(sub);
	// 2
	sub = ft_substr(str, 0, 5);
	if (strncmp(str, sub, 5) != 0 || sub[5] != '\0')
		error = 2;
	free(sub);
	// 3
	sub = ft_substr(str, 6, 5);
	if (strcmp("World", sub) != 0)
		error = 3;
	free(sub);
	// 4
	sub = ft_substr(str, 20, 5);
	if (strcmp("", sub) != 0)
		error = 4;
	free(sub);
	// 5
	sub = ft_substr("", 0, 5);
	if (strcmp("", sub) != 0)
		error = 5;
	free(sub);
	print_result(error);
	return (error);
}

static int test_strjoin(void)
{
	int			error;
	const char	*s1;
	const char	*s2;
	char		*str;

	error = 0;
	s1 = "Hello ";
	s2 = "World!";
	// 1
	str = ft_strjoin(s1, s2);
	if (strcmp(str, "Hello World!") != 0)
		error = 1;
	free(str);
	// 2
	str = ft_strjoin("", s2);
	if (strcmp(str, "World!") != 0)
		error = 2;
	free(str);
	// 3
	str = ft_strjoin(s1, "");
	if (strcmp(str, "Hello ") != 0)
		error = 3;
	free(str);
	// 4
	str = ft_strjoin("", "");
	if (strcmp(str, "") != 0)
		error = 4;
	free(str);
	print_result(error);
	return (error);
}

static int test_strtrim(void)
{
	int			error;
	const char	*str;
	const char	*set;
	char		*trim;

	error = 0;
	// 1
	str = "abc12345abc";
	set = "abc";
	trim = ft_strtrim(str, set);
	if (strcmp(trim, "12345") != 0)
		error = 1;
	free(trim);
	// 2
	str = "abc12345abc";
	set = "bca";
	trim = ft_strtrim(str, set);
	if (strcmp(trim, "12345") != 0)
		error = 2;
	free(trim);
	// 3
	str = "abc123abc45abc";
	set = "abc";
	trim = ft_strtrim(str, set);
	if (strcmp(trim, "123abc45") != 0)
		error = 3;
	free(trim);
	// 4
	str = "abcbac12345abcacb";
	set = "abc";
	trim = ft_strtrim(str, set);
	if (strcmp(trim, "12345") != 0)
		error = 4;
	free(trim);
	// 5
	str = " \t\n12345\n\t ";
	set = "\t\n ";
	trim = ft_strtrim(str, set);
	if (strcmp(trim, "12345") != 0)
		error = 5;
	free(trim);
	print_result(error);
	return (error);
}

static int	test_split(void)
{
	int			error;
	const char	*str;
	char		c;
	char		**tab;

	error = 0;
	// 1
	str = "apples,bananas,pears";
	c = ',';
	tab = ft_split(str, c);
	if (strcmp(tab[0], "apples") != 0
		|| strcmp(tab[1], "bananas") != 0
		|| strcmp(tab[2], "pears") != 0
		|| tab[3] != NULL)
		error = 1;
	free(tab[0]); free(tab[1]); free(tab[2]);
	free(tab);
	// 2
	str = " apples  bananas    pears   ";
	c = ' ';
	tab = ft_split(str, c);
	if (strcmp(tab[0], "apples") != 0
		|| strcmp(tab[1], "bananas") != 0
		|| strcmp(tab[2], "pears") != 0
		|| tab[3] != NULL)
		error = 2;
	free(tab[0]); free(tab[1]); free(tab[2]);
	free(tab);
	// 3
	str = "";
	c = ' ';
	tab = ft_split(str, c);
	if (tab[0] != NULL)
		error = 3;
	free(tab);
	print_result(error);
	return (error);
}

static int	test_itoa(void)
{
	int		error;
	int		n;
	char	*str;

	error = 0;
	// 1
	n = 7;
	str = ft_itoa(n);
	if (strcmp(str, "7") != 0)
		error = 1;
	free(str);
	// 2
	n = 42;
	str = ft_itoa(n);
	if (strcmp(str, "42") != 0)
		error = 2;
	free(str);
	// 3
	n = 0;
	str = ft_itoa(n);
	if (strcmp(str, "0") != 0)
		error = 3;
	free(str);
	// 4
	n = 2147483647;
	str = ft_itoa(n);
	if (strcmp(str, "2147483647") != 0)
		error = 4;
	free(str);
	// 5
	n = -2147483648;
	str = ft_itoa(n);
	if (strcmp(str, "-2147483648") != 0)
		error = 5;
	free(str);
	print_result(error);
	return (error);
}

static char	add_index(unsigned int n, char c)
{
	return (c + n);
}

static int	test_strmapi(void)
{
	int			error;
	const char	*str;
	char		*res;

	error = 0;
	// 1
	str = "0123";
	res = ft_strmapi(str, add_index);
	if (strcmp(res, "0246") != 0)
		error = 1;
	free(res);
	// 2
	str = "";
	res = ft_strmapi(str, add_index);
	if (strcmp(res, "") != 0)
		error = 2;
	free(res);
	print_result(error);
	return (error);
}

static void	alternate_case(unsigned int n, char *c)
{
	if (n % 2 == 0)
		*c = toupper(*c);
	else
		*c = tolower(*c);
}

static int	test_striteri(void)
{
	int		error;
	char	str[20];

	error = 0;
	// 1
	strcpy(str, "hello world");
	ft_striteri(str, alternate_case);
	if (strcmp(str, "HeLlO WoRlD") != 0)
		error = 1;
	// 2
	strcpy(str, "");
	ft_striteri(str, alternate_case);
	if (strcmp(str, "") != 0)
		error = 2;
	print_result(error);
	return (error);
}

static int	test_putchar_fd(void)
{
	int		error;
	char	c;
	FILE	*fd;
	int		f_no;
	char	r;

	error = 0;
	fd = fopen("testfile", "w+");
	f_no = fileno(fd);
	// 1
	c = 'a';
	ft_putchar_fd(c, f_no);
	rewind(fd);
	r = fgetc(fd);
	if (r != c)
		error = 1;
	fclose(fd);
	remove("testfile");
	print_result(error);
	return (error);
}

static int	test_putstr_fd(void)
{
	int		error;
	char	*str;
	FILE	*fd;
	int		f_no;
	char	buffer[20];
	size_t	len;

	error = 0;
	fd = fopen("testfile", "w+");
	f_no = fileno(fd);
	// 1
	str = "Hello World!";
	ft_putstr_fd(str, f_no);
	rewind(fd);
	len = fread(buffer, sizeof(char), strlen(str), fd);
	buffer[len] = '\0';
	if (strcmp(str, buffer) != 0)
		error = 1;
	fclose(fd);
	remove("testfile");
	print_result(error);
	return (error);
}

static int	test_putendl_fd(void)
{
	int		error;
	char	*str;
	FILE	*fd;
	int		f_no;
	char	buffer[20];
	size_t	len;

	error = 0;
	fd = fopen("testfile", "w+");
	f_no = fileno(fd);
	// 1
	str = "Hello World!";
	ft_putendl_fd(str, f_no);
	rewind(fd);
	len = fread(buffer, sizeof(char), strlen(str) + 1, fd);
	buffer[len] = '\0';
	if (strncmp(str, buffer, strlen(str)) != 0 || buffer[len - 1] != '\n')
		error = 1;
	fclose(fd);
	remove("testfile");
	print_result(error);
	return (error);
}

static int	test_putnbr_fd(void)
{
	int		error;
	int		nbr;
	FILE	*fd;
	int		f_no;
	char	buffer[20];
	size_t	len;

	error = 0;
	fd = fopen("testfile", "w+");
	f_no = fileno(fd);
	// 1
	nbr = 42;
	ft_putnbr_fd(nbr, f_no);
	rewind(fd);
	len = fread(buffer, sizeof(char), 2, fd);
	buffer[len] = '\0';
	if (strncmp(buffer, "42", len) != 0)
		error = 1;
	rewind(fd);
	// 2
	nbr = 2147483647;
	ft_putnbr_fd(nbr, f_no);
	rewind(fd);
	len = fread(buffer, sizeof(char), 10, fd);
	buffer[len] = '\0';
	if (strncmp(buffer, "2147483647", len) != 0)
		error = 2;
	rewind(fd);
	// 3
	nbr = -2147483648;
	ft_putnbr_fd(nbr, f_no);
	rewind(fd);
	len = fread(buffer, sizeof(char), 11, fd);
	buffer[len] = '\0';
	if (strncmp(buffer, "-2147483648", len) != 0)
		error = 3;
	rewind(fd);
	// 4
	nbr = 0;
	ft_putnbr_fd(nbr, f_no);
	rewind(fd);
	len = fread(buffer, sizeof(char), 1, fd);
	buffer[len] = '\0';
	if (strncmp(buffer, "0", len) != 0)
		error = 4;
	fclose(fd);
	remove("testfile");
	print_result(error);
	return (error);
}

