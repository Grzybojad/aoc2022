#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "helper/input_parse.hpp"
#include "helper/string_extra.hpp"


std::string solve_day5_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int conained_ranges = 0;
    bool finished_stacks = false;
    int stacks_lines_end = 0;

    std::vector< std::stack<char> > stacks;

    for (size_t i = 0; i < lines.size() && !finished_stacks; i++) {
        std::string line = lines[i];
        int current_stack = 0;
        
        for (size_t j = 1; j < line.length() && !finished_stacks; j += 4)
        {
            char c = line.at(j);

            if(c >= '1' && c <= '9') {
                finished_stacks = true;
                stacks_lines_end = i;
            }
            else if(c == ' ') {
                current_stack++;
            }
            else {
                // new crate
                while(stacks.size() < current_stack+1) {
                    std::stack<char> new_stack;
                    stacks.push_back(new_stack);
                }

                stacks[current_stack].push(line.at(j));
                current_stack++;
            }
        }
    }

    // reverse stacks
    for (size_t i = 0; i < stacks.size(); i++) {
        std::stack<char> reverse_stack;
        while(stacks[i].size() > 0) {
            reverse_stack.push(stacks[i].top());
            stacks[i].pop();
        }
        stacks[i] = reverse_stack;
    }

    for (size_t i = stacks_lines_end+2; i < lines.size(); i++)
    {
        std::string line = lines[i];
        std::vector<std::string> split_line;

        split( line, split_line, ' ' );

        int how_many = stoi(split_line[1]);
        int from = stoi(split_line[3])-1;
        int to = stoi(split_line[5])-1;

        // execute move
        for (size_t j = 0; j < how_many; j++)
        {
            char crate = stacks[from].top();
            stacks[from].pop();
            stacks[to].push(crate);
        }
    }

    std::string top_crates = "";

    for (size_t i = 0; i < stacks.size(); i++) {
        top_crates.append(std::string(1, stacks[i].top()));
    }

    return top_crates;
}

std::string solve_day5_2(std::string input_filename) {
     std::vector<std::string> lines = read_lines_string(input_filename);

    int conained_ranges = 0;
    bool finished_stacks = false;
    int stacks_lines_end = 0;

    std::vector< std::stack<char> > stacks;

    for (size_t i = 0; i < lines.size() && !finished_stacks; i++) {
        std::string line = lines[i];
        int current_stack = 0;
        
        for (size_t j = 1; j < line.length() && !finished_stacks; j += 4)
        {
            char c = line.at(j);

            if(c >= '1' && c <= '9') {
                finished_stacks = true;
                stacks_lines_end = i;
            }
            else if(c == ' ') {
                current_stack++;
            }
            else {
                // new crate
                while(stacks.size() < current_stack+1) {
                    std::stack<char> new_stack;
                    stacks.push_back(new_stack);
                }

                stacks[current_stack].push(line.at(j));
                current_stack++;
            }
        }
    }

    // reverse stacks
    for (size_t i = 0; i < stacks.size(); i++) {
        std::stack<char> reverse_stack;
        while(stacks[i].size() > 0) {
            reverse_stack.push(stacks[i].top());
            stacks[i].pop();
        }
        stacks[i] = reverse_stack;
    }

    for (size_t i = stacks_lines_end+2; i < lines.size(); i++)
    {
        std::string line = lines[i];
        std::vector<std::string> split_line;

        split( line, split_line, ' ' );

        int how_many = stoi(split_line[1]);
        int from = stoi(split_line[3])-1;
        int to = stoi(split_line[5])-1;

        // execute move
        std::stack<char> to_move;
        for (size_t j = 0; j < how_many; j++)
        {
            char crate = stacks[from].top();
            stacks[from].pop();
            to_move.push(crate);
        }
        for (size_t j = 0; j < how_many; j++)
        {
            stacks[to].push(to_move.top());
            to_move.pop();
        }
    }

    std::string top_crates = "";

    for (size_t i = 0; i < stacks.size(); i++) {
        top_crates.append(std::string(1, stacks[i].top()));
    }

    return top_crates;
}