#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strrchr of argv[2])"
gcc $CFLAG $CURR/strrchr_test.c ft_strlen.c ft_strrchr.c -I $DIR -o ft_strrchr_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strrchr of argv[2])"
gcc $CFLAG $CURR/strrchr_test.c ft_strlen.c ft_strrchr.c -I $DIR -o strrchr_test -D SYS0
OK
TARG0="z"
cmp_cmd "Test with : \"Bamboozled\" and \"$TARG0\"" "$(./ft_strrchr_test "$TARG0")" "$(./strrchr_test "$TARG0")"
TARG0="B"
cmp_cmd "Test with : \"Bamboozled\" and \"$TARG0\"" "$(./ft_strrchr_test "$TARG0")" "$(./strrchr_test "$TARG0")"
TARG0=""
cmp_cmd "Test with : \"Bamboozled\" and \"$TARG0\"" "$(./ft_strrchr_test "$TARG0")" "$(./strrchr_test "$TARG0")"
TARG0="v"
cmp_cmd "Test with : \"Bamboozled\" and \"$TARG0\"" "$(./ft_strrchr_test "$TARG0")" "$(./strrchr_test "$TARG0")"
#END METHOD
trap : 0

exit $EXITCODE
