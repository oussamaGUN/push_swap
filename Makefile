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

CLFAGS = -Wall -Wextra -Werror

CC = cc

NAME = push_swap

NAME_BONUS = checker_bonus

OBJC = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(OBJC) -o $(NAME) 

%.o: %.c
	$(CC) $(CLFAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC)  $(OBJ_BONUS) -o $(NAME_BONUS) -fsanitize=address -g3


clean:
	rm -rf $(OBJC) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) 

re: fclean all