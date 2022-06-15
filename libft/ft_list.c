/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:26:12 by tyamagis          #+#    #+#             */
/*   Updated: 2022/06/15 22:02:50 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_lstnew(void *elem){
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->elem = elem;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

// No Null Check.
// Use carefully.
t_list *ft_lstlast(t_list *lst){
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// No Null Check.
// Use carefully.
t_list *ft_lsttop(t_list *lst){
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}

void ft_lstclear(t_list *lst){
	t_list *next;

	if (lst == NULL)
		return ;
	lst = ft_lsttop(lst);
	while (lst != NULL)
	{
		next = lst->next;
		free(lst->elem);
		free(lst);
		lst = next;
	}
	return ;
}

void ft_lstinsert(t_list *prev, t_list *lst){
	t_list *tmp;
	
	if (prev == NULL)
		return ;
	if (prev->next == NULL)
	{
		prev->next = lst;
		return ;
	}
	else
	{
		tmp = prev->next;
		lst->prev = prev;
		prev->next = lst;
		lst = ft_lstlast(lst);
		lst->next = tmp;
		tmp->prev = lst;
	}
	return;
}

void ft_lstdel(t_list **lst){
	if (*lst == NULL)
		return ;
	if ((*lst)->prev != NULL)
		(*lst)->prev->next = (*lst)->next;
	if ((*lst)->next != NULL)
		(*lst)->next->prev = (*lst)->prev;
	free((*lst)->elem);
	free(*lst);
	*lst = NULL;
	return ;
}