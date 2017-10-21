#!/bin/sh
source ../foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strlcat of argv[2])"
gcc $CFLAG $1/strlcat_test.c ft_strlen.c ft_strlcat.c -I../includes -o ft_strlcat_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strlcat of argv[2])"
gcc $CFLAG $1/strlcat_test.c ft_strlen.c ft_strlcat.c -I../includes -o strlcat_test -D SYS0
OK
TARG0="Hello World"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strlcat_test "$TARG0")" "$(./strlcat_test "$TARG0")"
TARG0="Je"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strlcat_test "$TARG0")" "$(./strlcat_test "$TARG0")"
TARG0="Hello World"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strlcat_test "$TARG0")" "$(./strlcat_test "$TARG0")"

#END METHOD
trap : 0

exit $EXITCODE
