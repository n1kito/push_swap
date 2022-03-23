#include "libft.h"

//Write a Count() function that counts the number of times a given int occurs in a list.
// The code for this has the classic list traversal structure as demonstrated in Length().

int	lstlen(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}