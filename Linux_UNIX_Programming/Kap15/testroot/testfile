#! /bin/sh

mkdir -p cert && cd cert

openssl genrsa -des3 -out server.key 4096
openssl req -new -key server.key -out server.csr
openssl x509 -req -days 3650 -in server.csr -signkey server.key -out server.crt
openssl rsa -in server.key -out server.key.insecure
openssl rsa -in server.key.insecure -pubout > server.pub
