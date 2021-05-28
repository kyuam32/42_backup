#!bin/sh

docker build -t test ./
docker run -it --name test -p 3306 test
