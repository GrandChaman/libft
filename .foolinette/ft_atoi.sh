#!/bin/sh
set -e
abort()
{
    exit 123
}
trap 'abort' 0
set -e
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)atoi of argv[2])"
gcc $CFLAG $CURR/atoi_test.c ft_isdigit.c ft_atoi.c -I $DIR -o ft_atoi_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)atoi of argv[2])"
gcc $CFLAG $CURR/atoi_test.c ft_isdigit.c ft_atoi.c -I $DIR -o atoi_test -D SYS0
OK
TARG="18"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_atoi_test "$TARG")" "$(./atoi_test "$TARG")"
TARG="0"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_atoi_test "$TARG")" "$(./atoi_test "$TARG")"
TARG="-15"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_atoi_test "$TARG")" "$(./atoi_test "$TARG")"
TARG="              12"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_atoi_test "$TARG")" "$(./atoi_test "$TARG")"
TARG="              d12"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_atoi_test "$TARG")" "$(./atoi_test "$TARG")"
TARG="              12  13"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_atoi_test "$TARG")" "$(./atoi_test "$TARG")"
TARG="2147483647"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_atoi_test "$TARG")" "$(./atoi_test "$TARG")"
TARG="-2147483648"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_atoi_test "$TARG")" "$(./atoi_test "$TARG")"

#END METHOD
trap : 0

exit $EXITCODE
