#! /bin/bash

./run.sh
service mysql start
mysql -u root < setup.sql
#chown -R mysql:mysql /var/lib/mysql
service mysql stop
mysqld_safe
