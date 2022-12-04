#include <iostream>
#include <string>
#include "programs/day_1.cpp"
#include "programs/day_2.cpp"
#include "programs/day_3.cpp"


int main() {
    std::string input_day1 = "inputs/input_1.txt";
    std::string input_day2 = "inputs/input_2.txt";
    std::string input_day3 = "inputs/input_3.txt";

    std::cout << "Day 1, star 1: " << solve_day1_1(input_day1) << std::endl;
    std::cout << "Day 1, star 2: " << solve_day1_2(input_day1) << std::endl << std::endl;

    std::cout << "Day 2, star 1: " << solve_day2_1(input_day2) << std::endl;
    std::cout << "Day 2, star 2: " << solve_day2_2(input_day2) << std::endl << std::endl;

    std::cout << "Day 3, star 1: " << solve_day3_1(input_day3) << std::endl;
    std::cout << "Day 3, star 2: " << solve_day3_2(input_day3) << std::endl;

    return 0;
}

