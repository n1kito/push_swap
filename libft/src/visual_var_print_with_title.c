#include "libft.h"

void	visual_var_print_with_title(char *str, char *title)
{
	int	len;
	int	title_len;
	int	i;

	len = ft_strlen(str);
	title_len = ft_strlen(title);

	// TOP ROW
	i = 0;
	while (i++ < (title_len + 3))
		printf(" ");
	printf("+");
	i = 0;
	while (i++ < (len + 2))
		printf("-");
	printf("+");
	printf("\n");

	// MIDDLE ROW
	printf("%s = | %s |", title, str);
	printf("\n");

	// BOTTOM ROW
	i = 0;
	while (i++ < (title_len + 3))
		printf(" ");
	printf("+");
	i = 0;
	while (i++ < (len + 2))
		printf("-");
	printf("+");
	printf("\n");
}
