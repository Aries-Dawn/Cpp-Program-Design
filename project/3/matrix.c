#include "matrix.h"
#include <cblas.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

Matrix *create_mat(char *path) {
  Matrix *m = malloc(sizeof(Matrix));
  m->row_len = 0;
  m->col_len = 0;
  FILE *myfile = fopen(path, "r");
  int ch = 0;
  while (ch != EOF) {
    ch = fgetc(myfile);
    if (m->row_len == 0 && ch == ' ') {
      m->col_len++;
    }
    if (ch == '\n') {
      m->row_len++;
    }
  };

  m->col_len++;

  m->p_mat = calloc(m->row_len, sizeof(float *));
  for (int i = 0; i < m->row_len; i++) {
    m->p_mat[i] = calloc(m->col_len, sizeof(float));
  }

  rewind(myfile);

  for (int i = 0; i < m->row_len; i++) {
    for (int j = 0; j < m->col_len; j++) {
      if (!fscanf(myfile, "%f", &m->p_mat[i][j])) {
        break;
      }
    }
  }

  fclose(myfile);
  return m;
}

void delete_mat(Matrix *mat) {
  for (int i = 0; i < mat->row_len; i++) {
    free(mat->p_mat[i]);
  }
  free(mat->p_mat);
  free(mat);
}

void copy_mat(Matrix *target, Matrix *source) {
  delete_mat(target);
  target->row_len = source->row_len;
  target->col_len = source->col_len;
  target->p_mat = calloc(target->row_len, sizeof(float *));
  for (int i = 0; i < target->row_len; i++) {
    target->p_mat[i] = calloc(target->col_len, sizeof(float));
  }
  for (int i = 0; i < target->row_len; i++) {
    for (int j = 0; j < target->col_len; j++) {
      target->p_mat[i][j] = source->p_mat[i][j];
    }
  }
}

Matrix *multiple_mat(Matrix *mat1, Matrix *mat2) {
  Matrix *result = malloc(sizeof(Matrix));
  result->row_len = mat1->row_len;
  result->col_len = mat2->col_len;
  result->p_mat = calloc(result->row_len, sizeof(float *));
  for (int i = 0; i < result->row_len; ++i)
    result->p_mat[i] = calloc(result->col_len, sizeof(float));

#pragma omp parallel for
  for (int i = 0; i < result->row_len; i++) {
    for (int k = 0; k < mat1->col_len; k++) {
      float tmp = mat1->p_mat[i][k];
      for (int j = 0; j < result->col_len; j++) {
        result->p_mat[i][j] += tmp * mat2->p_mat[k][j];
      }
    }
  }

  return result;
}
void write_mat(char *path, Matrix *mat) {
  FILE *myfile = fopen(path, "w");
  for (int i = 0; i < mat->row_len; i++) {
    for (int j = 0; j < mat->col_len; j++) {
      if (j == mat->col_len - 1) {
        fprintf(myfile, "%f\n", mat->p_mat[i][j]);
      } else {
        fprintf(myfile, "%f ", mat->p_mat[i][j]);
      }
    }
  }
}

void display_mat(Matrix *m1) {
  for (int i = 0; i < m1->row_len; i++) {
    for (int j = 0; j < m1->col_len; j++) {
      if (j == m1->col_len - 1) {
        printf("%f\n", m1->p_mat[i][j]);
      } else {
        printf("%f ", m1->p_mat[i][j]);
      }
    }
  }
}

Matrix *calc_with_OpenBLAS(Matrix *m1, Matrix *m2) {
  Matrix *result = malloc(sizeof(Matrix));
  result->row_len = m1->row_len;
  result->col_len = m2->col_len;
  result->p_mat = calloc(result->row_len, sizeof(float *));
  for (int i = 0; i < result->row_len; ++i)
    result->p_mat[i] = calloc(result->col_len, sizeof(float));
  const int M = m1->row_len;
  const int N = m2->col_len;
  const int K = m1->col_len;
  int lda = K;
  int ldb = N;
  int ldc = N;
  float *A = calloc(M * K, sizeof(float));
  float *B = calloc(K * N, sizeof(float));
  float *C = calloc(M * N, sizeof(float));
  int k = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      A[k] = m1->p_mat[i][j];
      k += 1;
    }
  }
  k = 0;
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < N; j++) {
      B[k] = m2->p_mat[i][j];
      k += 1;
    }
  }
  cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, 1.0f, A, lda,
              B, ldb, 1.0f, C, ldc);
  k = 0;
  for (int i = 0; i < result->row_len; i++) {
    for (int j = 0; j < result->col_len; j++) {
      result->p_mat[i][j] = C[k];
      k++;
    }
  }
  free(A);
  free(B);
  free(C);
  return result;
}