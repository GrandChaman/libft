#!/bin/sh
set -e
abort()
{
    exit 123
}
trap 'abort' 0
set -e
source ../foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (Search in all string for char)"
gcc $CFLAG $1/memchr_test.c ft_memchr.c -I../include -o ft_memchr_test -D FT0
OK
printf "Compilation SYS0 (Search in all string for char)"
gcc $CFLAG $1/memchr_test.c ft_memchr.c -I../include -o memchr_test -D SYS0
OK
cmp_cmd "Comparaison" "$(./ft_memchr_test)" "$(./memchr_test)"
printf "Compilation FT1 (Will not found searched char)"
gcc $CFLAG $1/memchr_test.c ft_memchr.c -I../include -o ft_memchr_test -D FT1
OK
printf "Compilation SYS1 (Will not found searched char)"
gcc $CFLAG $1/memchr_test.c ft_memchr.c -I../include -o memchr_test -D SYS1
OK
cmp_cmd "Comparaison" "$(./ft_memchr_test)" "$(./memchr_test)"
printf "Compilation FT2 (Search for missing char)"
gcc $CFLAG $1/memchr_test.c ft_memchr.c -I../include -o ft_memchr_test -D FT2
OK
printf "Compilation SYS2 (Search for missing char)"
gcc $CFLAG $1/memchr_test.c ft_memchr.c -I../include -o memchr_test -D SYS2
OK
cmp_cmd "Comparaison" "$(./ft_memchr_test)" "$(./memchr_test)"

#END METHOD
trap : 0

exit $EXITCODE
