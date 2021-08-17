// TryToReturnSkillPart2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

void say_my_name();

int choose_cycle();

void write_numbers();

inline void keep_window_open() { char ch; std::cin >> ch; }

int main()
{
    write_numbers();
    keep_window_open();
    return 0;
}

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
    std::vector<std::string>names = {"Bob", "Alex", "Gennady", "Angela", "Nemedy"};
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
        for (int i = 0; i  < names.size(); ++i) {
            std::cout << names[i] << " ETO FOR increment\n";
        }
        break;
    }
    case 3: {
        for (std::string i : names) {
            std::cout << i << " ETO FOR every\n";
        }
        break;
    }
    default: {
        std::cout << "NE NASHEL";
        std::error("BAREBUHI NAPALI");
    }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
