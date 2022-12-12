#include <iostream>
#include <string>
#include <vector>
#include "helper/input_parse.hpp"


int solve_day12_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    int g_height = lines.size();
    int g_width = lines[0].length();
    int graph[g_width][g_height];

    for (size_t y = 0; y < g_height; y++) {
        for (size_t x = 0; x < g_width; x++) {
            char c = lines[y].at(x);
            int elevation;
            if( c == 'S' ) {
                elevation = 0;
            } else if( c== 'E' ) {
                elevation = 'z' - 'a';
            } else {
                elevation = c - 'a';
            }
            graph[x][y] = elevation;
        }   
    }
    
    // Djikstra
    int dist[g_width][g_height];
    bool visited[g_width][g_height];
    for (size_t y = 0; y < g_height; y++) {
        for (size_t x = 0; x < g_width; x++) {
            graph[x][y] = INT32_MAX;
        }   
    }
    dist[0][0] = 0;
    visited[0][0] = true;
    bool finished = false;
    int x, y = 0;

    while( !finished ) {
        // right
        if( x < g_width-1 ) {
            if( dist[x+1][y] > graph[x+1][y] + dist[x][y] && !visited[x+1][y] ) {
                dist[x+1][y] = graph[x+1][y] + dist[x][y];
            }
        }
        // left
        if( x > 0 ) {
            if( dist[x-1][y] > graph[x-1][y] + dist[x][y] && !visited[x-1][y] ) {
                dist[x-1][y] = graph[x-1][y] + dist[x][y];
            }
        }
        // up
        if( y < g_height-1 ) {
            if( dist[x][y+1] > graph[x][y+1] + dist[x][y] && !visited[x][y+1] ) {
                dist[x][y+1] = graph[x][y+1] + dist[x][y];
            }
        }
        // down
        if( y > 0 ) {
            if( dist[x][y-1] > graph[x][y-1] + dist[x][y] && !visited[x][y-1] ) {
                dist[x][y-1] = graph[x][y-1] + dist[x][y];
            }
        }

        visited[x][y] = true;
    }
    

    return 0;
}

int solve_day12_2(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
    }

    return 0;
}

