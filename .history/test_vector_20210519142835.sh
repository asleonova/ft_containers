#! /bin/sh
RED="\x1b[31m"
GREEN="\x1b[32m"
ENDCOLOR="\x1b[0m"

rm logs/user.output
rm logs/std.output
rm -rf logs
mkdir logs

clang++ -Wall -Wextra -Werror ft_vector_test.cpp -o logs/ft_vector && 
./logs/ft_vector > logs/user.output
echo -e "${GREEN}ft_tests successfully complied! Log file has been created.${ENDCOLOR}"
cp ft_vector_test.cpp std_vector_test.cpp
sed 's/ft::vector/std::vector/g' std_vector_test.cpp > output.file; mv output.file std_vector_test.cpp
clang++ -Wall -Wextra -Werror std_vector_test.cpp -o logs/std_vector &&
./logs/std_vector > logs/std.output
echo -e "${GREEN}std_tests successfully complied! Log file has been created.${ENDCOLOR}"
diff logs/user.output logs/std.output > diff.txt

if [[ -z $(grep '[^[:space:]]' diff.txt) ]]
then
   echo -e "${GREEN}No differences found. Good job!${ENDCOLOR}"
else
   echo -e "${RED}Poor you, some std funcs are not identical to yours, here is the diff: ${ENDCOLOR}"
   cat diff.txt
fi
rm std_vector_test.cpp