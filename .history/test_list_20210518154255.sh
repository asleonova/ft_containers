#! /bin/zsh

rm logs/ft_test.output
rm logs/std_test_output
rm -rf logs
mkdir logs

  clang++ -Wall -Wextra -Werror -fsanitize=address ft_vector_test.cpp -o logs/user_bin &&
  ./logs/user_bin > logs/user.output
  echo "ft_tests successfully complied! Log file has been created."
  clang++ -Wall -Wextra -Werror -fsanitize=address std_vector_test.cpp -o logs/bin &&
  ./logs/bin > logs/std.output
  echo "std_tests successfully complied! Log file has been created."
  diff logs/user.output logs/std.output