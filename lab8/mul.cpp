#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
using namespace std;

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
    for( int i = 0; i < a.row; i ++ )
        for( int j = 0; j < b.col; j ++ )
            for( int k = 0; k < a.col; k ++ )
                result.mat[i*b.col+j] += a.mat[i*a.col+k] * b.mat[k*b.col+j];
    return result;
}

int main() {
    MyMatrix mat1 = readMatFromFile( "./2048_1.txt" );
    MyMatrix mat2 = readMatFromFile( "./2048_2.txt" );

    time_t t1 = time(NULL);
    MyMatrix res = multiply( mat1, mat2 );
    time_t t2 = time(NULL);

    double elasped = difftime(t2, t1);
    printf("Calculation used %lf second(s).\n", elasped);

    writeMatToFile( res, "2048_3.txt" );

    freeMatrix(mat1);
    freeMatrix(mat2);
    freeMatrix(res);
return 0;
}
