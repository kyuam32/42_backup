# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 19:06:46 by namkyu            #+#    #+#              #
#    Updated: 2021/06/15 18:47:19 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get install -y mariadb-server

COPY ./mariadb.conf.d/50-server.cnf /etc/mysql/my.cnf
COPY ./tools/run.sh ./run.sh
COPY ./tools/entrypoint.sh ./entrypoint.sh
RUN chmod 775 ./entrypoint.sh
#RUN chown -R mysql:mysql /var/lib/mysql
CMD ./entrypoint.sh

