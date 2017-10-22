#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strncmp of argv[2])"
gcc $CFLAG $CURR/strncmp_test.c ft_strncmp.c -I $DIR -o ft_strncmp_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strncmp of argv[2])"
gcc $CFLAG $CURR/strncmp_test.c ft_strncmp.c -I $DIR -o strncmp_test -D SYS0
OK
TARG0="Bonjour"
TARG1="Bon"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strncmp_test "$TARG0" "$TARG1")" "$(./strncmp_test "$TARG0" "$TARG1")"
TARG0="Coucou comment va tu ?"
TARG1="Coucou comment va tu ?"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strncmp_test "$TARG0" "$TARG1")" "$(./strncmp_test "$TARG0" "$TARG1")"
TARG0="yeah boiii"
TARG1=""
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strncmp_test "$TARG0" "$TARG1")" "$(./strncmp_test "$TARG0" "$TARG1")"
TARG0="How was it"
TARG1="How was it"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strncmp_test "$TARG0" "$TARG1")" "$(./strncmp_test "$TARG0" "$TARG1")"
TARG0="How was it"
TARG1="How was iu"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_strncmp_test "$TARG0" "$TARG1")" "$(./strncmp_test "$TARG0" "$TARG1")"
#END METHOD
trap : 0

exit $EXITCODE
