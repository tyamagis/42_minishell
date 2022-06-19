#ifndef ALIST_H
#define ALIST_H

#include "libft/libft.h"

typedef struct s_alist {
	char			*key;
	char			*value;
	struct s_alist	*next;
}	t_alist;

void	free_alist(t_alist *head);
t_alist *rm_alist(t_alist *head, const char *key);
t_alist	*search_alist(t_alist *head, const char *key);
t_alist	*update_alist(t_alist *head, const char *key, const char *value);
t_alist	*add_new_alist(t_alist *head, const char *key, const char *value);

#endif
