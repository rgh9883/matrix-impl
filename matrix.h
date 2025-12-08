#ifndef MATRIX_H
#define MATRIX_H


#include <stddef.h>


typedef struct {
  size_t row;
  size_t col;
  int* data;
} Matrix;

Matrix* matrix_create(size_t row, size_t col);
int matrix_get_val(Matrix* matrix, size_t row, size_t col);
void matrix_set_val(Matrix* matrix, size_t row, size_t col, int new_val);
Matrix* matrix_add(Matrix* matrix1, Matrix* matrix2);
Matrix* matrix_mult(Matrix* matrix1, Matrix* matrix2);
Matrix* matrix_transpose(Matrix* matrix);
void matrix_free(Matrix* matrix);

#endif
