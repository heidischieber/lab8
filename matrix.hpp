#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

class Matrix {
public:
    Matrix(std::size_t N); //did
    Matrix(std::vector<std::vector<int> > nums); //did

    Matrix operator+(const Matrix &rhs) const; //did 
    Matrix operator*(const Matrix &rhs) const; //did
    void set_value(std::size_t i, std::size_t j, int n); //did 
    int get_value(std::size_t i, std::size_t j) const; //did
    int get_size() const; //did
    int sum_diagonal_major() const; //did
    int sum_diagonal_minor() const; 
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const; //did

private: 
    std::vector<std::vector<int> > _matrix; //a vector of vectors containing ints called _matrix 
    std::size_t _N; //int variable containing size of matrix in _n
};

#endif // __MATRIX_HPP__