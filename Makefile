# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 18:19:29 by lseabra-          #+#    #+#              #
#    Updated: 2025/05/20 17:43:48 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
MKDIR = mkdir -p
RM = rm -f
RMDIR = rm -rf

NAME = get_next_line.a
BUILD_PATH = build
SRCS = get_next_line.c get_next_line_utils.c 
OBJS = $(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))
#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) | $(BUILD_PATH)
	$(AR) $(NAME) $(OBJS)

$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR) $(BUILD_PATH)

clean:
	$(RMDIR) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all