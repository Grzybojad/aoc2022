#include <iostream>
#include <string>
#include "programs/day_1.cpp"


int main() {
    std::string input_day1 = "inputs/input_1.txt";

    std::cout << "Day 1, star 1: " << solve_day1_1(input_day1) << std::endl;
    std::cout << "Day 1, star 2: " << solve_day1_2(input_day1) << std::endl;

    return 0;
}

