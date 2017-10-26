#!/bin/sh
source ./foolinette_lib.sh
# BEGIN METHOD

printf "Compilation FT0 (get (ft_)strsplit of argv[2])"
gcc $CFLAG $CURR/strsplit_test.c ft_strsub.c ft_putstr.c ft_putstr_fd.c ft_strlen.c ft_strsplit.c -I $DIR -o ft_strsplit_test -D FT0
OK
TARG0="Bonjour"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strsplit_test "$TARG0")" "[[Bonjour]]"
TARG0="Coucou comment vas tu ?"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strsplit_test "$TARG0")" "[[Coucou][comment][vas][tu][?]]"
TARG0="yeah boiii"
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strsplit_test "$TARG0")" "[[yeah][boiii]]"
TARG0="           How was it          "
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strsplit_test "$TARG0")" "[[How][was][it]]"
TARG0="How was it            ???? "
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strsplit_test "$TARG0")" "[[How][was][it][????]]"
TARG0=""
cmp_cmd "Test with : \"$TARG0\"" "$(./ft_strsplit_test "$TARG0")" "[]"
#END METHOD
trap : 0

exit $EXITCODE
