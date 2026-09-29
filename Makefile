all: build-C ex0

build-C:	main.c ../ex1/ft_strs_to_tab.c ../ex2/ft_show_tab.c
	cc -Werror -Wall -Wextra $^ -I . -o Tests-C-Structures-Ex1-Ex2

ex0: fake_main.c
	cc -Werror -Wall -Wextra $^ -I ../ex0/ -o Tests-C-Structures-Ex0
