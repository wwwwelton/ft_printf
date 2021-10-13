LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES			=	ft_convert_char.c ft_convert_decimal.c ft_convert_integer.c
SOURCES			+=	ft_convert_percent.c ft_convert_pointer.c
SOURCES			+=	ft_convert_string.c ft_convert_u_hex.c
SOURCES			+=	ft_convert_u_int.c ft_parse_args.c
SOURCES			+=	ft_printf_utils.c ft_printf.c ft_parse_utils.c

HEADER			=	ft_printf.h

OBJ_DIR			=	objects

OBJECTS			=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)

NAME			=	libftprintf.a

CC				=	clang
AR				=	ar
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror
ARFLAGS 		=	rcs

$(OBJ_DIR)/%.o:		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJECTS) $(HEADER)
				cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH) bonus

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft
