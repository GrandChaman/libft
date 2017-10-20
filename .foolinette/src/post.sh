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
CFLAG='-Wall -Wextra -Werror'
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

rm -f ft_memset_test
rm -f memset_test
rm -f ft_bzero
rm -f bzero
rm -f ft_memcpy_test
rm -f memcpy_test
rm -f ft_memccpy_test
rm -f memccpy_test
rm -f ft_memmove_test
rm -f memmove_test
rm -f ft_memchr_test
rm -f memchr_test
rm -f ft_memcmp_test
rm -f memcmp_test
rm -f ft_strlen_test
rm -f strlen_test
rm -f ft_strcpy_test
rm -f strcpy_test
cd $DIR
cd ..
make fclean
#END METHOD
trap : 0
exit $EXITCODE
