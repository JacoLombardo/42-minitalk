# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 13:58:01 by jalombar          #+#    #+#              #
#    Updated: 2024/07/05 15:18:42 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc   
CFLAGS = -Wall -Werror -Wextra
HEADER = minitalk.h
CLIENT_SRCS = client.c client_utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT = client
SERVER = server
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) -L$(LIBFT_PATH) -lft

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) -L$(LIBFT_PATH) -lft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):	
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT)
	rm -f $(SERVER)

re: fclean all