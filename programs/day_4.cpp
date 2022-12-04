#include <iostream>
#include <string>
#include <vector>
#include "helper/input_parse.hpp"


int solve_day4_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    std::string pair_delimiter = ",";
    std::string range_delimeter = "-";
    int conained_ranges = 0;

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        std::string pair[2];        

        pair[0] = line.substr(0, line.find(pair_delimiter));
        pair[1] = line.substr(line.find(pair_delimiter)+1, line.length());

        int ranges[2][2];

        for (size_t j = 0; j < 2; j++) {
            int delimeter_pos = pair[j].find(range_delimeter);
            ranges[j][0] = stoi(pair[j].substr(0, delimeter_pos));
            ranges[j][1] = stoi(pair[j].substr(delimeter_pos+1, pair[j].length()-delimeter_pos));
        }
        
        if((ranges[0][0] >= ranges[1][0] && ranges[0][1] <= ranges[1][1]) ||
           (ranges[1][0] >= ranges[0][0] && ranges[1][1] <= ranges[0][1])) {
            conained_ranges++;
        }
    }
    return conained_ranges;
}

int solve_day4_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    std::string pair_delimiter = ",";
    std::string range_delimeter = "-";
    int conained_ranges = 0;

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        std::string pair[2];        

        pair[0] = line.substr(0, line.find(pair_delimiter));
        pair[1] = line.substr(line.find(pair_delimiter)+1, line.length());

        int ranges[2][2];

        for (size_t j = 0; j < 2; j++) {
            int delimeter_pos = pair[j].find(range_delimeter);
            ranges[j][0] = stoi(pair[j].substr(0, delimeter_pos));
            ranges[j][1] = stoi(pair[j].substr(delimeter_pos+1, pair[j].length()-delimeter_pos));
        }
        
        if((ranges[0][0] <= ranges[1][0] && ranges[0][1] >= ranges[1][0]) ||
           (ranges[0][0] <= ranges[1][1] && ranges[0][1] >= ranges[1][1]) ||
           (ranges[1][0] <= ranges[0][0] && ranges[1][1] >= ranges[0][0]) ||
           (ranges[1][0] <= ranges[0][1] && ranges[1][1] >= ranges[0][1])) {
            conained_ranges++;
        }
    }
    return conained_ranges;
}