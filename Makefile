SRCS_LIST = \
ft_itohex.c\
ft_printf.c\
ft_printf_conv.c\
ft_printf_conv2.c\
ft_printf_display.c\
ft_printf_flag.c\
ft_ptohex.c\
ft_uitoa.c\
utils.c\
utils2.c

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_LIST}}

OBJS = ${SRCS:.c=.o}

HEADER_DIR = includes/

LIBFT_DIR = libft/
LIBFT_NAME = libft.a

LIBFT = ${addprefix ${LIBFT_DIR}, ${LIBFT_NAME}}

NAME = libftprintf.a

CC = gcc
CFLAGS= -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	make -C ${LIBFT_DIR}
	cp ${LIBFT} ./${NAME}
	ar -rc ${NAME} ${OBJS} ${LIBFT}
	
%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -I ${HEADER_DIR} -o $@ 

bonus : ${NAME}

clean :
	rm -f ${OBJS}
	make clean -C ${LIBFT_DIR}

fclean : clean
	rm -f ${NAME}
	make fclean -C ${LIBFT_DIR}

re	: fclean all

.PHONY : all bonus clean fclean re
