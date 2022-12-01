#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> read_lines_int(std::string filename) {
    std::vector<int> lines;

     std::ifstream istrm(filename);

    if(!istrm.is_open()) {
        std::cout << "Failed to open " << filename << '\n';
    }
    else {
        int n;
        while (istrm >> n) {
            lines.push_back(n);
        }
    }

    return lines;
}

std::vector<std::string> read_lines_string(std::string filename) {
    std::vector<std::string> lines;

     std::ifstream istrm(filename);

    if(!istrm.is_open()) {
        std::cout << "Failed to open " << filename << '\n';
    }
    else {
        std::string n;
        while (std::getline(istrm, n)) {
            lines.push_back(n);
        }
    }

    return lines;
}

