#include <iostream>
#include <string>
#include <vector>
#include "helper/input_parse.hpp"

int char_to_priority(char a);

int solve_day3_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int priorities_sum = 0;
    char common_item = '0';

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];

        std::string first_compartment = line.substr(0, line.length()/2);

        for (size_t j = line.length()/2; j < line.length(); j++) {
            if(first_compartment.find(line[j]) != std::string::npos) {
                common_item = line[j];
            }
        }

        int item_priority = char_to_priority(common_item);
        priorities_sum += item_priority;
    }
    
    return priorities_sum;
}

int solve_day3_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int priorities_sum = 0;

    for (size_t i = 0; i < lines.size(); i+=3) {
        std::string line = lines[i];
        int seen_before[line.length()];
        for (size_t j = 0; j < line.length(); j++) {
            seen_before[j] = 0;
        }
        
        for (size_t j = i+1; j < i+3; j++) {
            std::string other_line = lines[j];

            for (size_t k = 0; k < line.length(); k++) {
                if(other_line.find(line[k]) != std::string::npos) {
                    seen_before[k] += 1;
                }
            }
        }

        for (size_t j = 0; j < line.length(); j++) {
            if(seen_before[j] == 2 ) {
                priorities_sum += char_to_priority(line[j]);
                break;
            }
        }
    }
    
    return priorities_sum;
}

int char_to_priority(char a) {
    bool uppercasecase = a >= 'A' && a <= 'Z';

    if(uppercasecase) {
        return a - 'A' + 27;
    }
    else {
        return a - 'a' + 1;
    }
}