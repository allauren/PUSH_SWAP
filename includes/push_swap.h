/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:25:22 by allauren          #+#    #+#             */
/*   Updated: 2017/12/17 06:52:08 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf.h"

# define PILEAINF pile->pilea->value < pile->pilea->next->value
# define PILEBINF pile->pileb->value < pile->pileb->next->value
# define PILEBSUP pile->pileb->value > pile->pileb->next->value
# define PILEA pile->pilea
# define PILEB pile->pileb
# define PILEAVAL PILEA->value
# define PILEBVAL PILEB->value
# define PILEAHEA PILEA->HEAD
# define PILEBHEA PILEB->HEAD
# define PILEANEX PILEA->next
# define PILEBNEX PILEB->next
# define PILEAIDX PILEA->index
# define PILEBIDX PILEB->index

typedef struct			s_2list
{
	int					value;
	int					index;
	struct s_2list		*head;
	struct s_2list		*next;
}						t_2list;

typedef struct			s_2pile
{
	t_2list				*pilea;
	t_2list				*pileb;
}						t_2pile;

void					sort_tillfif(t_2pile *pile, int i);
int						ft_is_reverse(t_2list *pile);
void					ft_2lstdelall(t_2list *begin);
int						ft_set_values(char *str, int taille);
int						ft_is_finish(t_2list *pilea);
int						ft_2listsize(t_2list *begin);
int						ft_cut(int ac, char **av);
void					sort_smalla(t_2pile *pile, int size);
void					ft_is_sort(t_2list *pilea);
int						ft_is_nfinish(t_2list *pilea, int n);
t_2pile					*ft_checkswapa(t_2pile *pile);
t_2list					*ft_fill(t_2list *pilea, int *tab, int i);
char					*ft_short_string(char *s, int taille, char *tmp);
void					quick2sort(t_2pile *pile, int i, int taille);
t_2list					*ft_2listrotate(t_2list *begin);
t_2list					*ft_2listrevrotate(t_2list *begin);
t_2list					*ft_2listndel(t_2list *begin, int n);
void					ft_2listdel(t_2list *begin);
t_2list					*ft_2listfront(t_2list *begin, t_2list *ew);
int						*ft_insertformed(int *tab, int len);
void					ft_readpsw(t_2pile *pile);
int						*ft_concattab(int *tab, t_2list *pile);
void					insertion_sort(t_2pile *pile, int taille);
int						*ft_concattab(int *tab, t_2list *pile);
int						ft_find_pivot(t_2list *pile, int len, int div);
void					ft_2sortb(t_2pile *pile, int lenb, int *tab);
int						*ft_insertformed(int *tab, int len);
void					sort_small(t_2pile *pile, int size);
t_2list					*ft_2listrev(t_2list *begin);
t_2list					*ft_2list_new(int value, int index);
t_2list					*ft_2listhead(t_2list *begin);
t_2list					*ft_2listtail(t_2list *begin);
void					ft_pushb(t_2pile *pile);
int						ft_fullzero(char *str);
int						ft_ispresent(int *tab, int i);
void					ft_find_opti(int lenb, t_2pile *pile, int *tab, int i);
void					ft_reinit(t_2pile *pile, int len);
void					ft_pusha(t_2pile *pile);
void					ft_exit(void);
int						ft_ispresent(int *tab, int i);
t_2list					*ft_swap(t_2list *begin, t_2list *next);
int						ft_checker(int argc, char **arg, int *tab);
void					ft_print_pile(t_2pile *pile);
#endif
