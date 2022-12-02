#include <iostream>
#include <string>
#include <vector>
#include "helper/input_parse.hpp"


int solve_day2_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int points = 0;

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];

        char move_opponent = line.at(0);
        char move_me = line.at(2)-('Y'-'A'-1);

        if(move_opponent==move_me) {
            // draw
            points += 3;
        }
        else {
            if( (move_opponent=='A' && move_me == 'B') ||
                (move_opponent=='B' && move_me == 'C') ||
                (move_opponent=='C' && move_me == 'A')
            ) {
                // win
                points += 6;
            }
            // else lose
        }

        points += (move_me - 'A' + 1);
    }
    
    return points;
}

int solve_day2_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int points = 0;

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];

        char move_opponent = line.at(0);
        char result = line.at(2);
        char move_me;

        if(result=='Y') {
            // draw
            points += 3;
            move_me = move_opponent;
        }
        else if(result=='Z') {
            // win
            points += 6;

            switch (move_opponent)
            {
            case 'A':
                move_me = 'B';
                break;
            case 'B':
                move_me = 'C';
                break;
            case 'C':
                move_me = 'A';
                break;
            default:
                break;
            }
        }
        else {
            // lose
            switch (move_opponent)
            {
            case 'B':
                move_me = 'A';
                break;
            case 'C':
                move_me = 'B';
                break;
            case 'A':
                move_me = 'C';
                break;
            default:
                break;
            }
        }

        points += (move_me - 'A' + 1);
    }
    
    return points;
}