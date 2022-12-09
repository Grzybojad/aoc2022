#include <iostream>
#include <string>
#include <vector>
#include "helper/input_parse.hpp"
#include "helper/vector_extra.hpp"

struct pos {
    int x;
    int y;

    bool operator==(const pos& a) const {
        return (x == a.x && y == a.y);
    }
};

int distance( pos p1, pos p2 );

int solve_day9_1(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    pos head, tail;
    head.x = head.y = tail.x = tail.y = 0;

    std::vector<pos> tail_visited;
    tail_visited.push_back(tail);

    for (size_t i = 0; i < lines.size(); i++) {
        std::string line = lines[i];

        char dir = line.at(0);
        int head_move_dist = line.at(2) - '0';

        for (size_t move = 0; move < head_move_dist; move++) {
            // move head
            switch( dir ) {
                case 'U':
                    head.y++;
                    break;
                case 'D':
                    head.y--;
                    break;
                case 'L':
                    head.x--;
                    break;
                case 'R':
                    head.x++;
                    break;
            }

            if( ( distance(head, tail) > 1 ) ) {
                // move tail
                if (head.x == tail.x) {
                    if (head.y > tail.y) {
                        tail.y++;
                    } else {
                        tail.y--;
                    }
                } 
                else if (head.y == tail.y) {
                    if (head.x > tail.x) {
                        tail.x++;
                    } else {
                        tail.x--;
                    }
                } 
                else {
                    if ( head.x > tail.x ) {
                        if (head.y > tail.y) {
                            tail.x++;
                            tail.y++;
                        } else {
                            tail.x++;
                            tail.y--;
                        }
                    } 
                    else {
                        if (head.y > tail.y) {
                            tail.x--;
                            tail.y++;
                        } else {
                            tail.x--;
                            tail.y--;
                        }
                    }
                }
            }

            if( !contains( tail_visited, tail ) ) {
                tail_visited.push_back( tail );
            }
        }
    }

    // for (size_t i = 0; i < tail_visited.size(); i++) {
    //     std::cout << "(" << tail_visited[i].x << ", " << tail_visited[i].y << ")\n";
    // }

    return tail_visited.size();
}

int distance( pos p1, pos p2 ) {
    if( abs( p1.x - p2.x ) > abs( p1.y - p2.y ) ) {
        return abs( p1.x - p2.x );
    }
    return abs( p1.y - p2.y );
}