#include <iostream>
#include <string>
#include <vector>
#include "helper/input_parse.hpp"

bool string_has_repeat(std::string s);

size_t solve_day6_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);
    std::string line = lines[0];
    std::string last_four = line.substr(0,4);

    size_t first_marker = 0;

    for (size_t index = 4; index < line.length() && first_marker == 0; index++) {
        if( string_has_repeat(last_four) ) {
            last_four.erase(0, 1);
            last_four.append(std::string(1, line.at(index)));
        }
        else {
            first_marker = index;
        }
       
    }

    return first_marker;
}

size_t solve_day6_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);
    std::string line = lines[0];
    std::string last_fourteen = line.substr(0,14);

    size_t first_marker = 0;

    for (size_t index = 14; index < line.length() && first_marker == 0; index++) {
        if( string_has_repeat(last_fourteen) ) {
            last_fourteen.erase(0, 1);
            last_fourteen.append(std::string(1, line.at(index)));
        }
        else {
            first_marker = index;
        }
       
    }

    return first_marker;
}

bool string_has_repeat(std::string s) {
    for (size_t i = 0; i < s.length()-1; i++) {
        for (size_t j = i+1; j < s.length(); j++) {
            if(s.at(i) == s.at(j)) {
                return true;
            }
        }
    }
    return false;
}