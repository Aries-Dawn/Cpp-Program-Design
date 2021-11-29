#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
#include <immintrin.h>

using namespace std;

// g++ -o mul_SSE mul_SSE.cpp -march=native && ./mul_SSE

struct MyMatrix {
    float* mat; // array of floats.
    size_t row; // number of rows in the matrix.
    size_t col; // number of columns in the matrix.

    float& operator()(int r, int c) {
        return mat[r*col+c];
    }

    size_t length() {
        return row*col;
    }
};
MyMatrix allocMatrix( int row, int col ) {
    struct MyMatrix result;
    result.row = row;
    result.col = col;
    result.mat = (float*)malloc( sizeof(float)*row*col );

    return result;
}
void freeMatrix( struct MyMatrix& matrix ) {
    free(matrix.mat);
}
MyMatrix readMatFromFile( const char* filename ) {
    FILE* file = fopen( filename, "r" );
    int row, col;
    fscanf(file, "%d%d", &row, &col );
    printf("%d  %d",row, col);
    MyMatrix result = allocMatrix(row, col);
    for( int i = 0; i < row; ++ i )
        for( int j = 0; j < col; ++ j )
            fscanf(file, "%f", &result(i,j));
    fclose(file);
    return result;
}
void writeMatToFile( MyMatrix& mat, const char* filename ) {
    FILE* file = fopen( filename, "w" );
    fprintf(file, "%zu %zu\n", mat.row, mat.col );
    for( int i = 0; i < mat.row; ++ i ) {
        for( int j = 0; j < mat.col; ++ j )
            fprintf(file, " %f", mat(i,j));
        fprintf(file, "\n");
    }
    fclose(file);
}
MyMatrix multiply( MyMatrix& a, MyMatrix& b ) {
    MyMatrix result = allocMatrix( a.row, b.col );
    memset( result.mat, 0, sizeof(float)*result.length() );
    if( a.col != b.row )
        return result;
    for( int j = 0; j < b.col; j ++ )
        for( int k = 0; k < a.col; ++ k ) {
            __m128 m2 = _mm_set_ps(b(k*4+3,j), b(k*4+2,j), b(k*4+1,j), b(k*4,j));
            for( int i = 0; i < a.row; i ++ ) {
                __m128 m1 = _mm_load_ps(&a(i,k*4));
                __m128 resul = _mm_mul_ps(m1, m2);
                float buffer[4];
                _mm_store_ps(buffer, resul);
                result(i, j) += buffer[0]+buffer[1]+buffer[2]+buffer[3];
             }
        }
    return result;
}

int main() {
    MyMatrix mat1 = readMatFromFile( "./2048_1.txt" );
    printf("gjs");
    MyMatrix mat2 = readMatFromFile( "./2048_2.txt" );

    time_t t1 = time(NULL);
    MyMatrix res = multiply( mat1, mat2 );
    time_t t2 = time(NULL);

    double usedTime = difftime(t2, t1);
    printf("Calculation used %lf second(s).\n", usedTime);

    writeMatToFile( res, "2048_c.txt" );

    freeMatrix(mat1);
    freeMatrix(mat2);
    freeMatrix(res);
return 0;
}
