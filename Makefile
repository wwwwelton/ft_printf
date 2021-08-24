LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES			=	ft_convert_char.c ft_convert_decimal.c
SOURCES			+=	ft_convert_percent.c ft_convert_pointer.c
SOURCES			+=	ft_convert_string.c ft_convert_u_hexadecimal.c
SOURCES			+=	ft_convert_uinteger.c ft_printf.c ft_printf_utils.c
SOURCES			+=	ft_replace_flags.c ft_replace_ch_dec_int.c
SOURCES			+=	ft_replace_u_int_hx.c

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
