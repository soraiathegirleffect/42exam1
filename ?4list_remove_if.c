ft_list.h

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

#endif





#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>
#include <string.h>


void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;

    if (!begin_list || !*begin_list)
        return ;
    current = *begin_list;
    if ((*cmp)(current->data, data_ref) == 0)
    {
        *begin_list = current->next;
        free(current);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    current = *begin_list;
    //current = current->next;              this is going to be error in case current->next is 0
    ft_list_remove_if(&current->next, data_ref, cmp);
}

//orrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}

/*Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.
It will be declared as follows :
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
cmp takes two void* and returns 0 when both parameters are equal.
You have to use the ft_list.h */
