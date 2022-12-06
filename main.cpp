#include <iostream>
#include <string>
#include "programs/day_1.cpp"
#include "programs/day_2.cpp"
#include "programs/day_3.cpp"
#include "programs/day_4.cpp"
#include "programs/day_5.cpp"
#include "programs/day_6.cpp"


int main() {
    std::string input_day1 = "inputs/input_1.txt";
    std::string input_day2 = "inputs/input_2.txt";
    std::string input_day3 = "inputs/input_3.txt";
    std::string input_day4 = "inputs/input_4.txt";
    std::string input_day5 = "inputs/input_5.txt";
    std::string input_day6 = "inputs/input_6.txt";

    std::cout << "Day 1, star 1: " << solve_day1_1(input_day1) << std::endl;
    std::cout << "Day 1, star 2: " << solve_day1_2(input_day1) << std::endl << std::endl;

    std::cout << "Day 2, star 1: " << solve_day2_1(input_day2) << std::endl;
    std::cout << "Day 2, star 2: " << solve_day2_2(input_day2) << std::endl << std::endl;

    std::cout << "Day 3, star 1: " << solve_day3_1(input_day3) << std::endl;
    std::cout << "Day 3, star 2: " << solve_day3_2(input_day3) << std::endl << std::endl;

    std::cout << "Day 4, star 1: " << solve_day4_1(input_day4) << std::endl;
    std::cout << "Day 4, star 2: " << solve_day4_2(input_day4) << std::endl << std::endl;

    std::cout << "Day 5, star 1: " << solve_day5_1(input_day5) << std::endl;
    std::cout << "Day 5, star 2: " << solve_day5_2(input_day5) << std::endl << std::endl;

    std::cout << "Day 6, star 1: " << solve_day6_1(input_day6) << std::endl;
    std::cout << "Day 6, star 2: " << solve_day6_2(input_day6) << std::endl << std::endl;

    return 0;
}

