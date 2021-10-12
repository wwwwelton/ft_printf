LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES			=	ft_convert_char.c ft_convert_decimal.c ft_convert_integer.c
SOURCES			+=	ft_convert_percent.c ft_convert_pointer.c
SOURCES			+=	ft_convert_string.c ft_convert_u_hex.c
SOURCES			+=	ft_convert_u_int.c ft_parse_args.c
SOURCES			+=	ft_printf_utils.c ft_printf.c ft_parse_utils.c

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	libftprintf.a

CC				=	clang
AR				=	ar
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
ARFLAGS 		=	rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)

all:			$(LIBFT) $(NAME)

bonus:			all


$(NAME):			$(OBJECTS)
				cp	$(LIBFT) $(NAME)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

run:
				clear && make && clang -Wall -Wextra -Werror -g3 -fsanitize=address *.c ./libft/libft.a && ./a.out

wrun:
				watch -n 0 "make && clang -Wall -Wextra -Werror -g3 -fsanitize=address *.c ./libft/libft.a && ./a.out"

norm:
				norminette $(SOURCES) ft_printf.h

.PHONY:			all clean fclean re libft
