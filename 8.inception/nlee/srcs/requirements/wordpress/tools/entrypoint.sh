#!/bin/bash

service php7.3-fpm start
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
./wp-cli.phar core install --path=/var/www/wordpress --url="nlee.42.fr"  --title="Nlee's page" --admin_user="nlee" --admin_password="nlee" --admin_email="lnk@naver.com" --allow-root
service php7.3-fpm stop
php-fpm7.3 -F