#!/bin/sh
source ../foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strncat of argv[2])"
gcc $CFLAG $1/strncat_test.c ft_strlen.c ft_strncat.c -I../includes -o ft_strncat_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strncat of argv[2])"
gcc $CFLAG $1/strncat_test.c ft_strlen.c ft_strncat.c -I../includes -o strncat_test -D SYS0
OK
TARG0="Hello World"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strncat_test "$TARG0")" "$(./strncat_test "$TARG0")"
TARG0="Je"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strncat_test "$TARG0")" "$(./strncat_test "$TARG0")"
TARG0="Hello World"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strncat_test "$TARG0")" "$(./strncat_test "$TARG0")"

#END METHOD
trap : 0

exit $EXITCODE
