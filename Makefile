# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 18:47:59 by rle               #+#    #+#              #
#    Updated: 2017/12/06 14:02:43 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

OBJS = $(addprefix ./srcs/, \
			$(addsuffix .o, \
				$(addprefix env/, \
					get_env \
					set_env \
					unset_env \
					print_env \
					get_env_val \
				) \
				$(addprefix commands/, \
					get_next_command \
					execute_commands \
					check_command \
					print_working_dir \
					path_command \
					echo_command \
					change_directory \
				) \
				$(addprefix helpers/, \
					display_prompt \
					clear_whitespaces \
					free_str_arr \
				) \
				main \
			) \
		)

CFLAGS = -Wall -Werror -Wextra

CC = @gcc

INCLUDES = -I ./includes -I ./libft/includes

LIB = libft

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)/libft.a $(INCLUDES) -o $(NAME)
	@echo "\x1B[31mminishell made"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIB): force
	@make -C $(LIB)

force: 
	@true

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIB)
	@echo "\x1B[34m~~~clean~~~"

fclean: clean
	@rm -f $(NAME)

re: fclean all
