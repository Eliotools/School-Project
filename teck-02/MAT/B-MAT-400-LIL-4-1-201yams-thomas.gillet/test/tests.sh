#! /bin/bash

echo -e "\n\033[33mCes tests ne prennent en compte que les exemple du sujet sauf le 7. Pour d'avantage de tests libre a vous de gérer en reprenant la syntaxe\033[0m\n"

test_opt_1=$(../FASTAtools 1 < result/ex.fasta)
test_opt_1_r=$(cat result/n1.txt)

test_opt_2=$(../FASTAtools 2 < result/ex.fasta)
test_opt_2_r=$(cat result/n2.txt)

test_opt_3=$(../FASTAtools 3 < result/ex.fasta)
test_opt_3_r=$(cat result/n3.txt)

test_opt_4=$(../FASTAtools 4 29 < result/ex.fasta)
test_opt_4_r=$(cat result/n4.txt)

test_opt_4bis=$(../FASTAtools 4 1 < result/ex.fasta)
test_opt_4_rbis=$(cat result/n4bis.txt)

test_opt_5=$(../FASTAtools 5 < result/ex.fasta)
test_opt_5_r=$(cat result/n5.txt)

test_opt_6=$(../FASTAtools 6 < result/ex.fasta)
test_opt_6_r=$(cat result/n6.txt)

if [[ "$test_opt_1" == "$test_opt_1_r" ]]
then
    echo -e "Option 1: \033[32mOK\033[0m"
    if [[ -e result/Test1.txt ]]
    then
        rm -f result/Test1.txt
    fi
else
    echo -e "Option 1: \033[31mKO\033[0m"
    echo -e "Got:\n$test_opt_1\n\nNeeded:\n$test_opt_1_r" > result/Test1.txt
fi

if [[ "$test_opt_2" == "$test_opt_2_r" ]]
then
    echo -e "Option 2: \033[32mOK\033[0m"
    if [[ -e result/Test2.txt ]]
    then
        rm -f result/Test2.txt
    fi
else
    echo -e "Option 2: \033[31mKO\033[0m"
    echo -e "Got:\n$test_opt_2\n\nNeeded:\n$test_opt_2_r" > Erros/Test2.txt
fi

if [[ "$test_opt_3" == "$test_opt_3_r" ]]
then
    echo -e "Option 3: \033[32mOK\033[0m"
    if [[ -e result/Test3.txt ]]
    then
        rm -f result/Test3.txt
    fi
else
    echo -e "Option 3: \033[31mKO\033[0m"
    echo -e "Got:\n$test_opt_3\n\nNeeded:\n$test_opt_3_r" > result/Test3.txt
fi

if [[ "$test_opt_4" == "$test_opt_4_r" && "$test_opt_4bis" == "$test_opt_4_rbis" ]]
then
    echo -e "Option 4: \033[32mOK\033[0m"
    if [[ -e result/Test4.txt ]]
    then
        rm -f result/Test4.txt
    fi
else
    echo -e "Option 4: \033[31mKO\033[0m"
    echo -e "For 1 and 4:\nGot:\n$test_opt_4\n\nNeeded:\n$test_opt_4_r\n\n" > result/Test4.txt
    echo -e "For 1 and 29:\n Got:\n$test_opt_4bis\n\nNeeded:\n$test_opt_4" >> result/Test4.txt
fi

if [[ "$test_opt_5" == "$test_opt_5_r" ]]
then
    echo -e "Option 5: \033[32mOK\033[0m"
    if [[ -e result/Test5.txt ]]
    then
        rm -f result/Test5.txt
    fi
else
    echo -e "Option 5: \033[31mKO\033[0m"
    echo -e "Got:\n$test_opt_5\n\nNeeded:\n$test_opt_5_r" > result/Test5.txt
fi

if [[ "$test_opt_6" == "$test_opt_6_r" ]]
then
    echo -e "Option 6: \033[32mOK\033[0m"
    if [[ -e result/Test6.txt ]]
    then
        rm -f result/Test6.txt
    fi
else
    echo -e "Option 6: \033[31mKO\033[0m"
    echo -e "Got:\n$test_opt_6\n\nNeeded:\n$test_opt_6_r" > result/Test6.txt
fi
