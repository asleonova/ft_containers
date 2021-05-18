#! /bin/zsh
mkdir logs

  clang++ -Wall -Wextra -Werror ft_list_test.cpp -o logs/ft_list &&
  ./logs/ft_list > logs/user.output
  echo "ft_tests successfully complied! Log file has been created."
  cp ft_list_test.cpp std_list_test.cpp
  clang++ -Wall -Wextra -Werror main_std.cpp -o logs/std_list &&
  ./logs/std_list > logs/std.output
  echo "std_tests successfully complied! Log file has been created."
  diff logs/user.output logs/std.output