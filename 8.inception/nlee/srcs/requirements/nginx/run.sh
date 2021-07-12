#!bin/sh

docker build -t test ./
docker run -it --name test -p 80:80 -p 443:443 test
