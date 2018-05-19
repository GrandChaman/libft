#!/usr/bin/env bash
BASE=$(dirname $0)
source $BASE/utils.sh
exec > >(column -ts "\\")
check_if_ok "diff <($BASE/rgxp_main 'sa*' 'sa patate c'est sa patate a samanta')
	<(echo 'sa patate c'est sa patate a samanta\nsa patate a samanta\nsamanta\n=> 0')"
