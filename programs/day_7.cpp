#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <string_view>
#include "helper/input_parse.hpp"
#include "helper/string_extra.hpp"
#include "helper/vector_extra.hpp"

const std::string dir_separator = "/";

std::string path_to_str(std::vector<std::string> path);

int solve_day7_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    std::vector<std::string> current_path;
    std::map<std::string, int> dirs;
    bool listing_dirs = false;

    for ( size_t i = 0; i < lines.size(); i++ ) {
        std::string line = lines[i];

        std::vector<std::string> spit_line;
        split(line, spit_line, ' ');

        if( spit_line[0] == "$" ) {
            // command
            std::string command = spit_line[1];
            listing_dirs = false;
            
            if( command == "cd" ) {
                // cd
                std::string cd_arg = spit_line[2];

                if( cd_arg == ".." ) {
                    current_path.pop_back();
                }
                else {
                    current_path.push_back( cd_arg );
                }

                std::string dir_path = path_to_str(current_path);
                if( !dirs.count(dir_path) ) {
                    dirs[dir_path] = 0;
                }
            }
            else if( command == "ls" ) {
                // ls, don't have to do anything
            }
        }
        else if( spit_line[0] == "dir" ) {
            // listing dir
            std::string dir_name = spit_line[1];
            std::string dir_path = path_to_str(current_path) + dir_name + dir_separator;

            if( !dirs.count(dir_path) ) {
                dirs[dir_path] = 0;
            }
        }
        else {
            // listing file
            int file_size = stoi( spit_line[0] );

            for (size_t j = current_path.size(); j > 0; j--) {
                std::vector<std::string> path_slice = slice(current_path, 0, j-1);
                dirs[path_to_str(path_slice)] += file_size;
            }
        }
    }

    int total_small_folder_size = 0;
    for (const auto & [key, value] : dirs) {
        if( value < 100000 ) {
            total_small_folder_size += value;
        }
    }

    return total_small_folder_size;
}

int solve_day7_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    std::vector<std::string> current_path;
    std::map<std::string, int> dirs;
    bool listing_dirs = false;

    for ( size_t i = 0; i < lines.size(); i++ ) {
        std::string line = lines[i];

        std::vector<std::string> spit_line;
        split(line, spit_line, ' ');

        if( spit_line[0] == "$" ) {
            // command
            std::string command = spit_line[1];
            listing_dirs = false;
            
            if( command == "cd" ) {
                // cd
                std::string cd_arg = spit_line[2];

                if( cd_arg == ".." ) {
                    current_path.pop_back();
                }
                else {
                    current_path.push_back( cd_arg );
                }

                std::string dir_path = path_to_str(current_path);
                if( !dirs.count(dir_path) ) {
                    dirs[dir_path] = 0;
                }
            }
            else if( command == "ls" ) {
                // ls, don't have to do anything
            }
        }
        else if( spit_line[0] == "dir" ) {
            // listing dir
            std::string dir_name = spit_line[1];
            std::string dir_path = path_to_str(current_path) + dir_name + dir_separator;

            if( !dirs.count(dir_path) ) {
                dirs[dir_path] = 0;
            }
        }
        else {
            // listing file
            int file_size = stoi( spit_line[0] );

            for (size_t j = current_path.size(); j > 0; j--) {
                std::vector<std::string> path_slice = slice(current_path, 0, j-1);
                dirs[path_to_str(path_slice)] += file_size;
            }
        }
    }

    int total_space = 70000000;
    int update_size = 30000000;
    int unused_space = 70000000 - dirs["/" + dir_separator];
    int minimum_to_delete = update_size - unused_space;

    int smallest_dir_big_enough = total_space;
    for (const auto & [key, value] : dirs) {
        if( value < smallest_dir_big_enough && value >= minimum_to_delete) {
            smallest_dir_big_enough = value;
        }
    }

    return smallest_dir_big_enough;
}

std::string path_to_str(std::vector<std::string> path) {
    std::string path_str = "";
    for (size_t i = 0; i < path.size(); i++) {
        path_str.append( path[i] + dir_separator);
    }
    return path_str;
}