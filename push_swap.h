/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:25:22 by allauren          #+#    #+#             */
/*   Updated: 2017/12/13 14:12:15 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "lib/printf.h"



typedef struct			s_2list
{
	int					value;
	struct s_2list		*head;
	struct s_2list		*next;
}						t_2list;

typedef struct			s_2pile
{
	t_2list	*pilea;
	t_2list	*pileb;
}						t_2pile;

void		ft_2lstdelall(t_2list *begin);
void		ft_easy_sort(t_2pile *pile, int i);
int		ft_set_values(char* str, int taille);
int	ft_is_finish(t_2list *pilea);
int		ft_2listsize(t_2list *begin);
int			ft_cut(int ac, char **av);
t_2list		*ft_fill(t_2list *pilea, int *tab, int i);
void		quick2sort(t_2pile *pile,int i);
t_2list		*ft_2listrotate(t_2list *begin);
t_2list		*ft_2listrevrotate(t_2list *begin);
t_2list		*ft_2listndel(t_2list *begin, int n);
void		ft_2listdel(t_2list *begin);
t_2list		*ft_2listfront(t_2list *begin, t_2list *ew);
void		ft_readpsw(t_2pile *pile);
void		insertion_sort(t_2pile *pile, int taille);
t_2list		*ft_2listrev(t_2list *begin);
t_2list		*ft_2list_new(int value);
t_2list		*ft_2listhead(t_2list *begin);
t_2list		*ft_2listtail(t_2list *begin);
void		ft_pushb(t_2pile *pile);
void		ft_pusha(t_2pile *pile);
void		ft_exit(void);
int			ft_ispresent(int *tab, int i);
t_2list		*ft_swap(t_2list *begin, t_2list *next);
int			ft_checker(int argc, char **argv, int *tab);
void		ft_print_pile(t_2pile *pile);
#endif
