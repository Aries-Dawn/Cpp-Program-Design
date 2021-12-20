#include <iostream>
#include <ctime>
#include <memory>
using namespace std;

class Rect
{
public:
    int x1;
    int y1;
    int x2;
    int y2;

public:
    Rect(int x1, int y1, int x2, int y2);
};

template <class T>
class Matrix
{
public:
    int row;
    int col;
    int len;
    int high;
    int channel;
    T *p_mat;
    T *start;

public:
    Matrix();
    Matrix<T> create_mat(char *path);
    void delete_mat();
    void allocateMem();
    Matrix<T> roi(Matrix<T> &mat, Rect &rec);
    Matrix<T> operator+(const Matrix<T> &second);
    Matrix<T> operator-(const Matrix<T> &second);
    Matrix<T> operator*(const Matrix<T> &second);
    Matrix<T> operator*(const T &number);
    Matrix<T> operator*(const char &c);
    bool operator==(const Matrix<T> &second);
    void operator=(const Matrix<T> &second);
    void write_mat(char *path);
};

Rect::Rect(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

template <class T>
Matrix<T> Matrix<T>::roi(Matrix<T> &mat, Rect &rec)
{
    int len = rec.y2 - rec.y1 + 1;
    int high = rec.x2 - rec.x1 + 1;
    // This is the start point of the window
    // Then I make a new Matrix and set this as it begin point of matrix
    // I also store the len and hight, means the window size and this will be used in read the data in window.
    T *ptr = mat.p_mat + (mat.row * rec.x1 + rec.y1);
    this->col = mat.col;
    this->row = mat.row;
    this->channel = mat.channel;
    this->high = high;
    this->len = len;
    this->p_mat = mat.p_mat;
    this->start = ptr;
    return *this;
}

template <class T>
void Matrix<T>::allocateMem()
{
    Matrix<T> *m = this;
    int chan = m->channel;
    double size = m->channel * m->row * m->col;
    m->p_mat = (T *)calloc(size, sizeof(float));
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &second)
{
    Matrix<T> *Result = (Matrix<T> *)malloc(sizeof(Matrix<T>));
    Result->channel = second.channel;
    Result->row = second.row;
    Result->col = second.col;

    Result->allocateMem();
    for (int i = 0; i < this->channel; i++)
    {
        for (int j = 0; j < this->row; j++)
        {
            for (int k = 0; k < this->col; k++)
            {
                Result->p_mat[i * this->row * this->col + j * this->col + k] = this->p_mat[i * this->row * this->col + j * this->col + k] + second.p_mat[i * this->row * this->col + j * this->col + k];
            }
        }
    }
    for (int i = 0; i < this->channel * this->row * this->col; i++)
    {
        Result->p_mat[i] = this->p_mat[i] + second.p_mat[i];
    }

    return *Result;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &second)
{
    Matrix<T> *Result = (Matrix<T> *)malloc(sizeof(Matrix<T>));
    Result->channel = second.channel;
    Result->row = second.row;
    Result->col = second.col;

    Result->allocateMem();
    for (int i = 0; i < this->channel * this->row * this->col; i++)
    {
        Result->p_mat[i] = this->p_mat[i] - second.p_mat[i];
    }

    return *Result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &second)
{
    Matrix<T> *Result = (Matrix<T> *)malloc(sizeof(Matrix<T>));
    Result->channel = second.channel;
    Result->row = second.row;
    Result->col = second.col;

    Result->allocateMem();
#pragma omp parallel for
    for (int c = 0; c < this->channel; c++)
    {
        for (int i = 0; i < Result->row; i++)
        {
            for (int k = 0; k < this->col; k++)
            {
                float tmp = this->p_mat[c * this->row * this->col + i * this->col + k];
                for (int j = 0; j < Result->col; j++)
                {
                    Result->p_mat[c * this->row * this->col + i * this->col + j] += tmp * second.p_mat[c * this->row * this->col + k * this->col + j];
                }
            }
        }
    }
    return *Result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T &number)
{
    Matrix<T> *Result = (Matrix<T> *)malloc(sizeof(Matrix<T>));
    Result->channel = this.channel;
    Result->row = this.row;
    Result->col = this.col;

    Result->allocateMem();

    for (int i = 0; i < this->channel * this->row * this->col; i++)
    {
        Result->p_mat[i] *= number;
    }
    return *Result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const char &c)
{

    Matrix<T> *Result = (Matrix<T> *)malloc(sizeof(Matrix<T>));
    Result->channel = this->channel;
    Result->row = this->row;
    Result->col = this->col;

    Result->allocateMem();
    int count = 0;
    for (int i = 0; i < this->channel; i++)
    {
        for (int j = 0; j < this->row; j++)
        {
            for (int k = 0; k < this->col; k++)
            {
                T x = this->p_mat[i * (this->row * this->col) + k * this->row + j];
                Result->p_mat[count] = x;
                count += 1;
            }
        }
    }
    return *Result;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T> &second)
{
    bool result = true;
    if (this->channel = second.channel && this->row == second.row && this->col == second.row)
    {
        for (int i = 0; i < this->channel * this->row * this->col; i++)
        {
            if (this->p_mat[i] != second.p_mat[i])
            {
                result = false;
            }
        }
    }
    else
    {
        result = false;
    }
    return result;
}

template <class T>
void Matrix<T>::operator=(const Matrix<T> &second)
{
    this->channel = second.channel;
    this->row = second.row;
    this->col = second.col;
    this->p_mat = second.p_mat;
}

template <class T>
Matrix<T>::Matrix()
{
    this->len = 0;
    this->high = 0;
};

template <class T>
Matrix<T> Matrix<T>::create_mat(char *path)
{
    Matrix<T> *m = (Matrix<T> *)malloc(sizeof(Matrix<T>));
    FILE *myfile = fopen(path, "r");
    int a = fscanf(myfile, "%d", &m->channel);
    a = fscanf(myfile, "%d", &m->row);
    a = fscanf(myfile, "%d", &m->col);

    m->allocateMem();

    int chan = m->channel;
    int size = m->channel * m->row * m->col;
    for (int i = 0; i < size; i++)
    {
        float temp;
        if (!fscanf(myfile, "%f", &temp))
        {
            break;
        }
        m->p_mat[i] = (T)temp;
    }

    fclose(myfile);
    return *m;
}

template <class T>
void Matrix<T>::delete_mat()
{
    Matrix<T> *mat = this;
    free(mat->p_mat);
}

template <class T>
void Matrix<T>::write_mat(char *path)
{
    FILE *myfile = fopen(path, "w");
    fprintf(myfile, "%d %d %d\n", this->channel, this->row, this->col);
    for (int k = 0; k < this->channel; k++)
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                fprintf(myfile, "%.2f ", (double)this->p_mat[k * this->row * this->col + i * this->col + j]);
            }
            fprintf(myfile, "\n");
        }
    }
}

template <class T>
void display_mat(Matrix<T> *ma)
{
    if (ma->len == 0 && ma->high == 0)
    {
        for (int i = 0; i < ma->channel; i++)
        {
            cout << "Channel " << i << endl;
            for (int j = 0; j < ma->row; j++)
            {
                for (int k = 0; k < ma->col; k++)
                {
                    cout.precision(3);
                    cout << (double)ma->p_mat[i * ma->row * ma->col + j * ma->col + k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    else
    {
        T *ptr = ma->start;
        for (int c = 0; c < ma->channel; c++)
        {
            cout << "Channel " << c << endl;
            for (int i = 0; i < ma->high; i++)
            {
                for (int j = 0; j < ma->len; j++)
                {
                    cout.precision(3);
                    cout << (double)ptr[j] << " ";
                }
                ptr += ma->col;
                cout << endl;
            }
            if (c + 1 < ma->channel)
            {
                ptr = ma->start + (ma->row * ma->col);
            }
            cout << endl;
        }
    }
}

int main(int argc, char **argv)
{
    Matrix<int> ma;
    Matrix<int> *pt_ma = &ma;
    ma = ma.create_mat(argv[1]);
    Matrix<int> mb;
    Matrix<int> *pt_mb = &mb;
    mb = mb.create_mat(argv[2]);
    time_t t;
    t = time(NULL);
    Matrix<int> res = ma * mb;
    double cost_t = time(NULL) - t;
    cout << "all time : " << cost_t << "s" << endl;

    // Rect rec(2, 2, 5, 5);
    // Matrix<int> re;
    // re = ma*'T';
    // Matrix<int> *pt_re = &re;
    // display_mat(pt_re);

    // Matrix<int> ro;
    // ro = ro.roi(ma, rec);
    // Matrix<int> *pt_ro = &ro;
    // display_mat(pt_ro);

    // bool b = ma == mb;
    // cout << boolalpha << b << endl;
    string s = "mat-R-2048.txt";
    char *p = (char *)s.data();
    res.write_mat(p);

    ma.delete_mat();
    mb.delete_mat();
    res.delete_mat();
    cout << "Finish Free Mem of Matrix" << endl;
}