#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "ft_stock_str.h"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

void	test_ex1(struct	s_stock_str *(*testex)(int, char **))
{
	char **array_of_strs;
	struct s_stock_str	*s_storage;

	array_of_strs = malloc(sizeof(char *) * (5 + 1));
	array_of_strs[0] = strdup("nine");
	array_of_strs[1] = strdup("-2147483648");
	array_of_strs[2] = strdup("0d23d$()");
	array_of_strs[3] = strdup("why...");
	array_of_strs[4] = strdup("2");
	array_of_strs[5] = NULL;

	printf("Testing basic case;\n");

	int pos = 0;
	printf("\nOur array:\n");
	while (pos < 5)
	{
		printf("\"%s\", ", array_of_strs[pos]);
		pos++;
	}

    s_storage = testex(5, array_of_strs);
    printf("The returned structure:\n");

	pos = 0;
	while (s_storage[pos].str != 0)
	{
		printf("\nPosition in struct array: %i\n", pos);
		printf("size: %i\n", s_storage[pos].size);
		assert(strlen(s_storage[pos].str) == (size_t)s_storage[pos].size);

		printf("str :\"%s\"\n", s_storage[pos].str);
		printf("copy :\"%s\"\n", s_storage[pos].copy);
		assert(strcmp(s_storage[pos].str, s_storage[pos].copy) == 0);

		free(s_storage[pos].copy);

		printf("\n\n");
		pos++;
	}
	free(s_storage);

	printf("Testing what happens if I give you a size of 0:\n");
	s_storage = testex(0, array_of_strs);
	assert(s_storage == NULL);
	printf("Yay, it returned NULL!\n");

	free(array_of_strs[0]);
	free(array_of_strs[1]);
	free(array_of_strs[2]);
	free(array_of_strs[3]);
	free(array_of_strs[4]);
	free(array_of_strs);
}

void	test_ex2(void (*testex)(struct s_stock_str *))
{
	char **array_of_strs;
	struct s_stock_str	*s_storage;
	int pos;

	array_of_strs = malloc(sizeof(char *) * (5 + 1));
	array_of_strs[0] = strdup("nine");
	array_of_strs[1] = strdup("-2147483648");
	array_of_strs[2] = strdup("0d23d$()");
	array_of_strs[3] = strdup("why...");
	array_of_strs[4] = strdup("2");
	array_of_strs[5] = NULL;

	printf("Testing regular use case with our function:\n");
	testex(ft_strs_to_tab(5, array_of_strs));

	printf("\nThe same case using printf instead:\n");

	pos = 0;
	s_storage = ft_strs_to_tab(5, array_of_strs);
	while (s_storage[pos].str != 0)
	{
		printf("\nPosition in struct array: %i\n", pos);
		printf("size: %i\n", s_storage[pos].size);
		assert(strlen(s_storage[pos].str) == (size_t)s_storage[pos].size);

		printf("str :\"%s\"\n", s_storage[pos].str);
		printf("copy :\"%s\"\n", s_storage[pos].copy);
		assert(strcmp(s_storage[pos].str, s_storage[pos].copy) == 0);

		free(s_storage[pos].copy);

		printf("\n\n");
		pos++;
	}
	free(s_storage);


	printf("Testing with a length equal to 0:\n");
	testex(ft_strs_to_tab(0, array_of_strs));
	printf("Nothing should happen, contact the authorities otherwise\n");

}



int	main(void)
{
	printf("Ex1: ft_strncpy:\n\n");
	test_ex1(ft_strs_to_tab);
	printf("\nTests Ex1 Passed!\n\n\n\n");

	printf("Ex2: ft_show_tab:\n\n");
	test_ex2(ft_show_tab);
	printf("\nTests Ex2 Passed!\n\n\n\n");
}
