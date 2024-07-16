# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 13:58:01 by jalombar          #+#    #+#              #
#    Updated: 2024/07/16 14:37:07 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = minitalk.h
CLIENT_SRCS = client.c
C_BONUS_SRCS = client_bonus.c
SERVER_SRCS = server.c
S_BONUS_SRCS = server_bonus.c
CLIENT = client
C_BONUS = client_bonus
SERVER = server
S_BONUS = server_bonus
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(CLIENT) $(SERVER)

bonus: $(C_BONUS) $(S_BONUS)

$(CLIENT): $(CLIENT_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_PATH) -lft

$(SERVER): $(SERVER_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(LIBFT_PATH) -lft

$(C_BONUS): $(C_BONUS_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(C_BONUS_SRCS) -L$(LIBFT_PATH) -lft

$(S_BONUS): $(S_BONUS_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(S_BONUS_SRCS) -L$(LIBFT_PATH) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	rm -f $(C_BONUS)
	rm -f $(S_BONUS)

re: fclean all