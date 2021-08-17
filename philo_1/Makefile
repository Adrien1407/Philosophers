NAME = Philo_one

FUNCTIONS = ./srcs/main \
			./srcs/init_philo \
			./srcs/init_struct \
			./srcs/launchthread \
			./srcs/routine \
			./srcs/death_monitoring \
			./srcs/utils/get_time \
			./srcs/utils/ft_strlen \
			./srcs/utils/ft_atoi \
			./srcs/utils/is_digit \
			./srcs/utils/ft_putnbr \
			./srcs/utils/ft_usleep \
			
FLAGS = -Wall -Wextra -Werror 

SRC = $(addsuffix .c, $(FUNCTIONS))
EXCH = $(addsuffix .o, $(FUNCTIONS))


all: $(NAME) 

$(NAME): $(EXCH)
	clang $(FLAGS) $(EXCH) -o $(NAME) -pthread


%.o: %.c
	clang $(FLAGS) -o $@ -c $<

clean:
	/bin/rm -f ./srcs/*.o
	/bin/rm -f ./srcs/utils/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
