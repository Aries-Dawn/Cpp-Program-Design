#include "cnn_fun.hpp"

float mult(float *v1, float *v2, int dim, int st1, int st2)
{
    // float temp,temp0;
    float sum = 0;
    for (size_t i = 0; i < dim; i++)
    {
        sum += v1[st1 + i] * v2[st2 + i];
    }
    return sum;
}

void conv_relu(const float *pic, const int pic_size, const int pic_cns,
               float *fm, const int fm_size, const int fm_cns,
               const float *weight, const float *bias, const int stride)
{
    float get_img_part[9];
    float get_weight[9];
    int kernelStart;
    int index;
    float sum;
    int count;
// #pragma omp parallel for
    for (size_t curOutChan = 0; curOutChan < fm_cns; curOutChan++)
    {
        for (size_t curRow = 0; curRow < pic_size; curRow += stride)
        {
            for (size_t curCol = 0; curCol < pic_size; curCol += stride)
            {
                sum = bias[curOutChan];
                for (size_t curInChan = 0; curInChan < pic_cns; curInChan++)
                {
                    kernelStart = curOutChan * pic_cns * 9 + curInChan * 9;
                    for (size_t temp = 0; temp < 9; temp++)
                    {
                        get_weight[temp] = weight[kernelStart + temp];
                    }

                    index = curInChan * pic_size * pic_size +
                            curRow * pic_size + curCol;
                    count = 0;
                    curRow -= 1;
                    curCol -= 1;
                    for (size_t i = 0; i < 3; i++)
                    {
                        for (size_t j = 0; j < 3; j++)
                        {
                            if (curRow + i < 0 || curCol + j < 0 || curRow + i >= pic_size || curCol + j >= pic_size)
                                get_img_part[count] = 0.0f;
                            else
                                get_img_part[count] = pic[index + i * pic_size + j];
                            count += 1;
                        }
                    }
                    curRow += 1;
                    curCol += 1;
                    sum += mult(get_img_part, get_weight, 9, 0, 0);
                }
                if (sum < 0.0f)
                    fm[curOutChan * fm_size * fm_size +
                       curRow / stride * fm_size +
                       curCol / stride] = 0.0f;
                else
                    fm[curOutChan * fm_size * fm_size +
                       curRow / stride * fm_size +
                       curCol / stride] = sum;
            }
        }
    }
}

void pooling(const float *pic, const int pic_size, const int cns,
             float *pic_pool, const int pic_pool_size)
{
    int index;
    float max;
    for (size_t c = 0; c < cns; c++)
    {
        for (size_t i = 0; i < pic_size; i += 2)
        {
            for (size_t j = 0; j < pic_size; j += 2)
            {
                index = c * pic_size * pic_size + i * pic_size + j;
                max = 0.0f;
                for (size_t row = 0; row < 2; row++)
                {
                    for (size_t col = 0; col < 2; col++)
                    {
                        if (pic[index + row * pic_size + col] > max)
                        {
                            max = pic[index + row * pic_size + col];
                        }
                    }
                }
                pic_pool[c * pic_pool_size * pic_pool_size +
                         i / 2 * pic_pool_size +
                         j / 2] = max;
            }
        }
    }
}

void softmax(double e, float bg_pow, float face_pow, float *score)
{
    float e_bg_pow = pow(e, bg_pow);
    float e_face_pow = pow(e, face_pow);
    float total_tensor = e_bg_pow + e_face_pow;
    score[0] = e_bg_pow / total_tensor;
    score[1] = e_face_pow / total_tensor;
}