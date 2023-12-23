SRC = main.c libft/lst_new.c libft/ft_atoi.c libft/lst_addfront.c libft/ft_lstsize.c \
	  sorting_tools/sa.c sorting_tools/pa.c libft/ft_split.c libft/ft_isdigit.c \
	  libft/lst_addback.c sorting_tools/ra.c sorting_tools/rra.c

CLFAGS = -Wall -Wextra

NAME = push_swap
all: main.c
	gcc $(SRC) $(CLFAGS)