# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 19:06:46 by namkyu            #+#    #+#              #
#    Updated: 2021/05/28 13:32:03 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade

# ARG MYSQL_USER
# ARG MYSQL_PASSWORD
# ARG MYSQL_DB_NAME

RUN apt-get -y install php7.3-fpm
RUN apt-get -y install php-mysql
RUN apt-get -y install php-mbstring

RUN mkdir -p /var/www/wordpress
COPY ./pool.d/www.conf ./etc/php/7.3/fpm/pool.d/www.conf
COPY ./src/wordpress /var/www/wordpress

COPY ./config/wp-config.php /var/www/wordpress
COPY ./tools/entrypoint.sh ./entrypoint.sh
RUN chmod 775 ./entrypoint.sh

CMD ./entrypoint.sh