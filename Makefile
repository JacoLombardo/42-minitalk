# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 13:58:01 by jalombar          #+#    #+#              #
#    Updated: 2024/07/08 14:23:01 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = minitalk.h
CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
C_BONUS_SRCS = client_bonus.c
C_BONUS_OBJS = $(C_BONUS_SRCS:.c=.o)
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
S_BONUS_SRCS = server_bonus.c
S_BONUS_OBJS = $(S_BONUS_SRCS:.c=.o)
CLIENT = client
C_BONUS = client_bonus
SERVER = server
S_BONUS = server_bonus
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(CLIENT) $(SERVER)

bonus: $(C_BONUS) $(S_BONUS)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) -L$(LIBFT_PATH) -lft

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) -L$(LIBFT_PATH) -lft

$(C_BONUS): $(C_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(C_BONUS_OBJS) -L$(LIBFT_PATH) -lft

$(S_BONUS): $(S_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(S_BONUS_OBJS) -L$(LIBFT_PATH) -lft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)
	rm -f $(C_BONUS_OBJS)
	rm -f $(S_BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	rm -f $(C_BONUS)
	rm -f $(S_BONUS)

re: fclean all