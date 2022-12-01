#include <iostream>
#include <string>
#include <vector>
#include "helper/input_parse.hpp"


int solve_day1_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int current_elf_calories = 0;
    int max_calories = 0;

    for(int i=0; i<lines.size(); i++) {
        
        std::string line = lines[i];

        if(line == "") {
            if(current_elf_calories > max_calories) {
                max_calories = current_elf_calories;
            }

            current_elf_calories = 0;
        }
        else {
            int calories = std::stoi( line );
            current_elf_calories += calories;
        }
    }

    if(current_elf_calories > max_calories) {
        max_calories = current_elf_calories;
    }

    return max_calories;
}

int solve_day1_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int current_elf_calories = 0;
    const int top_elves_count = 3;
    int top_elves[top_elves_count];
    int smallest_index = 0;

    for (size_t i = 0; i < 3; i++) {
        top_elves[i] = 0;
    }

    for(int i=0; i<lines.size(); i++) {
        std::string line = lines[i];

        if(line == "") {
            if(current_elf_calories > top_elves[smallest_index]) {
                top_elves[smallest_index] = current_elf_calories;

                smallest_index = 0;
                int smallest_value = top_elves[0];
                for (size_t j = 1; j < top_elves_count; j++) {
                    if(top_elves[j] < smallest_value) {
                        smallest_value = top_elves[j];
                        smallest_index = j;
                    }
                }
            }
            
            current_elf_calories = 0;
        }
        else {
            int calories = std::stoi( line );
            current_elf_calories += calories;
        }
    }

    if(current_elf_calories > top_elves[smallest_index]) {
        top_elves[smallest_index] = current_elf_calories;

        smallest_index = 0;
        int smallest_value = top_elves[0];
        for (size_t j = 0; j < top_elves_count; j++) {
            if(top_elves[j] < smallest_value) {
                smallest_index = j;
            }
        }
    }

    int top_calories_sum = 0;
    for (size_t i = 0; i < top_elves_count; i++) {
        top_calories_sum += top_elves[i];
    }

    return top_calories_sum;
}