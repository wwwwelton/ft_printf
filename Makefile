LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES			=	handler_char.c handler_decimal.c handler_integer.c
SOURCES			+=	handler_percent.c handler_pointer.c
SOURCES			+=	handler_string.c handler_u_hexadecimal.c
SOURCES			+=	handler_uinteger.c ft_printf.c ft_printf_utils.c
SOURCES			+=	ft_parse_flags.c ft_parse_ch_dec_int.c
SOURCES			+=	ft_parse_un_int_hex.c

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
