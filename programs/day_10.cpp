#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "helper/input_parse.hpp"
#include "helper/string_extra.hpp"

void write_pixel( int pc, int X );
bool should_light_up_pixel( int pc, int X );

int solve_day10_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int pc = 0;
    int X = 1;
    std::map<int, int> signal;

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];

        std::vector<std::string > split_line;
        split(line,split_line,  ' ');

        pc++;
        signal[pc] = pc * X;

        if(split_line[0] == "addx") {
            pc++;
            signal[pc] = pc * X;

            X += stoi(split_line[1]);
        }
    }

    pc++;
    signal[pc] = pc * X;

    // 20th, 60th, 100th, 140th, 180th, and 220th cycles
    return signal[20] + signal[60] + signal[100] + signal[140] + signal[180] + signal[220];
}

int solve_day10_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int pc = 0;
    int X = 1;
    std::map<int, int> signal;

    std::cout << std::endl;

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];

        std::vector<std::string > split_line;
        split(line,split_line,  ' ');

        write_pixel( pc, X );
        pc++;

        if(split_line[0] == "addx") {
            write_pixel( pc, X );
            pc++;

            X += stoi(split_line[1]);
        }
    }

    write_pixel( pc, X );
    pc++;

    return 0;
}

void write_pixel( int pc, int X ) {
    if( should_light_up_pixel(pc, X ) ) {
        std::cout << "#";
    }
    else {
        std::cout << " ";
    }

    if( pc % 40 == 0 ) {
        std::cout << std::endl;
    }
}

bool should_light_up_pixel( int pc, int X ) {
    int writing_x = pc % 40;
    return ( X - 1 <= writing_x && X + 1 >= writing_x );
}