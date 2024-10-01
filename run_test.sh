#!/bin/bash

printf '\33c\e[3J'


for file in tests/outs/*; do
  if [ -x "$file" ]; then
    echo "Running $file"
    if [[ "$OSTYPE" == "darwin"* ]]; then
      leaks -groupByType -list -atExit  -- ./"$file"
    else
      valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --trace-children=yes --track-origins=yes --leak-resolution=high ./"$file"
    fi
    printf "\n\n\n\n"
  fi
done
