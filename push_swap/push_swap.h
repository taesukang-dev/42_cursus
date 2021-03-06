/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:14:36 by tkang             #+#    #+#             */
/*   Updated: 2022/06/30 15:14:37 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 0
# define SB 1
# define SS 2

# define PA 0
# define PB 1

# define RA 0
# define RB 1
# define RR 2

# define RRA 0
# define RRB 1
# define RRR 2

# include "./libft/libft.h"

typedef struct s_DoublyListNodeType
{
	int							data;
	struct s_DoublyListNodeType	*prev;
	struct s_DoublyListNodeType	*next;
}	t_DoublyListNode;

typedef struct s_DoublyListType
{
	int					cnt;
	int					size;
	t_DoublyListNode	*head;
	t_DoublyListNode	*tail;
}	t_DoublyList;

void				init_doubly(t_DoublyList **dList, char *argv[], int argc);
int					my_atoi(const char *str);
void				exit_trap(int flag);
void				two_d_free(char **str);

int					*init_sorted_arr(t_DoublyList *dList);
int					sort_arr(int *sorted_arr, int size);

t_DoublyList		*create_doubly_list(void);
int					add_dl_element(t_DoublyList *dList, int data);
int					add_right_dl_element(t_DoublyList *dList, int data);
t_DoublyListNode	*pop_dl(t_DoublyList *dList);
t_DoublyListNode	*pop_right_dl(t_DoublyList *dList);

void				command_sab(t_DoublyList *dList, int flag);
void				command_ss(t_DoublyList *a, t_DoublyList *b);
void				command_pab(t_DoublyList *a, t_DoublyList *b, int flag);
void				command_rab(t_DoublyList *dList, int flag);
void				command_rr(t_DoublyList *a, t_DoublyList *b);
void				command_rrab(t_DoublyList *dList, int flag);
void				command_rrr(t_DoublyList *a, t_DoublyList *b);

void				sorting(t_DoublyList *a, t_DoublyList *b, int *sorted_arr);
void				sort_two_elements(t_DoublyList *a);
void				sort_three_elements(t_DoublyList *a);
void				sort_push_swap(t_DoublyList *a, \
									t_DoublyList *b, int *sorted_arr);
void				split_stack(t_DoublyList *a, \
									t_DoublyList *b, int *sorted_arr);

void				swap(t_DoublyList *a, \
							t_DoublyList *b, int *a_idx, int *b_idx);
int					get_idx(t_DoublyList *a, int b_val);
int					stack_max_idx(t_DoublyList *a);
int					stack_mid_idx(t_DoublyList *a, int b_val);
int					stack_min(t_DoublyList *a);
int					stack_min_idx(t_DoublyList *a);
int					stack_max(t_DoublyList *a);

void				rotate(t_DoublyList *a, \
							t_DoublyList *b, int *a_idx, int *b_idx);

#endif
