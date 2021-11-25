/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus_tester.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:07:19 by chelmerd          #+#    #+#             */
/*   Updated: 2021/11/25 13:09:52 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <string.h>

static int	test_lstnew(void);
static int	test_lstadd_front(void);
static int	test_lstsize(void);
static int	test_lstlast(void);
static int	test_lstadd_back(void);
static int	test_lstdelone(void);
static int	test_lstclear(void);
static int	test_lstiter(void);
static int	test_lstmap(void);

int	main(void)
{
	int	error;

	error = 0;
	printf("Testing ft_lstnew\n");
	error += test_lstnew();
	printf("Testing ft_lstadd_front\n");
	error += test_lstadd_front();
	printf("Testing ft_lstsize\n");
	error += test_lstsize();
	printf("Testing ft_lstlast\n");
	error += test_lstlast();
	printf("Testing ft_lstadd_back\n");
	error += test_lstadd_back();
	printf("Testing ft_lstdelone\n");
	error += test_lstdelone();
	printf("Testing ft_lstclear\n");
	error += test_lstclear();
	printf("Testing ft_lstiter\n");
	error += test_lstiter();
	printf("Testing ft_lstmap\n");
	error += test_lstmap();
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

static int	test_lstnew(void)
{
	int			error;
	const char	*str;
	t_list		*new;

	error = 0;
	str = "new element";
	new = ft_lstnew((void *)str);
	if (strcmp(str, new->content) != 0 || new->next != NULL)
		error = 1;
	free(new);
	print_result(error);
	return (error);
}

static void	free_list(t_list *head)
{
	if (head)
		free_list(head->next);
	free(head);
}

static int	test_lstadd_front(void)
{
	int			error;
	const char	*str;
	t_list		*lst;

	error = 0;
	str = "new element";
	lst = NULL;
	// 1
	ft_lstadd_front(&lst, ft_lstnew((void *)str));
	if (strcmp(str, lst->content) != 0 || lst->next != NULL)
		error = 1;
	// 2
	ft_lstadd_front(&lst, ft_lstnew((void *)"2nd add"));
	if (strcmp("2nd add", lst->content) != 0
		|| strcmp(str, lst->next->content) != 0 || lst->next->next != NULL)
		error = 2;
	free_list(lst);
	print_result(error);
	return (error);
}

static int	test_lstsize(void)
{
	int			error;
	const char	*str;
	t_list		*lst;
	int			size;

	error = 0;
	str = "new element";
	lst = NULL;
	// 1
	size = ft_lstsize(lst);
	if (size != 0)
		error = 1;
	// 2
	ft_lstadd_front(&lst, ft_lstnew((void *)str));
	size = ft_lstsize(lst);
	if (size != 1)
		error = 2;
	// 2
	ft_lstadd_front(&lst, ft_lstnew((void *)"2nd add"));
	size = ft_lstsize(lst);
	if (size != 2)
		error = 3;
	free_list(lst);
	print_result(error);
	return (error);
}

static int	test_lstlast(void)
{
	int			error;
	const char	*str;
	t_list		*lst;
	t_list		*last;

	error = 0;
	str = "new element";
	lst = NULL;
	// 1
	ft_lstadd_front(&lst, ft_lstnew((void *)str));
	last = ft_lstlast(lst);
	if (strcmp(str, last->content) != 0 || last->next != NULL)
		error = 1;
	// 2
	ft_lstadd_front(&lst, ft_lstnew((void *)"2nd add"));
	last = ft_lstlast(lst);
	if (strcmp(str, last->content) != 0 || last->next != NULL)
		error = 2;
	free_list(lst);
	print_result(error);
	return (error);
}

static int	test_lstadd_back(void)
{
	int			error;
	const char	*str;
	t_list		*lst;

	error = 0;
	str = "new element";
	lst = NULL;
	// 1
	ft_lstadd_back(&lst, ft_lstnew((void *)str));
	if (strcmp(str, lst->content) != 0 || lst->next != NULL)
		error = 1;
	// 2
	ft_lstadd_back(&lst, ft_lstnew((void *)"2nd add"));
	if (strcmp(str, lst->content) != 0
		|| strcmp("2nd add", lst->next->content) != 0 || lst->next->next != NULL)
		error = 2;
	free_list(lst);
	print_result(error);
	return (error);
}

static int	g_delone_called;
void	lstdelone_f(void *d)
{
	free(d);
	g_delone_called += 1;
}

static int	test_lstdelone(void)
{
	int		error;
	t_list	*lst;

	error = 0;
	// 1
	lst = ft_lstnew(malloc(7));
	ft_lstdelone(lst, lstdelone_f);
	if (g_delone_called != 1)
		error = 1;
	g_delone_called = 0;
	print_result(error);
	return (error);
}

static int	test_lstclear(void)
{
	int		error;
	t_list	*lst;

	error = 0;
	// 1
	lst = ft_lstnew(strdup("Hello"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("World")));
	ft_lstclear(&lst, lstdelone_f);
	if (g_delone_called != 2 || lst != NULL)
		error = 1;
	g_delone_called = 0;
	print_result(error);
	return (error);
}

static void	change_str(void *p)
{
	char	*str;

	str = p;
	str[0] = 'O';
	str[1] = 'K';
}

static int	test_lstiter(void)
{
	int		error;
	t_list	*lst;
	int		i;
	t_list	*tmp;

	error = 0;
	// 1
	i = 0;
	lst = NULL;
	while (i < 5)
	{
		ft_lstadd_back(&lst, ft_lstnew(strdup("Hello World!")));
		i++;
	}
	ft_lstiter(lst, change_str);
	i = 0;
	tmp = lst;
	while (i < 5)
	{
		if (strcmp("OKllo World!", (char *)tmp->content) != 0)
			error = 1;
		tmp = tmp->next;
		i++;
	}
	free_list(lst);
	print_result(error);
	return (error);
}

static void	*copy_change_str(void *p)
{
	char	*str;
	char	*ret;

	str = p;
	ret = strdup(str);
	ret[0] = 'O';
	ret[1] = 'K';
	return (ret);
}

static int	test_lstmap(void)
{
	int		error;
	t_list	*lst;
	int		i;
	t_list	*m;
	t_list	*tmp;

	error = 0;
	// 1
	i = 0;
	lst = NULL;
	while (i < 5)
	{
		ft_lstadd_back(&lst, ft_lstnew(strdup("Hello World!")));
		i++;
	}
	m = ft_lstmap(lst, copy_change_str, free);
	// check if original list is still the same
	i = 0;
	tmp = lst;
	while (i < 5)
	{
		if (strcmp("Hello World!", (char *)tmp->content) != 0)
			error = 1;
		tmp = tmp->next;
		i++;
	}
	// check the returned list
	i = 0;
	tmp = m;
	while (i < 5)
	{
		if (strcmp("OKllo World!", (char *)tmp->content) != 0)
			error = 2;
		tmp = tmp->next;
		i++;
	}
	free_list(lst);
	ft_lstclear(&m, free);
	print_result(error);
	return (error);
}
