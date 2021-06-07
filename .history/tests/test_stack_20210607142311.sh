#! /bin/sh

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_stack.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 14:22:58 by dbliss            #+#    #+#              #
#    Updated: 2021/06/07 14:22:58 by dbliss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RED="\x1b[31m"
GREEN="\x1b[32m"
ENDCOLOR="\x1b[0m"

if [ -d "logs" ]; then rm -fr logs; fi
mkdir logs

clang++ -Wall -Wextra -Werror ft_stack_test.cpp -o logs/ft_stack && 
./logs/ft_stack > logs/user.output
echo -e "${GREEN}ft_tests successfully complied! Log file has been created.${ENDCOLOR}\n"
cp ft_stack_test.cpp std_stack_test.cpp
sed 's/ft::stack/std::stack/g' std_stack_test.cpp > output.file; mv output.file std_stack_test.cpp
clang++ -Wall -Wextra -Werror std_stack_test.cpp -o logs/std_stack &&
./logs/std_stack > logs/std.output
echo -e "${GREEN}std_tests successfully complied! Log file has been created.${ENDCOLOR}\n"
diff logs/user.output logs/std.output > diff.txt

if [[ -z $(grep '[^[:space:]]' diff.txt) ]]
then
   echo -e "${GREEN}No differences found. Good job!${ENDCOLOR}\n"
else
   echo -e "${RED}Poor you, some std funcs are not identical to yours, here is the diff: ${ENDCOLOR}\n"
   cat diff.txt
fi
rm std_stack_test.cpp