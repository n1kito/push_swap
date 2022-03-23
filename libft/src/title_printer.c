#include "libft.h"

void	print_title(char *title, int size)
{
	int title_len;
	int left_len;
	int right_len;
	int i;

	i = 0;
	title_len = ft_strlen(title);
	left_len = ((size - title_len) / 2) - 1;
	right_len = size - (title_len + left_len) - 2;
	printf("+");
	while (i++ < left_len)
		printf("-");
	printf("%s", title);
	i = 0;
	while (i++ < right_len)
		printf("-");
	printf("+");
	printf("\n");
}

void	print_title_end(int size)
{
	int i;

	printf("+");
	i = 0;
	while (i++ < (size - 2))
		printf("-");
	printf("+");
	printf("\n");
	printf("\n");
}