# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 19:35:58 by fprosper          #+#    #+#              #
#    Updated: 2023/03/02 19:36:05 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

APP1 = server
APP2 = client
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBRARY = ft_printf/libftprintf.a
CLIENT =	client.c
SERVER =	server.c
OBJS_CLIENT = $(CLIENT:.c=.o)
OBJS_SERVER = $(SERVER:.c=.o)
all: lib server client
server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ -o $(APP1) $(LIBRARY)
client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $(APP2) $(LIBRARY)
lib:
	make -C ./ft_printf
norme:  all
	norminette server.c client.c minitalk.h ./ft_printf
deb: lib
	$(CC) $(CFLAGS) $(SERVER) -o $(APP1) -g $(LIBRARY)
	$(CC) $(CFLAGS) $(CLIENT) -o $(APP2) -g $(LIBRARY)
clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C ./ft_printf
fclean: clean
	$(RM) $(APP1) $(APP2)
	make fclean -C ./ft_printf
re: fclean all
.PHONY: all clean fclean re server client deb lib