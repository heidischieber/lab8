#include "matrix.hpp" //includes matrix.hpp file
#include <fstream> //allows access to all components of header fstream
#include <iostream> //allows acces to all components of header iostream
#include <string> //allows access to all components of header string
#include <sstream> //allows acces to all components of header sstream



int main(int argc, char *argv[]) {
    /*      PROBLEM 1: Read values from a file into the matrix      */

    //information on how to open a file in C++ from Google AI overview 
    std::ifstream file; //creates an ifstream variable called file (for reading from files)
    file.open("lab8.txt"); //opens lab8.txt file
    //error checking if file opened correctly
    if (!file.is_open()){ //True if file is not open //got this function from Google AI Overview
        std::cout << "Error opening the file." << std::endl; //displays error with file
        return 0; //return to terminate main program
    }

    std::string line; //variable line ~ type: string
    std::vector<std::string> contents; //variable contents ~ a vector of strings
    std::vector<std::vector<int> > matrix1; //variable matrix1 ~ a vector of vectors of ints
    std::vector<std::vector<int> > matrix2; //variable matrix2 ~ a vector of vectors of ints 
    std::string num; //variable num ~ type: string
    std::size_t counter = 0; //variable counter ~ type; size_t and set to 0
    std::size_t size_n; //size of matrices stored in size_n

    while (std::getline(file, line)){ //while loop's condition evaluates as ture whiel there is a line to get from file ~ and the line is stored in line 
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end()); //from google AI overview ~ shows how to get rid of trailing and leading \n characters
        if (counter == 0){ //True if couter is 0
            size_n = std::stoi(line); //size_n is set to content of the first line ~ stoi converts from type string to int
            counter++; //increments counter 
        } else { //the following runs if counter is greater than 0
            std::stringstream ss(line); //creates a stringstream of line called ss ~ got from ChatGPT
            std::vector<int> v_num; //vector of ints called v_num
            while (getline(ss, num, ' ')){ //got this from geeksforgeeks ~ delimts by space and stores values one at a time in num
                v_num.push_back(std::stoi(num)); //adds int num to v_num vector
            }
            if (counter <= size_n){ //True if counter is less than or equal to size_n ~ means add to matrix1
                matrix1.push_back(v_num); //adds v_num vector of ints to matrix1 vector
            }
            else{ //True if counter is greater than size_n ~ means add to matrix2
                matrix2.push_back(v_num); //adds v_num vector of ints to matrix2 vector
            }
            counter++; //increments counter 
        }
    }

    file.close(); //closes file

    Matrix m1 = Matrix(matrix1); //creates a Matrix object out of matrix1 and stores it in m1
    Matrix m2 = Matrix(matrix2); //creates a Matrix object out of matrix2 and stores it in m2

    std::cout<< "Matrix 1:" << std::endl; //displays "Matrix 1: "
    m1.print_matrix(); //calls print_matrix() function which will display matrix m1
    std::cout << "\n"; //new line

    std::cout<< "Matrix 2:" << std::endl; //displays "Matrix 2: "
    m2.print_matrix(); //calls print_matrix() function which will display matrix m2
    std::cout << "\n"; //new line

    /*      PROBLEM 2: Add two matrixes and display the result      */

    std::cout<< "Matrix 1 + Matrix 2 =" << std::endl; //displays addition of matrices
    Matrix m1PLUSm2 = m1.operator+(m2); //m1PLUSm2 stores result of calling operator+ function on matrix m1 with input m2 ~ will add their contents
    m1PLUSm2.print_matrix(); //calls print_matrix() function which will display matrix m1PLUSm2
    std::cout << "\n"; //new line

    /*      PROBLEM 3: Multiply two matrices and display the result      */

    std::cout<< "Matrix 1 * Matrix 2 =" << std::endl; //displays multiplication of matrices
    Matrix m1TIMESm2 = m1.operator*(m2); //m1TIMESm2 stores result of calling operator* function on matrix m1 with input m2 ~ will multiply the matrices
    m1TIMESm2.print_matrix(); //calls print_matrix() function which will display matrix m1TIMESm2
    std::cout << "\n"; //new line

    /*      PROBLEM 4: Sum of major and minor elements in diagonal of matrix 1      */

    std::cout << "Matrix 1 sum of diagonal major elements: " << std::endl; //displays sum of diagonal major in m1
    std::cout << m1.sum_diagonal_major() << std::endl; //calls sum_diagonal_major() function on m1 and displays result
    std::cout << "Matrix 1 sum of diagonal minor elements: " << std::endl; //displays sum of diagonal minor in m1
    std::cout << m1.sum_diagonal_minor() << std::endl; //calls sum_diagonal_minor() function on m1 and displays result
    std::cout << "\n"; //new line

    /*      PROBLEM 4: Sum of major and minor elements in diagonal of matrix 2      */

    std::cout << "Matrix 2 sum of diagonal major elements: " << std::endl; //displays sum of diagonal major in m2
    std::cout << m2.sum_diagonal_major() << std::endl; //calls sum_diagonal_major() function on m2 and displays result
    std::cout << "Matrix 2 sum of diagonal minor elements: " << std::endl; //displays sum of diagonal minor in m2
    std::cout << m2.sum_diagonal_minor() << std::endl; //calls sum_diagonal_minor() function on m2 and displays result
    std::cout << "\n"; //new line

    /*      PROBLEM 5: Swap matrix rows and display the result      */

    //got how to store user input in C++ from Google AI Overview
    size_t row1; //initializes row1
    size_t row2;  //initializes row2
    int m_to_swap; //initializes m_to_swap
    std::cout << "Enter the index of the first row to be swapped: "; //displays to user what to input
    std::cin >> row1; //stores user input in row1
    std::cout << "Enter the index of the second row to be swapped: "; //displays to user what to input
    std::cin >> row2; //stores user input in row2
    std::cout << "Enter 1 if you want to swap rows in matrix 1 or Enter a 2 if you want to swap rows in matrix 2: "; //displays to user what to input
    std::cin >> m_to_swap; //stores user input in row2
    
    if (m_to_swap == 1){ //True if swap rows in m1
        if (row1 >= 0 & row1 < m1.get_size() & row2 >= 0 & row2 < m1.get_size()){ //checks if valid inputs
            m1.swap_rows(row1, row2); //swaps row1 with row2 in m1
            std::cout << "Matrix 1 with row" << row1 << " swapped with row" << row2 << " : " << std::endl; //displays what's happening
            m1.print_matrix(); //displays m1 now with swapped rows
        } else{
            std::cout << "Index out of range." << std::endl; //displays indexing error
        }
    } else { //the following runs if swap rows in m2
        if (row1 >= 0 & row1 < m1.get_size() & row2 >= 0 & row2 < m1.get_size()){ //checks if valid inputs
            m2.swap_rows(row1, row2); //swaps row1 with row2 in m2
            std::cout << "Matrix 2 with row" << row1 << " swapped with row" << row2 << " : " << std::endl; //displays what's happening
            m2.print_matrix(); //displays m2 now with swapped rows
        }
    }
    std::cout << "\n"; //new line


    /*      PROBLEM 6: Swap matrixe columns and display the result      */

    //got how to store user input in C++ from Google AI Overview
    size_t col1; //initializes col1
    size_t col2; //initalizes col2
    int c_to_swap; //initializes c_to_swap
    std::cout << "Enter the index of the first column to be swapped: "; //dispalys to user waht to input
    std::cin >> col1; //stores user input in col1
    std::cout << "Enter the index of the second column to be swapped: "; //dispalys to user waht to input
    std::cin >> col2; //stores user input in col2
    std::cout << "Enter 1 if you want to swap rows in matrix 1 or Enter a 2 if you want to swap rows in matrix 2: "; //dispalys to user waht to input
    std::cin >> c_to_swap; //stores user input in c_to_swap
    std::cout << "\n"; //new line 

    if (c_to_swap == 1){ //True if swap cols in m1
        if (col1 >= 0 & col1 < m1.get_size() & col2 >= 0 & col2 < m1.get_size()){ //checks if valid inputs
            m1.swap_cols(col1, col2); //swaps col1 with col2 in m1
            std::cout << "Matrix 1 with row" << col1 << " swapped with row" << col2 << " : " << std::endl; //description of what's happening
            m1.print_matrix(); //displays m1 now with swapped cols
        } else { 
            std::cout << "Index out of range." << std::endl; //displays indexing error
        }
    } else {
        if (col1 >= 0 & col1 < m1.get_size() & col2 >= 0 & col2 < m1.get_size()){ //checks if valid inputs 
            m2.swap_cols(col1, col2); //swaps col1 with col2 in m2
            std::cout << "Matrix 2 with row" << col1 << " swapped with row" << col2 << " : " << std::endl; //description of what's happening
            m2.print_matrix(); //displays m2 now with swapped cols
        } else {
            std::cout << "Index out of range." << std::endl; //displays indexing error
        }
    }
    std::cout << "\n"; //new line


    /*      PROBLEM 7: Update matrix rows and display the result      */
    
    size_t row; //initializes row
    size_t col; //initializes col
    int val; //initializes val
    int m; //initializes m
    std::cout << "Enter the index of the row you want to input at: "; //tells user what to input
    std::cin >> row; //stores user input in row
    std::cout << "Enter the index of the column you want to input at: "; //tells user what to input
    std::cin >> col; //stores user input in col
    std::cout << "Enter the new value you want inputted: "; //tells user what to input
    std::cin >> val; //stores user input in val
    std::cout << "Enter 1 if using matrix 1 or Enter a 2 if using matrix 2: "; //tells user what to input
    std::cin >> m; //stores user input in m
    std::cout << "\n"; //new line

    if (m == 1){ //True if set value in m1
        if (row >= 0 & row < m1.get_size() & col >= 0 & col < m1.get_size()){ //error checking
            m1.set_value(row, col, val); //sets m1[row][col] = val
            std::cout << "New Matrix: " << std::endl; //description of what's happening
            m1.print_matrix(); //displays m1 with new value
        } else {
            std::cout << "Index out of range." << std::endl; //displays error
        }
    } else {
        if (row >= 0 & row < m1.get_size() & col >= 0 & col < m1.get_size()){ //error checking 
            m2.set_value(row, col, val); //sets m2[row][col] = val
            std::cout << "New Matrix: " << std::endl; //description of what's happening
            m2.print_matrix(); //displays m2 with new value 
        } else {
            std::cout << "Index out of range." << std::endl; //displays error
        }
    }


    return 0; //returns to terminate program 
}
