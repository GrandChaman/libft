#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation ft_isalpha_test"
gcc $CFLAG $CURR/isalpha_test.c ft_isalpha.c -I $DIR -o ft_isalpha_test -D FT0
OK
./ft_isalpha_test
#END METHOD
trap : 0

exit $EXITCODE
