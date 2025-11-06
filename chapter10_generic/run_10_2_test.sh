#!/bin/zsh
# compile and run test for 10.2.cpp
cd "$(dirname "$0")"

# compile with C++11
g++ -std=c++11 -Wall 10.2.cpp -o 10.2
if [ $? -ne 0 ]; then
  echo "Compile failed"
  exit 1
fi

echo "Input file: test_input.txt"
echo "Searching: apple"
echo "---- Program output ----"
# feed the search word via stdin
echo "apple" | ./10.2 test_input.txt
echo "---- Done ----"
