#include "matrix.hpp"
#include "matrix.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>



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
    std::vector<std::string> contents;
    std::vector<std::vector<int> > matrix1;
    std::vector<std::vector<int> > matrix2;
    std::string num;
    int counter = 0;
    int size_n; //size of matrices
    while (std::getline(file, line)){
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end()); //from google AI overview ~ shows how to get rid of trailing and leading \n characters
        if (counter == 0){
            size_n = std::stoi(line);
            counter++;
        } else {
            std::stringstream ss(line);
            std::vector<int> v_num;
            while (getline(ss, num, ' ')){ //got this from geeksforgeeks
                v_num.push_back(std::stoi(num)); //stoi converts from string to int                
            }
            
            if (counter <= size_n){
                matrix1.push_back(v_num);
            }
            else{
                matrix2.push_back(v_num);
            }
            counter++;
            
        //contents.push_back(line); //store each line from file in contents 
        }
    }
    file.close();

    Matrix m1 = Matrix(matrix1);
    Matrix m2 = Matrix(matrix2);

    m1.print_matrix();
    m2.print_matrix();


    return 0;
}
