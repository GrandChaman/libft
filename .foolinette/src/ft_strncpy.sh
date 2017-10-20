#!/bin/sh
source ../foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strncpy of argv[2])"
gcc $CFLAG $1/strncpy_test.c ft_strncpy.c -I../includes -o ft_strncpy_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strncpy of argv[2])"
gcc $CFLAG $1/strncpy_test.c ft_strncpy.c -I../includes -o strncpy_test -D SYS0
OK
TARG0="Hello World"
TARG1="15"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strncpy_test "$TARG0" "$TARG1")" "$(./strncpy_test "$TARG0" "$TARG1")"
TARG0="Je suis"
TARG1="3"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strncpy_test "$TARG0" "$TARG1")" "$(./strncpy_test "$TARG0" "$TARG1")"
TARG0="Hello World"
TARG1="11"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strncpy_test "$TARG0" "$TARG1")" "$(./strncpy_test "$TARG0" "$TARG1")"

#END METHOD
trap : 0

exit $EXITCODE
