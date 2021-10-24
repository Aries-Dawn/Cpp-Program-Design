typedef struct {
    int row_len;
    int col_len;
    float** p_mat;
} Matrix;

Matrix* create_mat(char*);
void delete_mat(Matrix*);
void copy_mat(Matrix*, Matrix*);
Matrix* multiple_mat(Matrix*, Matrix*);
void write_mat(char*, Matrix*);
void display_mat(Matrix*);
Matrix* calc_with_OpenBLAS(Matrix* m1, Matrix* m2);
