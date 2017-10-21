#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strlcat of argv[2])"
gcc $CFLAG $CURR/strlcat_test.c ft_strlen.c ft_strlcat.c -I $DIR -o ft_strlcat_test -D FT0
OK
printf "Compilation SYS0 (get (ft_)strlcat of argv[2])"
gcc $CFLAG $CURR/strlcat_test.c ft_strlen.c ft_strlcat.c -I $DIR -o strlcat_test -D SYS0
OK
TARG0="Hello World"
TARG1="Yooo"
TARG2="10"
cmp_cmd "SIZE < src < dest" "$(./ft_strlcat_test "$TARG0" "$TARG1" "$TARG2")" "$(./strlcat_test "$TARG0" "$TARG1" "$TARG2")"
TARG0="Hello World"
TARG1="Yooo"
TARG2="100"
cmp_cmd "SIZE > dest > src" "$(./ft_strlcat_test "$TARG0" "$TARG1" "$TARG2")" "$(./strlcat_test "$TARG0" "$TARG1" "$TARG2")"
TARG0="Hello World"
TARG1="Yooo"
TARG2="11"
cmp_cmd "SIZE == dest > src" "$(./ft_strlcat_test "$TARG0" "$TARG1" "$TARG2")" "$(./strlcat_test "$TARG0" "$TARG1" "$TARG2")"
TARG0="Hello World"
TARG1="Yooo"
TARG2="0"
cmp_cmd "SIZE == 0" "$(./ft_strlcat_test "$TARG0" "$TARG1" "$TARG2")" "$(./strlcat_test "$TARG0" "$TARG1" "$TARG2")"
TARG0="Hello World"
TARG1="Yooo"
TARG2="-1"
cmp_cmd "SIZE == -1" "$(./ft_strlcat_test "$TARG0" "$TARG1" "$TARG2")" "$(./strlcat_test "$TARG0" "$TARG1" "$TARG2")"
#END METHOD
trap : 0

exit $EXITCODE
