#! /bin/zsh
mkdir logs

  clang++ -Wall -Wextra -Werror -fsanitize=address main.cpp -o logs/user_bin &&
  ./logs/user_bin > logs/user.output
  echo "ft_tests successfully complied! Log file has been created."
  clang++ -Wall -Wextra -Werror -fsanitize=address main_std.cpp -o logs/bin &&
  ./logs/bin > logs/std.output
  echo "std_tests successfully complied! Log file has been created."
  diff logs/user.output logs/std.output