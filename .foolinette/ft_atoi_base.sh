#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)atoi_base of argv[2])"
gcc $CFLAG $CURR/atoi_base_test.c ft_strlen.c ft_iswhitespace.c ft_pow.c ft_atoi_base.c -I $DIR -o ft_atoi_base_test -D FT0
OK
TARG0="1F4"
TARG1="0123456789ABCDEF"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_atoi_base_test "$TARG0" "$TARG1")" "500"
TARG0="7FF"
TARG1="0123456789ABCDEF"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_atoi_base_test "$TARG0" "$TARG1")" "2047"
TARG0="-1011"
TARG1="01"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_atoi_base_test "$TARG0" "$TARG1")" "-11"
TARG0="7FFFFFFF"
TARG1="0123456789ABCDEF"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_atoi_base_test "$TARG0" "$TARG1")" "2147483647"
TARG0="-80000000"
TARG1="0123456789ABCDEF"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_atoi_base_test "$TARG0" "$TARG1")" "-2147483648"
TARG0="0"
TARG1="0123456789ABCDEF"
cmp_cmd "Test with : \"$TARG0\" and \"$TARG1\"" "$(./ft_atoi_base_test "$TARG0" "$TARG1")" "0"

#END METHOD
trap : 0

exit $EXITCODE
