#include "matrix.hpp"
#include <vector>
#include <iostream>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    std::vector<int> empty_row; //creates a vector of integers called empty_row

    for (int i = 0; i < N; i++){ //for loop iterates from 0 to N
        empty_row.push_back(0); //adds a 0 to empty_row
    }
    for (int j =0; j < N; j++){ //for loops iterates from 0 to N
        _matrix.push_back(empty_row); //
    }
}

// constructor with paramter 
Matrix::Matrix(std::vector<std::vector<int>> nums) {
    std::vector<int> row;

    for (int i = 0; i < _N; i++){
        for (int j = 0; j < _N; j++){
            int entry = nums[i][j];
            row.push_back(entry);
        } 
        _matrix.push_back(row);
    }   
}

void Matrix::set_value(std::size_t i, std::size_t j, int n){
    _matrix[i][j] = n;
}

// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
    for (int i = 0; i < _N; i++){
        for (int j = 0; j < _N; i++){
            std::cout << j << std::endl;
        }
        std::cout << "\n" << std::endl;
    }
}
