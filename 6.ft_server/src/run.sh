# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 14:43:50 by namkyu            #+#    #+#              #
#    Updated: 2021/04/20 18:34:21 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "Moving files in container..."
mv default ../etc/nginx/sites-available
mv wordpress ../var/www/html
mv phpMyAdmin ../var/www/html

chown -R www-data:www-data ../var/www/*
chmod -R 755 ../var/www/*

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/L=Seoul/O=42seoul/OU=nlee/CN=localhost" -keyout ../etc/ssl/private/ft_server.key -out ../etc/ssl/certs/ft_server.crt
chmod 600 ../etc/ssl/certs/ft_server.crt ../etc/ssl/private/ft_server.key

service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'nlee'@'localhost' IDENTIFIED BY 'nlee';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'nlee'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password

service nginx start
service php7.3-fpm start

cd ../
rm -rf ./setup

bash