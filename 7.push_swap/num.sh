#! /bin/bash

ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./nlee/push_swap/cmake-build-debug/push_swap/push_swap $ARG | ./nlee/push_swap/cmake-build-debug/checker/checker $ARG; ./nlee/push_swap/cmake-build-debug/push_swap/push_swap $ARG | wc -l
