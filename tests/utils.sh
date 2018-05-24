#!/usr/bin/env bash

RED="\033[1;31"m
GREEN="\033[1;32m"
NC="\033[0m"

function check_if_ok {
eval $1
last_val=$?
if [ $last_val -ne 0 ]
then
	echo -n "==> $1"
	echo -e $RED "  KO " "$NC"
	exit $last_val
else
	echo -n "==> $1"
	echo -e $GREEN "  OK " "$NC"
fi
}
