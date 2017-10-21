#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strcat of argv[2])"
gcc $CFLAG $CURR/strcat_test.c ft_strlen.c ft_strcat.c -I $DIR -o ft_strcat_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strcat of argv[2])"
gcc $CFLAG $CURR/strcat_test.c ft_strlen.c ft_strcat.c -I $DIR -o strcat_test -D SYS0
OK
TARG0="Hello World"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strcat_test "$TARG0")" "$(./strcat_test "$TARG0")"
TARG0="Je"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strcat_test "$TARG0")" "$(./strcat_test "$TARG0")"
TARG0="Hello World"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strcat_test "$TARG0")" "$(./strcat_test "$TARG0")"

#END METHOD
trap : 0

exit $EXITCODE
