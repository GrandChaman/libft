#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)stritoa of argv[2])"
gcc $CFLAG $CURR/stritoa_test.c ft_stritoa.c -I $DIR -o ft_stritoa_test -D FT0
OK
TARG0="12"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_stritoa_test "$TARG0")" $TARG0
TARG0="23487"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_stritoa_test "$TARG0")" $TARG0
TARG0="39090"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_stritoa_test "$TARG0")" $TARG0
TARG0="0"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_stritoa_test "$TARG0")" $TARG0
TARG0="-233"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_stritoa_test "$TARG0")" $TARG0
TARG0="-2147483648"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_stritoa_test "$TARG0")" $TARG0
TARG0="2147483647"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_stritoa_test "$TARG0")" $TARG0
#END METHOD
trap : 0

exit $EXITCODE
