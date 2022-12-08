#include <iostream>
#include <string>
#include <vector>
#include "helper/input_parse.hpp"

bool is_tree_visible( int **grid, int tree_x, int tree_y, int w, int h );
int scenic_score( int **grid, int tree_x, int tree_y, int w, int h );

int solve_day8_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    // init grid
    int grid_width = lines[0].size();
    int grid_height = lines.size();
    int** grid = new int*[grid_height];                
    for(int i=0; i<grid_height; i++) {
        grid[i] = new int[grid_width];
    }

    // fill grid
    for (size_t y = 0; y < grid_height; y++) {
        for (size_t x = 0; x < grid_width; x++) {
            grid[x][y] = stoi(std::string(1, lines[y].at(x)));
        }
    }
    
    int visible_trees = 0;

    for (size_t y = 0; y < grid_height; y++) {
        for (size_t x = 0; x < grid_width; x++) {
            if( is_tree_visible( grid, x, y, grid_width, grid_height ) ) {
                visible_trees++;
            }
        }
    }

    return visible_trees;
}

int solve_day8_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    // init grid
    int grid_width = lines[0].size();
    int grid_height = lines.size();
    int** grid = new int*[grid_height];                
    for(int i=0; i<grid_height; i++) {
        grid[i] = new int[grid_width];
    }

    // fill grid
    for (size_t y = 0; y < grid_height; y++) {
        for (size_t x = 0; x < grid_width; x++) {
            grid[x][y] = stoi(std::string(1, lines[y].at(x)));
        }
    }
    
    int top_score = 0;

    for (size_t y = 0; y < grid_height; y++) {
        for (size_t x = 0; x < grid_width; x++) {
            int score = scenic_score( grid, x, y, grid_width, grid_height );

            if( score > top_score ) {
                top_score = score;
            }
        }
    }

    return top_score;
}

bool is_tree_visible( int **grid, int tree_x, int tree_y, int w, int h ) {
    if( tree_x == 0 || tree_y == 0 || tree_x == w-1 || tree_y == h-1 ) {
        return true;
    }

    // check above
    bool visible = true;
    for (size_t y = 0; y < tree_y; y++) {
        if( grid[tree_x][y] >= grid[tree_x][tree_y] ) {
            visible = false;
        }
    }
    if( visible ) {
        return true;
    }

    // check below
    visible = true;
    for (size_t y = tree_y+1; y < h; y++) {
        if( grid[tree_x][y] >= grid[tree_x][tree_y] ) {
            visible = false;
        }
    }
    if( visible ) {
        return true;
    }

    // check left
    visible = true;
    for (size_t x = 0; x < tree_x; x++) {
        if( grid[x][tree_y] >= grid[tree_x][tree_y] ) {
            visible = false;
        }
    }
    if( visible ) {
        return true;
    }

    // check right
    visible = true;
    for (size_t x = tree_x+1; x < w; x++) {
        if( grid[x][tree_y] >= grid[tree_x][tree_y] ) {
            visible = false;
        }
    }
    return visible;
}


int scenic_score( int **grid, int tree_x, int tree_y, int w, int h ) {
    if( tree_x == 0 || tree_y == 0 || tree_x == w-1 || tree_y == h-1 ) {
        return 0;
    }

    int score = 0;

    // check above
    int total_in_dir = 0;
    for (int y = tree_y-1; y >= 0; y--) {
        total_in_dir++;
        if( grid[tree_x][y] >= grid[tree_x][tree_y] ) {
            break;
        }
    }
    score = total_in_dir;

    // check below
    total_in_dir = 0;
    for (int y = tree_y+1; y < h; y++) {
        total_in_dir++;
        if( grid[tree_x][y] >= grid[tree_x][tree_y] ) {
            break;
        }
    }
    score *= total_in_dir;

    // check left
    total_in_dir = 0;
    for (int x = tree_x-1; x >= 0; x--) {
        total_in_dir++;
        if( grid[x][tree_y] >= grid[tree_x][tree_y] ) {
            break;
        }
    }
    score *= total_in_dir;
    

    // check right
    total_in_dir = 0;
    for (int x = tree_x+1; x < w; x++) {
        total_in_dir++;
        if( grid[x][tree_y] >= grid[tree_x][tree_y] ) {
            break;
        }
    }
    score *= total_in_dir;

    return score;
}