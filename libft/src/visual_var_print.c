#include "libft.h"

void	visual_var_print(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);

	// TOP ROW
	printf("+");
	i = 0;
	while (i++ < (len + 2))
		printf("-");
	printf("+");
	printf("\n");

	// MIDDLE ROW
	printf("| %s |", str);
	printf("\n");

	// BOTTOM ROW
	printf("+");
	i = 0;
	while (i++ < (len + 2))
		printf("-");
	printf("+");
	printf("\n");
}
