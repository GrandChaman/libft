#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strchr of argv[2])"
gcc $CFLAG $CURR/strchr_test.c ft_strchr.c -I $DIR -o ft_strchr_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strchr of argv[2])"
gcc $CFLAG $CURR/strchr_test.c ft_strchr.c -I $DIR -o strchr_test -D SYS0
OK
TARG0="z"
cmp_cmd "Test with : \"Bamboozled\" and \"$TARG0\"" "$(./ft_strchr_test "$TARG0")" "$(./strchr_test "$TARG0")"
TARG0="B"
cmp_cmd "Test with : \"Bamboozled\" and \"$TARG0\"" "$(./ft_strchr_test "$TARG0")" "$(./strchr_test "$TARG0")"
TARG0=""
cmp_cmd "Test with : \"Bamboozled\" and \"$TARG0\"" "$(./ft_strchr_test "$TARG0")" "$(./strchr_test "$TARG0")"
TARG0="v"
cmp_cmd "Test with : \"Bamboozled\" and \"$TARG0\"" "$(./ft_strchr_test "$TARG0")" "$(./strchr_test "$TARG0")"
#END METHOD
trap : 0

exit $EXITCODE
