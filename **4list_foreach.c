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

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);				// calling the function with its param
		begin_list = begin_list->next;
	}
}





/*Write a function that takes a list and a function pointer, and applies this
function to each element of the list.
It must be declared as follows:
void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
The function pointed to by f will be used as follows:
(*f)(list_ptr->data);
You must use the following structure, and turn it in as a file called
ft_list.h:
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/
