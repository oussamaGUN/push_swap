SRC = main.c lst_new.c ft_atoi.c lst_addfront.c ft_lstsize.c \
	  sorting_tools/sa.c sorting_tools/pa.c ft_split.c ft_isdigit.c \
	  lst_addback.c sorting_tools/ra.c sorting_tools/rra.c sorting_tools/pb.c \
	   sorting_3.c error_handle.c error_handle1.c list_creating.c list_sorting.c tools1.c tools2.c lst_del.c cheapest.c sorting_tools/rrr.c  \
	   adjust.c adjust_tools.c

BONUS = checker_bonus.c lst_new.c ft_atoi.c lst_addfront.c ft_lstsize.c \
	  sorting_tools/sa.c sorting_tools/pa.c ft_split.c ft_isdigit.c \
	  lst_addback.c sorting_tools/ra.c sorting_tools/rra.c sorting_tools/pb.c \
	   error_handle.c error_handle1.c list_creating.c get_next_line.c get_next_line_outils.c lst_del.c sorting_tools/rrr.c sorting_tools/ss.c \
	   bonus_tools.c bonus_conditions.c ft_strcmp.c

CLFAGS = -Wall -Wextra 

NAME = push_swap

all: main.c
	gcc $(SRC) $(CLFAGS) -o $(NAME)

bonus: checker_bonus.c
	gcc $(BONUS) $(CLFAGS) -o checker_bonus	