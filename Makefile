# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 17:32:30 by fprosper          #+#    #+#              #
#    Updated: 2023/03/01 18:48:42 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client
SERVER = server.c
CLIENT = client.c
OBJS_SERVER = $(SERVER:.c=.o)
OBJS_CLIENT = $(CLIENT:.c=.o)
FT_PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f 

all: 		server client
			make clean

server:		$(OBJS_SERVER)
			make -C ./ft_printf
			$(CC) $(CFLAGS) -o $(NAME1) $(OBJS_SERVER) $(FT_PRINTF) $(SERVER)

client:		$(OBJS_CLIENT)
			make -C ./ft_printf
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME2) $(OBJS_CLIENT) $(FT_PRINTF) $(LIBFT)
			$(CLIENT)

clean:
			$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
			make clean -C ./ft_printf
			make clean -C ./libft

fclean: 	clean
			$(RM) $(NAME1) $(NAME2)
			make fclean -C ./ft_printf
			make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re server client