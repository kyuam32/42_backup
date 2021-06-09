# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 13:39:09 by namkyu            #+#    #+#              #
#    Updated: 2021/06/09 13:44:07 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y wget

RUN wget https://download.redis.io/releases/redis-6.2.4.tar.gz
COPY ./tools/entrypoint.sh ./