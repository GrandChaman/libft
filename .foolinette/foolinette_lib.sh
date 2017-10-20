#!/bin/sh
CURR=$1
DIR=$2
CFLAG='-Wall -Wextra -Werror'
CFLAG_OPTI='-Wall -Wextra -Werror -O3'
CFLAG_O='-c -Wall -Wextra -Werror'
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
	if [[ "$2" == "$3"  ]]
	then
		printf "%s" "${2:0:100}"
		if [[ ${2:100:101} != "" ]]
		then
			printf "..."
		fi
		printf " == "
		printf "%s" "${3:0:100}"
		if [[ ${3:100:101} != "" ]]
		then
			printf "..."
		fi
		OK
	else
		printf "%s" "${2:0:100}"
		if [[ ${2:100:101} != "" ]]
		then
			printf "..."
		fi
		printf " != "
		printf "%s" "${3:0:100}"
		if [[ ${3:100:101} != "" ]]
		then
			printf "..."
		fi
		KO
	fi
}
timer() {
	printf "TIMER > Command ($1) done in : "
	/usr/bin/time -p $1 2>&1 | grep real | rev | cut -d" " -f1 | rev
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
abort()
{
	TMPL=$?
	if [ $TMPL -eq 139 ]; then
    echo "${RED}===> SEGFAULT !${NC}"
	exit $TMPL
	fi
	if [ $TMPL -eq 134 ]; then
    echo "${RED}===> SIGTERM !${NC}"
	exit $TMPL
	fi
	if [ $TMPL != "0" ]; then
    exit $TMPL
	fi

}
trap 'abort' CHLD
set -bm
