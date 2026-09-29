all: build-C ex0

build-C:	main.c ../ex1/ft_strs_to_tab.c ../ex2/ft_show_tab.c
	cc -Werror -Wall -Wextra $^ -I ft_stock_str.h -o Tests-C-Structures

ex0: fake_main.c
	cc -Werror -Wall -Wextra $^ -I ../ex0/ft_point.h -o Tests-C-Structures
