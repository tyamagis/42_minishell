/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:56:22 by tyamagis          #+#    #+#             */
/*   Updated: 2022/06/15 20:21:49 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_tree *tree_new(char *data){
	t_tree *new;
	
	new = (t_tree *)malloc(sizeof(t_tree));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_tree *tree_add_node(t_tree *root, t_tree *node){
	
}

void tree_clear(t_tree *root){
	
}