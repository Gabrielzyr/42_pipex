SRCS = ft_isascii.c ft_isalnum.c ft_isprint.c ft_atoi.c ft_isdigit.c ft_isalpha.c\
ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strdup.c\
ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c\
ft_memcmp.c ft_calloc.c ft_strnstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
ft_putendl_fd.c ft_itoa.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c\
ft_striteri.c ft_strjoin_free.c ft_strchr_no_null.c ft_substr_free.c get_next_line.c\
ft_printf.c ft_printf_utils.c ft_printf_conversors.c ft_printf_conversor_x.c

OBJS = $(SRCS:%.c=%.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

B_OBJS = $(BONUS:%.c=%.o)

NAME = libft.a

CC = gcc 
       
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

bonus: $(B_OBJS) 
	$(CC) $(CFLAGS) -c $(BONUS)
	ar -crs $(NAME) $(B_OBJS)

clean: 
	rm -f *.o
	rm -rf ./a.out

fclean: clean
	rm -f $(NAME)

re: fclean all
