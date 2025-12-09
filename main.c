#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"


void print_matrix(Matrix* matrix) {
  size_t row = matrix->row;
  size_t col = matrix->col;
  for(size_t i = 0; i < row; i++) {
    for(size_t j = 0; j < col; j++) {
      int val = matrix_get_val(matrix, i, j);
      printf("%d ", val);
    }
    puts("");
  }

  puts("");
}

int main() {
  Matrix* matrix1 = matrix_create(2, 2);
  matrix_set_val(matrix1, 0, 0, 1);
  matrix_set_val(matrix1, 0, 1, 2);
  matrix_set_val(matrix1, 1, 0, 3);
  matrix_set_val(matrix1, 1, 1, 4);
  print_matrix(matrix1);

  Matrix* matrix2 = matrix_create(2, 2);
  matrix_set_val(matrix2, 0, 0, 1);
  matrix_set_val(matrix2, 0, 1, 2);
  matrix_set_val(matrix2, 1, 0, 3);
  matrix_set_val(matrix2, 1, 1, 4);

  Matrix* add_test = matrix_add(matrix1, matrix2);
  print_matrix(add_test);

  Matrix* mult_test = matrix_mult(matrix1, matrix2);
  print_matrix(mult_test);

  Matrix* transpose = matrix_transpose(matrix1);
  print_matrix(transpose);

  matrix_free(matrix1);
  matrix_free(matrix2);
  matrix_free(add_test);
  matrix_free(mult_test);
  matrix_free(transpose);
  return 0;
}
