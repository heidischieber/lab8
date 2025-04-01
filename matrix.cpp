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
Matrix::Matrix(std::vector<std::vector<int> > nums) {
    _N = nums.size();
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

int Matrix::get_value(std::size_t i, std::size_t j) const{
    return _matrix[i][j];
}

int Matrix::get_size() const{
    return _N;
}

//matrix addition
Matrix Matrix::operator+(const Matrix &rhs) const{
    Matrix result(_N);
    for (int i = 0; i < _N; i++){
        for (int j = 0; j < _N; j++){
            result.set_value(i, j, (get_value(i, j) + rhs.get_value(i, j)));
        }
    }
    return result;
}

//matrix multiplication
Matrix Matrix::operator*(const Matrix &rhs) const{
    Matrix result(_N);
    for (int i = 0; i < _N; i++){
        for (int j = 0; j < _N; j++){
            int result_value = 0; //result value from multiplication
            for (int z = 0; z < _N; z++){
                result_value = result_value + (get_value(i, z) * rhs.get_value(z, j));
            }
        result.set_value(i, j, result_value);
        }
    }

}

//sum diagonal major
int Matrix::sum_diagonal_major() const{
    int result = 0;
    for (int i = 0; i < get_size(); i++){
        result = result + get_value(i, i);
    }
    return result;
}

//sum diagonal minor
int Matrix::sum_diagonal_minor() const{
    int result = 0;
    int row = 0;
    for (int i = get_size() - 1; i >= 0; i--){
        result = result + get_value(row, i);
        row ++;
    }
}

//swap rows 
void Matrix::swap_rows(std::size_t r1, std::size_t r2){
    int temp;
    for (int i = 0; i < get_size(); i++){
        temp = get_value(r1, i);
        set_value(r1, i, get_value(r2, i));
        set_value(r2, i, temp);
    }
}

//swap columns
void Matrix::swap_cols(std::size_t c1, std::size_t c2){
    int temp; 
    for (int i = 0; i < get_size(); i++){
        temp = get_value(i, c1);
        set_value(i, c1, get_value(c2, i));
        set_value(i, c2, temp);
    }
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
