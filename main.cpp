#include <iostream>
#include <string>
#include "programs/day_1.cpp"
#include "programs/day_2.cpp"
#include "programs/day_3.cpp"
#include "programs/day_4.cpp"
#include "programs/day_5.cpp"
#include "programs/day_6.cpp"
#include "programs/day_7.cpp"
#include "programs/day_8.cpp"
#include "programs/day_9.cpp"
#include "programs/day_10.cpp"


int main() {
    std::string input_day1 = "inputs/input_1.txt";
    std::string input_day2 = "inputs/input_2.txt";
    std::string input_day3 = "inputs/input_3.txt";
    std::string input_day4 = "inputs/input_4.txt";
    std::string input_day5 = "inputs/input_5.txt";
    std::string input_day6 = "inputs/input_6.txt";
    std::string input_day7 = "inputs/input_7.txt";
    std::string input_day8 = "inputs/input_8.txt";
    std::string input_day9 = "inputs/input_9.txt";
    std::string input_day10 = "inputs/input_10.txt";

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

    std::cout << "Day 7, star 1: " << solve_day7_1(input_day7) << std::endl;
    std::cout << "Day 7, star 2: " << solve_day7_2(input_day7) << std::endl << std::endl;

    std::cout << "Day 8, star 1: " << solve_day8_1(input_day8) << std::endl;
    std::cout << "Day 8, star 2: " << solve_day8_2(input_day8) << std::endl << std::endl;

    std::cout << "Day 9, star 1: " << solve_day9_1(input_day9) << std::endl;
    std::cout << "Day 9, star 2: " << solve_day9_2(input_day9) << std::endl << std::endl;

    std::cout << "Day 10, star 1: " << solve_day10_1(input_day10) << std::endl;
    std::cout << "Day 10, star 2: " << solve_day10_2(input_day10) << std::endl << std::endl;


    return 0;
}

