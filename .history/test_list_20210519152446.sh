#! /bin/sh
RED="\x1b[31m"
GREEN="\x1b[32m"
ENDCOLOR="\x1b[0m"

if [ -d "logs" ]; then rm -fr logs; fi
mkdir logs

clang++ -Wall -Wextra -Werror ft_list_test.cpp -o logs/ft_list && 
./logs/ft_list > logs/user.output
echo -e "${GREEN}ft_tests successfully complied! Log file has been created.${ENDCOLOR}"
echo " "
cp ft_list_test.cpp std_list_test.cpp
sed 's/ft::list/std::list/g' std_list_test.cpp > output.file; mv output.file std_list_test.cpp
clang++ -Wall -Wextra -Werror std_list_test.cpp -o logs/std_list &&
./logs/std_list > logs/std.output
echo -e "${GREEN}std_tests successfully complied! Log file has been created.${ENDCOLOR}"
echo " "
diff logs/user.output logs/std.output > diff.txt

if [[ -z $(grep '[^[:space:]]' diff.txt) ]]
then
   echo -e "${GREEN}No differences found. Good job!${ENDCOLOR}"
   echo " "
else
   echo -e "${RED}Poor you, some std funcs are not identical to yours, here is the diff: ${ENDCOLOR}"
   echo " "
   cat diff.txt
fi
rm std_list_test.cpp