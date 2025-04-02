#include "matrix.hpp"
#include <vector>
#include <iostream>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

//constructor with no nums inputted
Matrix::Matrix(size_t N) { //constructor with input N
    // initialize an empty NxN matrix
    _N = N; //sets _N equal to N
    for (size_t i = 0; i < N; i++){ //for loop iterates from 0 to N
        std::vector<int> empty_row(N, 0); //got empty_row(N, 0) from chatGPT ~ was having issues of copying same empty_row over and over again resulting in infinite zeros
        _matrix.push_back(empty_row);  //add empty_row to _matrix
    }
}

// constructor with vector of vector of ints 
Matrix::Matrix(std::vector<std::vector<int> > nums) {
    _N = nums.size(); //sets _N to length of nums

    for (size_t i = 0; i < _N; i++){ //for loop iterates from 0 to _N
        std::vector<int> row; //intializes row
        for (size_t j = 0; j < _N; j++){ //for loop iterates from 0 to _N
            int entry = nums[i][j]; //initializes entry as num[i][j]
            row.push_back(entry); //adds entry to row
        } 
        _matrix.push_back(row); //adds row to _matrix
    }   
}

void Matrix::set_value(std::size_t i, std::size_t j, int n){ //set value function
    _matrix[i][j] = n; //sets _matrix[i][j] to value n
}

int Matrix::get_value(std::size_t i, std::size_t j) const{ //get value function
    return _matrix[i][j]; //returns value at _matrix[i][j]
}

int Matrix::get_size() const{ //get size function
    return _N; //returns _N
}

//matrix addition
Matrix Matrix::operator+(const Matrix &rhs) const{ //matrix addition function
    Matrix result(_N); //creates a matrix of 0s called result
    for (size_t i = 0; i < _N; i++){ //iterates from 0 to _N
        for (size_t j = 0; j < _N; j++){ //iterates from 0 to _N
            result.set_value(i, j, (get_value(i, j) + rhs.get_value(i, j))); //sets value of result[i][j] equal to the value of _matrix[i][j] plus rhs[i][j]
        }
    }
    return result; //return result (addition matrix)
}

//matrix multiplication
Matrix Matrix::operator*(const Matrix &rhs) const{ //matrix multiplication function 
    Matrix result(_N); //creates a matrix of 0s called result 
    for (size_t i = 0; i < _N; i++){ //iterates from 0 to _N
        for (size_t j = 0; j < _N; j++){ //iterates from 0 to _N
            int result_value = 0; //result value from multiplication 
            for (size_t z = 0; z < _N; z++){  //iterates from 0 to _N
                result_value += get_value(i, z) * rhs.get_value(z, j);  //result_value stores multiplication of _matrix[i][z] times rhs[z][j]
            } 
            result.set_value(i, j, result_value); //sets value of result[i][j] equal to result_value
        } 
    }
    return result; //return result (multiplication matrix)
}

//sum diagonal major
int Matrix::sum_diagonal_major() const{ //sum of diagonal major funciton
    int result = 0; //initializes result
    for (size_t i = 0; i < get_size(); i++){ //iterates from 0 to get_size()
        result = result + get_value(i, i); //result equals result plus value at _matrix[i][i] (gets values in major diagonal)
    }
    return result; //returns result 
}

//sum diagonal minor  
int Matrix::sum_diagonal_minor() const{ //sum of diagonal minor function
    int result = 0; //initializes result
    int row = 0; //initializes row
    for (int i = get_size() - 1; i >= 0; i--){ //iterates from get_size() - 1 to 0
        result = result + get_value(row, i); //result equals result plus value at _matrix[row][i] (gets values in minor diaognal)
        row ++; //increments row
    }
    return result; //reutrns result
}

//swap rows 
void Matrix::swap_rows(std::size_t r1, std::size_t r2){ //swap rows function 
    if (r1 >= 0 & r1 < get_size() & r2 >= 0 & r2 < get_size()){ //checks if inputs are within range
        int temp; //initializes temp 
        for (size_t i = 0; i < get_size(); i++){ //iterates from 0 to get_size()
            temp = get_value(r1, i); //temp is set to value at _matrix[r1][i]
            set_value(r1, i, get_value(r2, i)); //_matrix[r1][i] is set to value at _matrix[r2][i]
            set_value(r2, i, temp); //_matrix[r2][i] is set to temp
        }
    }
}

//swap columns
void Matrix::swap_cols(std::size_t c1, std::size_t c2){ //swap cols function 
    if (c1 >= 0 & c1 < get_size()-1 & c2 >= 0 & c2 < get_size()-1){ //checks if inputs are within range
        int temp; //initializes temp 
        for (size_t i = 0; i < get_size(); i++){ //iterates from 0 to get_size()
            temp = get_value(i, c1); //temp is set to value at _matrix[c1][i]
            set_value(i, c1, get_value(i, c2)); //_matrix[i][c1] is set to value at _matrix[i][c2]
            set_value(i, c2, temp); //_matrix[i][c2] is set to temp
        }
    }
}

// e.g. for a member function:

void Matrix::print_matrix() const { //print matrix function
    // print out the matrix
    for (size_t i = 0; i < _N; i++){ //iterates from 0 to _N
        for (size_t j = 0; j < _N; j++){ //iterates from 0 to _N
            std::cout << _matrix[i][j] << " "; //prints value at _matrix[i][j]
        }
        std::cout << "\n"; //new line 
    }
}
