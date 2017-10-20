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
gcc $CFLAG $1/memmove_test.c ft_memmove.c -I../include -o ft_memmove_test -D FT0
OK
printf "Compilation SYS0 (Copy all string)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c  -I../include -o memmove_test -D SYS0
OK
cmp_cmd "Comparaison" "$(./ft_memmove_test)" "$(./memmove_test)"
printf "Compilation FT1 (Copy 5 chars)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c -I../include -o ft_memmove_test -D FT1
OK
printf "Compilation SYS1 (Copy 5 chars)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c  -I../include -o memmove_test -D SYS1
OK
cmp_cmd "Comparaison" "$(./ft_memmove_test)" "$(./memmove_test)"
printf "Compilation FT2 (Copy with dest < src)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c -I../include -o ft_memmove_test -D FT2
OK
printf "Compilation SYS2 (Copy with dest < src)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c  -I../include -o memmove_test -D SYS2
OK
cmp_cmd "Comparaison" "$(./ft_memmove_test)" "$(./memmove_test)"
printf "Compilation FT3 (Copy with dest = src)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c -I../include -o ft_memmove_test -D FT3
OK
printf "Compilation SYS3 (Copy with dest = src)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c  -I../include -o memmove_test -D SYS3
OK
cmp_cmd "Comparaison" "$(./ft_memmove_test)" "$(./memmove_test)"
printf "Compilation FT4 (Copy with dest > src)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c -I../include -o ft_memmove_test -D FT4
OK
printf "Compilation SYS4 (Copy with dest > src)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c  -I../include -o memmove_test -D SYS4
OK
cmp_cmd "Comparaison" "$(./ft_memmove_test)" "$(./memmove_test)"
printf "Compilation FT5 (Check return value)"
gcc $CFLAG $1/memmove_test.c ft_memmove.c  -I../include -o ft_memmove_test -D FT5
OK
cmp_cmd "Comparaison" "$(./ft_memmove_test)" "OK"
#END METHOD
trap : 0

exit $EXITCODE
