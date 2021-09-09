#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>


void say_my_name();

int choose_cycle();

void write_numbers();

inline void keep_window_open() { char ch; std::cin >> ch; }

void error(std::string s) {
    throw std::runtime_error(s);
}

void error(std::string s1, std::string s2) {
    throw std::runtime_error(s1 + " " + s2);
}

//Test throw
class out_of_bad {};

void say_my_name()
{
    std::cout << "Say my name!\n";
    std::string first_name;
    std::cin >> first_name;
    std::cout << "Bubaleh " << first_name << "!\n";
}

int choose_cycle()
{
    int recursion_num = 0;
    char cycle_num;
    std::cout << "Choose your cycle:\n" << "1. While\n" << "2. For(increment)\n" << "3. For (everyone)\n"; // << "1. While\n" << "1. While\n"
    std::cin >> cycle_num;
    switch (cycle_num) {
    case '1': {
        recursion_num = 1;
        break;
    }
    case '2': {
        recursion_num = 2;
        break;
    }
    case '3': {
        recursion_num = 3;
        break;
    }
    }
    return recursion_num;
}

void write_numbers()
{
    int recursion_num = choose_cycle();
    std::vector<std::string>names = { "Bob", "Alex", "Gennady", "Angela", "Nemedy" };
    switch (recursion_num) {
        case 1: {
            int i = 0;
            while (i < names.size())
            {
                std::cout << names[i] << " ETO WHILE\n";
                ++i;
            }
            break;
        }
        case 2: {
            for (int i = 0; i < names.size(); ++i) {
                std::cout << names[i] << " ETO FOR increment\n";
            }
            break;
        }
        case 3: {
            for (std::string i : names) {
                std::cout << i << " ETO FOR every\n";
            }
            //Test throw
            error("LOvi chukcha");
            break;
        }
        default: {
            std::cout << "NE NASHEL";
        }
    }
}

void check_repeat_char_file() {
    std::ifstream fin;
    std::ofstream fon;
    std::vector<std::vector<int>> vecchar;
    std::vector<int> vecnum;

    fin.open("input.txt");
    if (fin.is_open()) {
        char a;
        while (fin.get(a)){
            auto result = 0;
            auto iter = vecchar.begin();
            int count = 0;
            std::vector<int> minivecchar;
            while (iter != vecchar.end())    
            {
                if (vecchar.at(count).at(0) == a) {
                    ++vecchar.at(count).at(1);
                    break;
                }
                ++count;
                ++iter;
            }
            if (iter == vecchar.end()) {
                minivecchar.push_back(a);
                minivecchar.push_back(1);
                vecchar.push_back(minivecchar);
            }
            std::cout << a;
        }
        fin.close();
    }

    fon.open("output.txt");
    if (fon.is_open()) {
        std::vector<int> minivecchar;
        auto iter = vecchar.begin();
        while (iter != vecchar.end()) {
            minivecchar = *iter;
            char ch = minivecchar.at(0);
            fon << ch << " counts " << minivecchar.at(1) << " times\n";
            ++iter;
        }
        fon.close();
    }
}

int main()
{
    try {
        check_repeat_char_file();
        keep_window_open();
    }
    //Test throw
    catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << "\n";
        keep_window_open();
        return 1;
    }

    return 0;
}


