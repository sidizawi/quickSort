#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	long	res;
	int		k;

	if (!str)
		exit(1);
	k = 1;
	res = 0;
	if (*str == '-')
		k = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - 48);
	if (*str)
		exit(1);
	res *= k;
	return ((int)res);
}

void	ft_swap(int *lst, int i, int j)
{
	int	temp;

	temp = lst[i];
	lst[i] = lst[j];
	lst[j] = temp;
}

int		ft_partition(int *lst, int start, int end)
{
	int	index;
	int	pivot;

	index = start;
	pivot = lst[end];
	while (start < end)
	{
		if (lst[start] < pivot)
		{
			ft_swap(lst, index, start);
			index++;
		}
		start++;
	}
	ft_swap(lst, index, start);
	return (index);
}

// default: start = 0, end = lenfth of (lst) - 1
void	quick_sort(int *lst, int start, int end)
{
	int	index;

	if (start >= end)
		return;
	index = ft_partition(lst, start, end);
	quick_sort(lst, start, index - 1);
	quick_sort(lst, index + 1, end);
}

int		main(int ac, char *av[])
{
	int *lst;
	int i;

	lst = malloc(sizeof(int)*(ac - 1));
	if (!lst)
		exit(1);
	i = -1;
	while (++i < (ac - 1))
		lst[i] = ft_atoi(av[i+1]);
	quick_sort(lst, 0, ac - 2);
	i = 0;
	while (i < (ac - 1))
	{
		printf("%i", lst[i++]);
		if (i < (ac - 1))
			printf(", ");
	}
	printf("\n");
	free(lst);
	return (0);
}
