LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES			=	convert_char.c convert_decimal.c convert_integer.c
SOURCES			+=	convert_percent.c convert_pointer.c
SOURCES			+=	convert_string.c convert_u_hex.c
SOURCES			+=	convert_u_int.c parse_u_int_hex.c
SOURCES			+=	parse_flags.c parse_ch_dec_int.c
SOURCES			+=	ft_printf_utils.c ft_printf.c

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

.PHONY:			all clean fclean re libft
