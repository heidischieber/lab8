#include "matrix.hpp"
#include "matrix.cpp"
#include <fstream>
#include <iostream>
#include <string>



int main(int argc, char *argv[]) {
    //information on how to open a file in C++ from Google AI overview 
    std::ifstream file;
    file.open("lab8.txt");
    //error checking if file opened correctly
    if (!file.is_open()){
        std::cout << "Error opening the file." << std::endl;
        return 0;
    }

    std::string line; 
    std::int first_line = 1;
    while (std::getline(file, line)){
        //looked at example from geeksforgeeks to figure out how to delimit the line by spaces between numbers
        std::stringstream ss(line);
        std::vector<int> v_num;
        std::string num;
        while (std::getline(ss, s, ' ')){
            v_num.push_back(std::stoi(num)); //stoi converts from string to int 
        }


    }


    return 0;
}
