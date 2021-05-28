#!bin/sh

docker build -t test ./
docker run -d --name test -p 80:80 -p 443:443 test
