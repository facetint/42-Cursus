# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: facetint <facetint@student.42kocaeli.com.  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 19:23:29 by facetint          #+#    #+#              #
#    Updated: 2023/10/06 19:23:37 by facetint         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME            =   minitalk

SERVER			=	server
SERVER_SRC		=	server_bonus.c


CLIENT			=	client
CLIENT_SRC		=	client_bonus.c


UTILS_SRC		=	utils.c 

CC				=	gcc
RM 				=	rm -rf
FLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER) :
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)


$(CLIENT) :
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)

clean :
	$(RM) $(SERVER) $(CLIENT)

fclean :
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re 
