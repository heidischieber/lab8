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
    std::size_t counter = 0;
    std::size_t size_n; //size of matrices
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
                /*for (int i = 0; i < v_num.size(); i++){
                    std::cout << v_num[i] << std::endl;
                }
                std::cout << " " <<std::endl;*/
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

    std::cout<< "Matrix 1:" << std::endl;
    m1.print_matrix();
    std::cout << "\n";

    std::cout<< "Matrix 2:" << std::endl;
    m2.print_matrix();
    std::cout << "\n";

    std::cout<< "Matrix 1 + Matrix 2 =" << std::endl;
    Matrix m1PLUSm2 = m1.operator+(m2);
    m1PLUSm2.print_matrix();
    std::cout << "\n";

    std::cout<< "Matrix 1 * Matrix 2 =" << std::endl;
    Matrix m1TIMESm2 = m1.operator*(m2);
    m1TIMESm2.print_matrix();
    std::cout << "\n";

    std::cout << "Matrix 1 sum of diagonal major elements: " << std::endl;
    std::cout << m1.sum_diagonal_major() << std::endl;
    std::cout << "Matrix 1 sum of diagonal minor elements: " << std::endl;
    std::cout << m1.sum_diagonal_minor() << std::endl;
    std::cout << "\n";

    std::cout << "Matrix 2 sum of diagonal major elements: " << std::endl;
    std::cout << m2.sum_diagonal_major() << std::endl;
    std::cout << "Matrix 2 sum of diagonal minor elements: " << std::endl;
    std::cout << m2.sum_diagonal_minor() << std::endl;
    std::cout << "\n";


    return 0;
}
