#!/bin/sh
set -e
abort()
{
    exit 123
}
trap 'abort' 0
set -e

cd $2
cd ..
make fclean
make

trap : 0
exit 0
