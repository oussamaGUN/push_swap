SRC = main.c libft/lst_new.c libft/ft_atoi.c libft/lst_addfront.c libft/ft_lstsize.c \
	  sorting/sa.c sorting/pb.c libft/ft_split.c libft/ft_isdigit.c

CLFAGS = -Wall -Wextra

NAME = push_swap
all: main.c
	gcc $(SRC) $(CLFAGS)