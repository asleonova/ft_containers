#! /bin/sh

RED="\x1b[31m"
GREEN="\x1b[32m"
ENDCOLOR="\e[0m"


rm logs/user.output
rm logs/std.output
rm -rf logs
mkdir logs

clang++ -Wall -Wextra -Werror ft_list_test.cpp -o logs/ft_list && 
./logs/ft_list > logs/user.output
echo "${GREEN}ft_tests successfully complied! Log file has been created.${ENDCOLOR}"
cp ft_list_test.cpp std_list_test.cpp
sed 's/ft::list/std::list/g' std_list_test.cpp > output.file; mv output.file std_list_test.cpp
clang++ -Wall -Wextra -Werror std_list_test.cpp -o logs/std_list &&
./logs/std_list > logs/std.output
echo "${GREEN}std_tests successfully complied! Log file has been created.${ENDCOLOR}"
diff logs/user.output logs/std.output > diff.txt

if [[ -z $(grep '[^[:space:]]' diff.txt) ]]
then
   echo "${GREEN}No differences found. Good job!${ENDCOLOR}"
else
   echo "${RED}Poor you, some std funcs are not identical to yours, here is the diff: ${ENDCOLOR}"
   cat diff.txt
fi