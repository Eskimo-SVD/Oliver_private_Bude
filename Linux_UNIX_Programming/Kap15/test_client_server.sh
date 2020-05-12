#! /bin/bash

set -v

./https_server 8080 testroot &
./https_client localhost 8080 /testfile
