#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strstr of argv[2])"
gcc $CFLAG $CURR/strstr_test.c ft_strstr.c -I $DIR -o ft_strstr_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strstr of argv[2])"
gcc $CFLAG $CURR/strstr_test.c ft_strstr.c -I $DIR -o strstr_test -D SYS0
OK
TARG0="Bonjour"
TARG1="jou"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strstr_test "$TARG0" "$TARG1")" "$(./strstr_test "$TARG0" "$TARG1")"
TARG0="Coucou comment va tu ?"
TARG1="t va"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strstr_test "$TARG0" "$TARG1")" "$(./strstr_test "$TARG0" "$TARG1")"
TARG0="yeah boiii"
TARG1="z"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strstr_test "$TARG0" "$TARG1")" "$(./strstr_test "$TARG0" "$TARG1")"
TARG0="How was it"
TARG1="How was it"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strstr_test "$TARG0" "$TARG1")" "$(./strstr_test "$TARG0" "$TARG1")"
TARG0="How was it"
TARG1=""
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strstr_test "$TARG0" "$TARG1")" "$(./strstr_test "$TARG0" "$TARG1")"
#END METHOD
trap : 0

exit $EXITCODE
