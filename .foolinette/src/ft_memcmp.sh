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

printf "Compilation FT0 (Compare all string)"
gcc $CFLAG $1/memcmp_test.c ft_memcmp.c -I../include -o ft_memcmp_test -D FT0
OK
printf "Compilation SYS0 (Compare all string)"
gcc $CFLAG $1/memcmp_test.c ft_memcmp.c -I../include -o memcmp_test -D SYS0
OK
cmp_cmd "Comparaison" "$(./ft_memcmp_test)" "$(./memcmp_test)"
printf "Compilation FT1 (Compare 5 first chars)"
gcc $CFLAG $1/memcmp_test.c ft_memcmp.c -I../include -o ft_memcmp_test -D FT1
OK
printf "Compilation SYS1 (Compare 5 first chars)"
gcc $CFLAG $1/memcmp_test.c ft_memcmp.c -I../include -o memcmp_test -D SYS1
OK
cmp_cmd "Comparaison" "$(./ft_memcmp_test)" "$(./memcmp_test)"
printf "Compilation FT2 (Comparing 0 char)"
gcc $CFLAG $1/memcmp_test.c ft_memcmp.c -I../include -o ft_memcmp_test -D FT2
OK
printf "Compilation SYS2 (Comparing 0 char)"
gcc $CFLAG $1/memcmp_test.c ft_memcmp.c -I../include -o memcmp_test -D SYS2
OK
cmp_cmd "Comparaison" "$(./ft_memcmp_test)" "$(./memcmp_test)"
printf "Compilation FT3 (Compare 3 first chars)"
gcc $CFLAG $1/memcmp_test.c ft_memcmp.c -I../include -o ft_memcmp_test -D FT3
OK
printf "Compilation SYS3 (Compare 3 first chars)"
gcc $CFLAG $1/memcmp_test.c ft_memcmp.c -I../include -o memcmp_test -D SYS3
OK
cmp_cmd "Comparaison" "$(./ft_memcmp_test)" "$(./memcmp_test)"

#END METHOD
trap : 0

exit $EXITCODE
