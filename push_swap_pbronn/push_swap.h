/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:52:16 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 16:47:38 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list {
	int				steps;
	int				i;
	struct s_list	*prev;
	int				index;
	struct s_list	*place;
	int				data;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int		check_str(unsigned int x);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_strdel(char **as);
char	*ft_strc(const char *s, int c);
int		get_next_line(const int fd, char **line);
int		ft_strncmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
void	ft_exit(t_list **a);
int		ft_sort(t_list *a);
void	(*best_function(int x, int y, char **msg, int z))(t_list**, char*);
int		lst_size(t_list *head);
void	swap_stack(t_list *head, char *msg);
t_list	*new_node(int data);
t_list	*add_back(t_list *new, t_list **head);
void	clr_list(t_list **head);
void	push_stack(t_list **from, t_list **to, char *msg);
t_list	*add_front(t_list *new, t_list **head);
void	reverse_rotate_stack(t_list **head, char *msg);
void	sort_index(t_list **stack);
void	rotate_stack(t_list **head, char *msg);
void	sort3(t_list **a);
void	sort2(t_list **a);
t_list	*max_index(t_list **stack);
void	sort(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b, t_list *head);
void	push_stack_b(t_list **a, t_list **b, t_list *node);
void	range_stack_utils(t_list **a, t_list **b, t_list *min, \
	void (*fa)(t_list**, char*), void (*fb)(t_list**, char*));
void	check_place(t_list **a, t_list **b, t_list *node_p, t_list *markup);
void	write_steps(t_list *target, t_list *node, t_list *heada, t_list *headb);
void	calculate_steps(t_list **a, t_list **b, t_list *markup);
void	mix_stack(t_list **a, t_list **b);
void	add_front_utils(t_list *new, t_list **head);
void	sort_index_utils(t_list *a, t_list *b);
void	min_on_top(t_list **a);
t_list	*min_steps(t_list *b);
t_list	*min_data(t_list *a);
void	sort_4_5(t_list **a, t_list **b);
void	check_in(int ac, char **av, t_list **a);
int		check_num(char *str);

#endif