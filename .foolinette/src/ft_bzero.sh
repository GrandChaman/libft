#!/bin/sh
set -e
abort()
{
    exit 123
}
trap 'abort' 0
set -e
CURR=$1
DIR=$2
CFLAG='-Wall -Wextra -Werror -O3'
cd $DIR
GREEN='\033[0;32m'
RED='\033[1;31m'
NC='\033[0m'
OK () {
   echo " -> ${GREEN}OK${NC}"
}
KO () {
   echo " -> ${RED}KO${NC}"
   EXITCODE=1
}
cmp_cmd() {
	echo $1
	if [[ $2 == $3 ]]
	then
		printf "${2:0:100} == ${3:0:100}"
		OK
	else
		printf "${2:0:100} != ${3:0:100}"
		KO
	fi
}
EXITCODE=0
printf "Norminette"
norminette $CURR
if [[ $(norminette $CURR | grep -E '^(Error|Warning)') == "" ]]
then
	OK
else
	KO
fi
# BEGIN METHOD

printf "Compilation FT0 (5 First chars)"
gcc $CFLAG $1/bzero_test.c ft_memset.c ft_bzero.c -I../includes -o ft_bzero -D FT0
OK
printf "Compilation SYS0 (5 First chars)"
gcc $CFLAG $1/bzero_test.c ft_memset.c ft_bzero.c -I../includes -o bzero -D SYS0
OK
cmp_cmd "Comparaison" "$(./bzero)" "$(./ft_bzero)"
printf "Compilation FT1 (All chars)"
gcc $CFLAG $1/bzero_test.c ft_memset.c ft_bzero.c -I../includes -o ft_bzero -D FT1
OK
printf "Compilation SYS1 (All chars)"
gcc $CFLAG $1/bzero_test.c ft_memset.c ft_bzero.c -I../includes -o bzero -D SYS1
OK
cmp_cmd "Comparaison" "$(./bzero)" "$(./ft_bzero)"
printf "Compilation FT2 (Zero char)"
gcc $CFLAG $1/bzero_test.c ft_memset.c ft_bzero.c -I../includes -o ft_bzero -D FT2
OK
printf "Compilation SYS2 (Zero char)"
gcc $CFLAG $1/bzero_test.c ft_memset.c ft_bzero.c -I../includes -o bzero -D SYS2
OK
cmp_cmd "Comparaison" "$(./bzero)" "$(./ft_bzero)"
#END METHOD
trap : 0

exit $EXITCODE
