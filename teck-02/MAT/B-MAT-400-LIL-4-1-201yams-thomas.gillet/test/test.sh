#! /bin/bash


test_opt1=$(./FASTAtools 1 < test/result/list4)
test_opt1_=$(cat test/result/rep1)

test_opt2=$(./FASTAtools 2 < test/result/list4)
test_opt2_=$(cat test/result/rep2)

test_opt3=$(./FASTAtools 3 < test/result/list4)
test_opt3_=$(cat test/result/rep3)

test_opt4_1=$(./FASTAtools 4 1 < test/result/list4)
test_opt4_1_=$(cat test/result/rep4_1)

test_opt4_2=$(./FASTAtools 4 29 < test/result/list4)
test_opt4_2_=$(cat test/result/rep4_2)

test_opt5=$(./FASTAtools 5 < test/result/list4)
test_opt5_=$(cat test/result/rep5)

if [[ "$test_opt1" == "$test_opt1_" ]]
then
    echo "opt -> 1 : OK"
else
    echo "opt -> 1 : KO"
fi

if [[ "$test_opt2" == "$test_opt2_" ]]
then
    echo "opt -> 2 : OK"
else
    echo "opt -> 2 : KO"
fi

if [[ "$test_opt3" == "$test_opt3_" ]]
then
    echo "opt -> 3 : OK"
else
    echo "opt -> 3 : KO"
fi

if [[ "$test_opt4_1" == "$test_opt4_1_" ]]
then
    echo "opt -> 4 1 : OK"
else
    echo "opt -> 4 1 : KO"
fi

if [[ "$test_opt4_2" == "$test_opt4_2_" ]]
then
    echo "opt -> 4 29 : OK"
else
    echo "opt -> 4 29 : KO"
fi

if [[ "$test_opt5" == "$test_opt5_" ]]
then
    echo "opt -> 5 : OK"
else
    echo "opt -> 5 : KO"
fi