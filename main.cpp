#include "matrix.hpp"
#include "matrix.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>



int main(int argc, char *argv[]) {
    /*      PROBLEM 1: Read values from a file into the matrix      */

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

    /*      PROBLEM 2: Add two matrixes and display the result      */

    std::cout<< "Matrix 1 + Matrix 2 =" << std::endl;
    Matrix m1PLUSm2 = m1.operator+(m2);
    m1PLUSm2.print_matrix();
    std::cout << "\n";

    /*      PROBLEM 3: Multiply two matrices and display the result      */

    std::cout<< "Matrix 1 * Matrix 2 =" << std::endl;
    Matrix m1TIMESm2 = m1.operator*(m2);
    m1TIMESm2.print_matrix();
    std::cout << "\n";

    /*      PROBLEM 4: Sum of major and minor elements in diagonal of matrix 1      */

    std::cout << "Matrix 1 sum of diagonal major elements: " << std::endl;
    std::cout << m1.sum_diagonal_major() << std::endl;
    std::cout << "Matrix 1 sum of diagonal minor elements: " << std::endl;
    std::cout << m1.sum_diagonal_minor() << std::endl;
    std::cout << "\n";

    /*      PROBLEM 4: Sum of major and minor elements in diagonal of matrix 2      */

    std::cout << "Matrix 2 sum of diagonal major elements: " << std::endl;
    std::cout << m2.sum_diagonal_major() << std::endl;
    std::cout << "Matrix 2 sum of diagonal minor elements: " << std::endl;
    std::cout << m2.sum_diagonal_minor() << std::endl;
    std::cout << "\n";

    /*      PROBLEM 5: Swap matrix rows and display the result      */

    //got how to store user input in C++ from Google AI Overview
    size_t row1;
    size_t row2; 
    int m_to_swap;
    std::cout << "Enter the index of the first row to be swapped: ";
    std::cin >> row1;
    std::cout << "Enter the index of the second row to be swapped: ";
    std::cin >> row2;
    std::cout << "Enter 1 if you want to swap rows in matrix 1 or Enter a 2 if you want to swap rows in matrix 2: ";
    std::cin >> m_to_swap;
    
    if (m_to_swap == 1){
        m1.swap_rows(row1, row2);
        std::cout << "Matrix 1 with row" << row1 << " swapped with row" << row2 << " : " << std::endl;
        m1.print_matrix();
    } else {
        m2.swap_rows(row1, row2);
        std::cout << "Matrix 2 with row" << row1 << " swapped with row" << row2 << " : " << std::endl;
        m2.print_matrix();
    }
    std::cout << " " << std::endl;


    /*      PROBLEM 6: Swap matrixe columns and display the result      */

    //got how to store user input in C++ from Google AI Overview
    size_t col1;
    size_t col2; 
    int c_to_swap;
    std::cout << "Enter the index of the first column to be swapped: ";
    std::cin >> col1;
    std::cout << "Enter the index of the second column to be swapped: ";
    std::cin >> col2;
    std::cout << "Enter 1 if you want to swap rows in matrix 1 or Enter a 2 if you want to swap rows in matrix 2: ";
    std::cin >> c_to_swap;
    std::cout << " " << std::endl;

    if (c_to_swap == 1){
        m1.swap_cols(col1, col2);
        std::cout << "Matrix 1 with row" << col1 << " swapped with row" << col2 << " : " << std::endl;
        if (col1 >= 0 & col1 < m1.get_size()-1 & col2 >= 0 & col2 < m1.get_size()-1){
            m1.print_matrix();
        } else {
            std::cout << "Index out of range." << std::endl;
        }
    } else {
        m2.swap_cols(col1, col2);
        std::cout << "Matrix 2 with row" << col1 << " swapped with row" << col2 << " : " << std::endl;
        if (col1 >= 0 & col1 < m1.get_size()-1 & col2 >= 0 & col2 < m1.get_size()-1){
            m2.print_matrix();
        } else {
            std::cout << "Index out of range." << std::endl;
        }
    }
    std::cout << " " << std::endl;


    /*      PROBLEM 7: Update matrix rows and display the result      */
    
    size_t row;
    size_t col; 
    int val;
    int m;
    std::cout << "Enter the index of the row you want to input at: ";
    std::cin >> row;
    std::cout << "Enter the index of the column you want to input at: ";
    std::cin >> col;
    std::cout << "Enter the new value you want inputted: ";
    std::cin >> val;
    std::cout << "Enter 1 if using matrix 1 or Enter a 2 if using matrix 2: ";
    std::cin >> m;  
    std::cout << " " << std::endl;

    if (m == 1){
        m1.set_value(row, col, val);
        if (row >= 0 & row < m1.get_size()-1 & col >= 0 & col < m1.get_size()-1){
            std::cout << "New Matrix: " << std::endl;
            m1.print_matrix();
        } else {
            std::cout << "Index out of range." << std::endl;
        }
    } else {
        m2.set_value(row, col, val);
        if (row >= 0 & row < m1.get_size()-1 & col >= 0 & col < m1.get_size()-1){
            std::cout << "New Matrix: " << std::endl;
            m2.print_matrix();
        } else {
            std::cout << "Index out of range." << std::endl;
        }
    }


    return 0;
}
