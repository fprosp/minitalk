# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 17:32:30 by fprosper          #+#    #+#              #
#    Updated: 2023/03/06 15:36:39 by fprosper         ###   ########.fr        #
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

all: 		libs server client

server:		$(OBJS_SERVER)
			$(CC) $(CFLAGS) $(OBJS_SERVER) $(FT_PRINTF) -o $(NAME1)

client:		$(OBJS_CLIENT) 
			$(CC) $(CFLAGS) $(OBJS_CLIENT) $(FT_PRINTF) $(LIBFT) -o $(NAME2)

libs:		
			make -C ./libft
			make -C ./ft_printf

clean:
			$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
			make clean -C ./libft
			make clean -C ./ft_printf

fclean: 	clean
			$(RM) $(NAME1) $(NAME2)
			make fclean -C ./libft
			make fclean -C ./ft_printf

re: fclean all

.PHONY: all libs clean fclean re 