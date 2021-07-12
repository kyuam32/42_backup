# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 20:52:22 by namkyu            #+#    #+#              #
#    Updated: 2021/06/22 17:14:03 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOC_PATH := $(shell pwd)/srcs/
DOC_INIT := docker-compose --project-directory $(DOC_PATH) --file $(DOC_PATH)docker-compose.yml --project-name inception
DATA_PATH = home/nlee
RM = rm -rf

all : up

up : 
	$(DOC_INIT) up -d --build

# setup :
# 	$(Need a pwd to change localhost url)
# 	$(shell echo '127.0.0.1 nlee.42.fr' | sudo tee -a /etc/hosts > /dev/null)

clean : 
	# $(DOC_INIT) down --rmi all
	$(DOC_INIT) down

fclean : 
	# $(DOC_INIT) down --rmi all -v
	$(DOC_INIT) down --rmi all -v
		
re : fclean all

prune: 
	docker system prune --all --force --volumes
# sudo rm -rf $(DATA_PATH)

.PHONY: all up clean fclean re prune
