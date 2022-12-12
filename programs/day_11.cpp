#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "helper/input_parse.hpp"
#include "helper/string_extra.hpp"
#include "helper/vector_extra.hpp"

class monkey {
    public:
        int index;
        std::vector<long> items;

        bool multiply;
        bool old_operand;
        int operand;

        int div_test;
        int true_index;
        int false_index;

        long inspect_count = 0;
};

std::vector<monkey> load_monkeys(std::string input_filename);

int solve_day11_1(std::string input_filename) {
    std::vector<monkey> monkeys = load_monkeys(input_filename);

    int round = 1;

    for (size_t round_i = 0; round_i < 20; round_i++) {
        for (size_t monkey_i = 0; monkey_i < monkeys.size(); monkey_i++) {
            monkey m = monkeys[monkey_i];
            // std::cout << "Monkey " << m.index << " items: " << m.items.size() << std::endl;

            while( !m.items.empty() ) {
                // std::cout << "Monkey " << m.index << " items before: " << m.items.size() << std::endl;

                long worry = m.items[m.items.size()-1];
                m.items.pop_back();
                // std::cout << "Monkey " << m.index << " items after: " << m.items.size() << std::endl;

                if( m.multiply ) {
                    if( m.old_operand ) {
                        worry *= worry;
                    } else {
                        worry *= m.operand;
                    }
                } else {
                    if( m.old_operand ) {
                        worry += worry;
                    } else {
                        worry += m.operand;
                    }
                }

                worry /= 3;
                m.inspect_count++;

                if( worry % m.div_test == 0 ) {
                    monkeys[m.true_index].items.push_back( worry );
                } else {
                    monkeys[m.false_index].items.push_back( worry );
                }
            }

            monkeys[monkey_i] = m;
        }
    }

    std::vector<long> inspections;

    for (size_t i = 0; i < monkeys.size(); i++) {
        inspections.push_back( monkeys[i].inspect_count );
    }
    std::sort(inspections.begin(), inspections.end(), std::greater<long>());

    return inspections[0] * inspections[1];
}

long solve_day11_2(std::string input_filename) {
    std::vector<monkey> monkeys = load_monkeys(input_filename);

    int round = 1;
    long common_multiplier = 1;
    for (size_t i = 0; i < monkeys.size(); i++) {
        common_multiplier *= monkeys[i].div_test;
    }    

    for (size_t round_i = 0; round_i < 10000; round_i++) {
        for (size_t monkey_i = 0; monkey_i < monkeys.size(); monkey_i++) {
            monkey m = monkeys[monkey_i];

            while( !m.items.empty() ) {

                long worry = m.items[m.items.size()-1];
                m.items.pop_back();

                if( m.multiply ) {
                    if( m.old_operand ) {
                        worry *= worry;
                    } else {
                        worry *= m.operand;
                    }
                } else {
                    if( m.old_operand ) {
                        worry += worry;
                    } else {
                        worry += m.operand;
                    }
                }

                m.inspect_count++;

                if( worry % m.div_test == 0 ) {
                    monkeys[m.true_index].items.push_back( worry % common_multiplier );
                } else {
                    monkeys[m.false_index].items.push_back( worry % common_multiplier );
                }
            }

            monkeys[monkey_i] = m;
        }
    }

    std::vector<long> inspections;
    for (size_t i = 0; i < monkeys.size(); i++) {
        inspections.push_back( monkeys[i].inspect_count );
    }
    std::sort(inspections.begin(), inspections.end(), std::greater<long>());

    return inspections[0] * inspections[1];
}

std::vector<monkey> load_monkeys(std::string input_filename) {
    std::vector<std::string> lines = read_lines_string(input_filename);

    std::vector<monkey> monkeys;

    for (size_t i = 0; i < lines.size(); i += 7) {
        monkey new_monkey;
        new_monkey.index = i / 7;

        // items
        std::string items_line = lines[i+1];
        items_line = items_line.substr(18);
        std::vector<std::string> split_items;
        split(items_line, split_items, ',');
        std::vector<long> items;
        for( int j = split_items.size()-1; j >= 0; j-- ) {
            items.push_back( stoi(split_items[j]) );
        }
        new_monkey.items = items;

        // operation
        std::string operation_line = lines[i+2];
        operation_line = operation_line.substr(23);
        std::vector<std::string> split_operation;
        split(operation_line, split_operation, ' ');
        new_monkey.multiply = split_operation[0] == "*";
        new_monkey.old_operand = split_operation[1] == "old";
        if( !new_monkey.old_operand ) {
            new_monkey.operand = stoi(split_operation[1]);
        }

        // test
        std::string test_line = lines[i+3];
        test_line = test_line.substr(21);
        new_monkey.div_test = stoi(test_line);
        std::string test_true_line = lines[i+4];
        test_true_line = test_true_line.substr(29);
        new_monkey.true_index = stoi(test_true_line);
        std::string test_false_line = lines[i+5];
        test_false_line = test_false_line.substr(30);
        new_monkey.false_index = stoi(test_false_line);

        monkeys.push_back( new_monkey );
    }

    return monkeys;
}