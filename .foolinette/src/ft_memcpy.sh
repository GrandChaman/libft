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

printf "Compilation FT0 (Copy all string)"
gcc $CFLAG $1/memcpy_test.c ft_memcpy.c ft_bzero.c ft_memset.c -I../includes -o ft_memcpy_test -D FT0
OK
printf "Compilation SYS0 (Copy all string)"
gcc $CFLAG $1/memcpy_test.c ft_memcpy.c ft_bzero.c ft_memset.c -I../includes -o memcpy_test -D SYS0
OK
cmp_cmd "Comparaison" "$(./ft_memcpy_test)" "$(./memcpy_test)"

printf "Compilation FT1 (Copy 5 chars)"
gcc $CFLAG $1/memcpy_test.c ft_memcpy.c ft_bzero.c ft_memset.c -I../includes -o ft_memcpy_test -D FT1
OK
printf "Compilation SYS1 (Copy 5 chars)"
gcc $CFLAG $1/memcpy_test.c ft_memcpy.c ft_bzero.c ft_memset.c -I../includes -o memcpy_test -D SYS1
OK
cmp_cmd "Comparaison" "$(./ft_memcpy_test)" "$(./memcpy_test)"
printf "Compilation FT2 (Copy zero char)"
gcc $CFLAG $1/memcpy_test.c ft_memcpy.c ft_bzero.c ft_memset.c -I../includes -o ft_memcpy_test -D FT2
OK
printf "Compilation SYS2 (Copy zero char)"
gcc $CFLAG $1/memcpy_test.c ft_memcpy.c ft_bzero.c ft_memset.c -I../includes -o memcpy_test -D SYS2
OK
cmp_cmd "Comparaison" "$(./ft_memcpy_test)" "$(./memcpy_test)"
printf "Compilation FT3 (Check return value)"
gcc $CFLAG $1/memcpy_test.c ft_memcpy.c ft_bzero.c ft_memset.c -I../includes -o ft_memcpy_test -D FT3
OK
cmp_cmd "Comparaison" "$(./ft_memcpy_test)" "OK"
#END METHOD
trap : 0

exit $EXITCODE
