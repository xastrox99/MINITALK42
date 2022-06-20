# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:37:33 by mbaazzy           #+#    #+#              #
#    Updated: 2022/04/10 00:57:57 by mbaazzy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

s_client = client.c
s_server = server.c
s_client_bonus = client_bonus.c
s_server_bonus = server_bonus.c

o_client = $(s_client:.c=.o)
o_server = $(s_server:.c=.o)
o_client_bonus = $(s_client_bonus:.c=.o)
o_server_bonus = $(s_server_bonus:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC     = cc

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(o_client)
				$(CC) $(CFLAGS) $(o_client) -o $@
$(NAME_SERVER) : $(o_server)
				$(CC) $(CFLAGS) $(o_server) -o $@

bonus : $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS) : $(o_client_bonus)
					$(CC) $(CFLAGS) $(o_client_bonus) -o $@
$(NAME_SERVER_BONUS) : $(o_server_bonus)
					$(CC) $(CFLAGS) $(o_server_bonus) -o $@
clean:
	rm -rf $(o_client) $(o_server) $(o_server_bonus) $(o_client_bonus)

fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all