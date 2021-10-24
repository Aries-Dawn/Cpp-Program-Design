#include "matrix.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Invalid arguments!\n");
    return 1;
  }
  clock_t start, end;
  start = clock();
  Matrix *m1 = create_mat(argv[1]);
  end = clock();
  printf("Read in First file used time :%fs\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  Matrix *m2 = create_mat(argv[2]);
  end = clock();
  printf("Read in Second file used time :%fs\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  Matrix *result = multiple_mat(m1, m2);
  end = clock();
  printf("Calculate two matrix multiple used time :%fs\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  Matrix *result2 = calc_with_OpenBLAS(m1, m2);
  end = clock();
  printf("Calculate two matrix multiple with cblas_sgemm used time :%fs\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  write_mat(argv[3], result);
  write_mat("out2048-O.txt", result2);

  delete_mat(result2);
  delete_mat(result);
  delete_mat(m2);
  delete_mat(m1);
  return 0;
}