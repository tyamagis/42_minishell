/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:47:26 by tyamagis          #+#    #+#             */
/*   Updated: 2022/06/15 21:19:39 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef struct s_tree {
	char			*data;
	struct s_tree	*parent;
	struct s_tree	*left;
	struct s_tree	*right;
} t_tree;

t_tree	*tree_new(char *data);
t_tree	*tree_add_node(t_tree *root, t_tree *node);
t_tree	*tree_delete(t_tree *root, t_tree *node);
void	tree_clear(t_tree *root);

#endif