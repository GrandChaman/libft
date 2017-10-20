#!/bin/sh
set -e
abort()
{
    exit 123
}
trap 'abort' 0
set -e
source ../foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strcpy of argv[2])"
gcc $CFLAG $1/strcpy_test.c ft_strcpy.c -I../includes -o ft_strcpy_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strcpy of argv[2])"
gcc $CFLAG $1/strcpy_test.c ft_strcpy.c -I../includes -o strcpy_test -D SYS0
OK
TARG="Hello World"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_strcpy_test "$TARG")" "$(./strcpy_test "$TARG")"
TARG="wiefhwjfekwefkjbwefb"
cmp_cmd "Test with : \"$TARG\"" "$(./ft_strcpy_test "$TARG")" "$(./strcpy_test "$TARG")"
TARG="wojfwpfokpeofkpwef w ewe  we wf we w "
cmp_cmd "Test with : \"$TARG\"" "$(./ft_strcpy_test "$TARG")" "$(./strcpy_test "$TARG")"
TARG=""
cmp_cmd "Test with : \"$TARG\"" "$(./ft_strcpy_test "$TARG")" "$(./strcpy_test "$TARG")"

#END METHOD
trap : 0

exit $EXITCODE
