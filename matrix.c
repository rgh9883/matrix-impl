#include <stdlib.h>
#include <stdio.h>


#include "matrix.h"


Matrix* matrix_create(size_t row, size_t col) {
  Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
  matrix->row = row;
  matrix->col = col;
  matrix->data = (int*) malloc(row * col * sizeof(int));

  return matrix;
}

int matrix_get_val(Matrix* matrix, size_t row, size_t col) {
  if(row >= matrix->row || col >= matrix->col) return -1;

  return matrix->data[(row*matrix->col) + col];
}

void matrix_set_val(Matrix* matrix, size_t row, size_t col, int new_val) {
  if(row >= matrix->row || col >= matrix->col) return;

  matrix->data[(row*matrix->col) + col] = new_val;
}

Matrix* matrix_add(Matrix* matrix1, Matrix* matrix2) {
  if(matrix1->row != matrix2->row || matrix1->col != matrix2->col) return NULL;

  size_t row = matrix1->row;
  size_t col = matrix1->col;
  Matrix* result = matrix_create(row, col);
  for(size_t i = 0; i < row; i++) {
    for(size_t j = 0; j < col; j++) {
      result->data[(i*col)+j] = matrix1->data[(i*col)+j] + matrix2->data[(i*col)+j];
    }
  }

  return result;
}

Matrix* matrix_mult(Matrix* matrix1, Matrix* matrix2) {
  if(matrix1->col != matrix2->row) return NULL;

  size_t row1 = matrix1->row;
  size_t col2 = matrix2->col;
  size_t col1 = matrix1->col;
  Matrix* result = matrix_create(row1, col2);

  for(size_t i = 0; i < row1; i++) {
    for(size_t j = 0; j < col2; j++) {
      int val = 0;
      for(size_t k = 0; k < col1; k++) {
        val += matrix1->data[(i*col1)+k] * matrix2->data[(k*col2)+i];
      }
      result->data[(i*col2)+j] = val;
    }
  }

  return result;
}

Matrix* matrix_transpose(Matrix* matrix) {
  size_t row = matrix->row;
  size_t col = matrix->col;
  Matrix* result = matrix_create(col, row);
  for(size_t i = 0; i < row; i++) {
    for(size_t j = 0; j < col; j++) {
      result->data[(j*row)+i] = matrix->data[(i*col)+j];
    }
  }

  return result;
}

void matrix_free(Matrix* matrix) {
  free(matrix->data);
  free(matrix);
}
