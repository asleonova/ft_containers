#! /bin/zsh
rm logs/user.output
  rm logs/std.output
  rm -rf logs
  mkdir logs

  
  clang++ -Wall -Wextra -Werror ft_list_test.cpp -o logs/ft_list &&
  ./logs/ft_list > logs/user.output
  echo "ft_tests successfully complied! Log file has been created."
  cp ft_list_test.cpp std.cpp
  sed -i 's/ft::list/std::list/g' std.cpp
  clang++ -Wall -Wextra -Werror std.cpp -o logs/std_list &&
  ./logs/std_list > logs/std.output
  echo "std_tests successfully complied! Log file has been created."
  diff logs/user.output logs/std.output > diff.txt

  if [[ -z $(grep '[^[:space:]]' diff.txt) ]]
  then
    echo "No differences found. Good job!"
  else
    echo "Poor you, some std funcs are not identical to yours, here is the diff: "
    cat diff.txt
  fi