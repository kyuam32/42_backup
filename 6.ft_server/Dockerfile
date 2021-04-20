# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 14:11:29 by namkyu            #+#    #+#              #
#    Updated: 2021/04/20 16:56:04 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

# APT UPDATE
RUN apt-get -y update
RUN apt-get -y upgrade

# NGINX
RUN apt-get -y install nginx

# OPENSSL
RUN apt-get -y install openssl

# PHP
RUN apt-get -y install php7.3-fpm
RUN apt-get -y install php-mysql
RUN apt-get -y install php-mbstring

# MARIA DB
RUN apt-get -y install mariadb-server

# UTLIS
RUN apt-get -y install curl
RUN apt-get -y install vim
RUN apt-get -y install wget

WORKDIR /setup
COPY ./wordpress wordpress
COPY ./phpMyAdmin phpMyAdmin
COPY ./src/default default
COPY ./src/run.sh run.sh

CMD bash run.sh