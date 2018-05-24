#!/usr/bin/env bash
BASE=$(dirname $0)
source $BASE/utils.sh
check_if_ok "gcc $BASE/rgxp_main.c $BASE/../bin/libft.a -o $BASE/rgxp_main -I \
	$BASE/.."
check_if_ok "diff <($BASE/rgxp_main 'sa*' 'saaaaaaa' 2>&-) \
	<(printf 'Match : saaaaaaa\n=> 0\n')"
check_if_ok "diff <($BASE/rgxp_main 'sa*e' 'saaaaaae' 2>&-) \
	<(printf 'Match : saaaaaae\n=> 0\n')"
check_if_ok "diff <($BASE/rgxp_main 'sa*' 'saaaaaae' 2>&-) \
	<(printf 'Match : saaaaaa\n=> 0\n')"
check_if_ok "diff <($BASE/rgxp_main 'sa*' 'saaaaaaa saaaaaaaaaaa' 2>&-) \
	<(printf 'Match : saaaaaaa\nMatch : saaaaaaaaaaa\n=> 0\n')"
check_if_ok "diff <($BASE/rgxp_main 'Salu*t Co.*t ca va *' 'Salut Comment ca va ?' 2>&-) \
	<(printf 'Match : Salut Comment ca va \n=> 0\n')"
IFS='%'
check_if_ok "diff <($BASE/rgxp_main '*' 'Coucou Ca va ?' 2>&-) \
	<(printf 'Match : Coucou Ca va ?\nMatch : oucou Ca va ?\nMatch : ucou Ca va ?\nMatch : cou Ca va ?\nMatch : ou Ca va ?\nMatch : u Ca va ?\nMatch :  Ca va ?\nMatch : Ca va ?\nMatch : a va ?\nMatch :  va ?\nMatch : va ?\nMatch : a ?\nMatch :  ?\nMatch : ?\n=> 0\n')"
unset IFS
