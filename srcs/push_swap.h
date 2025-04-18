/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:33:56 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 10:28:01 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct array
{
	long	*arr;
	int		size;
	int		cap;
}	t_stack;

void	double_free_error(char **splited, t_stack *stk);
long	*ft_realloc_dst(long *src, long *dst, int size);
void	init_data(int *i, char ***splited, int *count, char *str);
long	*ft_realloc_src(long *src, int size);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_chunks(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
t_stack	*create_stack(int size);
int		stack_empty_or_full(t_stack *stk);
long	peek(t_stack *stk);
void	freeing(char **str);
void	freeing_and_error(char **str);
void	free_stack(t_stack *st);
void	error_and_free(t_stack *st);
void	error(void);
long	ft_atol(const char *str);
long	find_max(long *arr, int last);
long	find_min(long *arr, int last);
int		main(int ac, char **av);
void	swap(t_stack *stk, char c);
void	push(t_stack *src, t_stack *dst, char c);
void	rotate(t_stack *stk, char c);
void	reverse_rotate(t_stack *stk, char c);
int		ft_validate(char *str);
int		count_args(char *str);
int		check_duplicates(long *arr, int valid_count);
t_stack	*ft_string(char *str, t_stack *stk);
t_stack	*ft_args(int ac, char **av, t_stack *stk);
int		find_index(long *arr, int size, long element);
void	increment_range(int *end, int *start);
void	push_back_to_a(t_stack *a, t_stack *b, long *sorted);
long	*bubble_sort(long *arr, int size);
int		is_sorted(t_stack *a);
int		find_index_in_b(long *arr, long element, int top);
void	init_range(int *start, int *end, int cap);
void	ft_swap(long *a, long*b);
int		is_only_space(char *str);

#endif