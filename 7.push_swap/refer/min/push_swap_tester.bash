#!/bin/bash
BLACK=$'\033[0;30m'
RED=$'\033[0;31m'
GREEN=$'\033[0;32m'
YELLOW=$'\033[0;33m'
BLUE=$'\033[0;34m'
PURPLE=$'\033[0;35m'
CYAN=$'\033[0;36m'
WHITE=$'\033[0;39m'

#==============================================================================

TESTER_DIR=./tester/

#==============================================================================

TESTER_EXEC=random_numbers
TESTER=$TESTER_DIR$TESTER_EXEC

function set_arg(){
	export ARG=$($TESTER ${1} ${2} ${3})
	echo -n "         ARG: "
	if [ "$1" -le 20 ]
	then
		echo $ARG
	else
		echo $1 elements
	fi
}

function test(){
	echo "      result:" $(./push_swap $ARG | ./checker $ARG)
	echo "instructions:" $(./push_swap $ARG | wc -l)
	echo $GREEN"------------------------------"$WHITE	
}

function run_test(){
	set_arg ${1} ${2} ${3}
	test
}

function run_test_arg(){
	export ARG="${1} ${2} ${3}"
	echo -n "         ARG: "
	echo $ARG
	test
}

make

run_test_arg 1 2 3
run_test_arg 1 3 2
run_test_arg 2 1 3
run_test_arg 2 3 1
run_test_arg 3 1 2
run_test_arg 3 2 1

run_test 4 1
run_test 4 1
run_test 4 1
run_test 4 1
run_test 4 1
run_test 5 1
run_test 5 1
run_test 5 1
run_test 5 1
run_test 5 1
run_test 5 1
run_test 5 1
run_test 100 1
run_test 100 1
run_test 100 1
run_test 100 1
run_test 100 1
run_test 100 1
run_test 500 1
run_test 500 1
run_test 500 1
run_test 500 1
run_test 500 1
run_test 500 1
