#! /bin/sh

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_map.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 14:16:25 by dbliss            #+#    #+#              #
#    Updated: 2021/06/07 14:16:33 by dbliss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED="\x1b[31m"
GREEN="\x1b[32m"
ENDCOLOR="\x1b[0m"

if [ -d "logs" ]; then rm -fr logs; fi
mkdir logs

clang++ ft_map_test.cpp -o logs/ft_map && 
./logs/ft_map > logs/user.output
echo -e "${GREEN}ft_tests successfully complied! Log file has been created.${ENDCOLOR}\n"
cp ft_map_test.cpp std_map_test.cpp
sed 's/ft::map/std::map/g' std_map_test.cpp > output.file; mv output.file std_map_test.cpp
clang++ -Wall -Wextra -Werror std_map_test.cpp -o logs/std_map &&
./logs/std_map > logs/std.output
echo -e "${GREEN}std_tests successfully complied! Log file has been created.${ENDCOLOR}\n"
diff logs/user.output logs/std.output > diff.txt

if [[ -z $(grep '[^[:space:]]' diff.txt) ]]
then
   echo -e "${GREEN}No differences found. Good job!${ENDCOLOR}\n"
else
   echo -e "${RED}Poor you, some std funcs are not identical to yours, here is the diff: ${ENDCOLOR}\n"
   cat diff.txt
fi
rm std_map_test.cpp