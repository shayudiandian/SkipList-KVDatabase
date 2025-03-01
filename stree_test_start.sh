#!/bin/bash
g++ -I./include ./test/stress_test.cpp -o ./bin/stress_test  --std=c++11 
./bin/stress_test