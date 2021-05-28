#! /bin/bash

./run.sh
service mysql start 
mysql -u root < setup.sql
mysqld_safe