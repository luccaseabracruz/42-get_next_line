# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 18:19:29 by lseabra-          #+#    #+#              #
#    Updated: 2025/05/21 19:10:24 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
MKDIR = mkdir -p
TCH = touch
RM = rm -f
RMDIR = rm -rf

NAME = get_next_line.a
BUILD_PATH = build
SRCS = get_next_line.c get_next_line_utils.c 
OBJS = $(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c 
OBJS_BONUS = $(addprefix $(BUILD_PATH)/, $(SRCS_BONUS:.c=.o))
BONUS_MARK = .bonus


#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) | $(BUILD_PATH)
	$(AR) $(NAME) $(OBJS)

$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(OBJS_BONUS) | $(BUILD_PATH)
	$(AR) $(NAME) $(OBJS_BONUS)
	$(TCH) $(BONUS_MARK)

$(BUILD_PATH):
	$(MKDIR) $(BUILD_PATH)

clean:
	$(RMDIR) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME) $(BONUS_MARK)

re: fclean all