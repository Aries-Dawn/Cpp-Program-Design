#include "cnn_fun.hpp"

#define KERNEL_ELE 9
#define IMG0_SIZE 128
#define IMG0_CNS 3
#define IMG1_SIZE 64
#define IMG1_CNS 16
#define IMG1_POOL_SIZE 32
#define IMG2_SIZE 32
#define IMG2_CNS 32
#define IMG2_POOL_SIZE 16
#define IMG3_SIZE 8
#define IMG3_CNS 32

#define E 2.71828183

void CNN(string imgdir)
{
    Mat image;
    float *img = (float *)calloc(IMG0_SIZE * IMG0_SIZE * IMG0_CNS, sizeof(float));
    cout << imgdir << endl;

    // read in part
    try
    {
        image = imread(imgdir);
        for (int curChannel = 0; curChannel < IMG0_CNS; curChannel++)
        {
            for (int curRow = 0; curRow < IMG0_SIZE; curRow++)
            {
                for (int curCol = 0; curCol < IMG0_SIZE; curCol++)
                {
                    img[curChannel * IMG0_SIZE * IMG0_SIZE + curRow * IMG0_SIZE +
                        curCol] =
                        image.at<Vec3b>(curRow, curCol)[IMG0_CNS - 1 - curChannel] /
                        (float)255;
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        cerr << "\nInvalid directory. Please enter again.\n";
    }

    // conv layers

    float *img_first_layer = (float *)calloc(IMG1_SIZE * IMG1_SIZE * IMG1_CNS, sizeof(float));
    conv_relu(img, IMG0_SIZE, IMG0_CNS,
              img_first_layer, IMG1_SIZE, IMG1_CNS,
              conv0_weight, conv0_bias, 2);

    float *img_first_layer_pool = (float *)calloc(IMG1_POOL_SIZE * IMG1_POOL_SIZE * IMG1_CNS, sizeof(float));
    pooling(img_first_layer, IMG1_SIZE, IMG1_CNS,
            img_first_layer_pool, IMG1_POOL_SIZE);

    float *img_second_layer = (float *)calloc(IMG2_SIZE * IMG2_SIZE * IMG2_CNS, sizeof(float));
    conv_relu(img_first_layer_pool, IMG1_POOL_SIZE, IMG1_CNS,
              img_second_layer, IMG2_SIZE, IMG2_CNS,
              conv1_weight, conv1_bias, 1);

    float *img_second_layer_pool = (float *)calloc(IMG2_POOL_SIZE * IMG2_POOL_SIZE * IMG2_CNS, sizeof(float));
    pooling(img_second_layer, IMG2_SIZE, IMG2_CNS,
            img_second_layer_pool, IMG2_POOL_SIZE);

    float *img_third_layer = (float *)calloc(IMG3_SIZE * IMG3_SIZE * IMG3_CNS, sizeof(float));
    conv_relu(img_second_layer_pool, IMG2_POOL_SIZE, IMG2_CNS,
              img_third_layer, IMG3_SIZE, IMG3_CNS, conv2_weight, conv2_bias, 2);

    // This is a method to print read in img
    // for (size_t c = 0; c < 3; c++)
    // {
    //     cout<<c<<endl;
    //     for (size_t i = 0; i < 128; i++)
    //     {
    //         for (size_t j = 0; j < 128; j++)
    //         {
    //             cout <<img[c*128*128+i*128+j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    float bg_pow = mult(img_third_layer, fc0_weight, 2048, 0, 0) + fc0_bias[0];
    float face_pow = mult(img_third_layer, fc0_weight, 2048, 0, 2048) + fc0_bias[1];
    float *score = (float *)calloc(2, sizeof(float));
    softmax(E, bg_pow, face_pow, score);
    float bg_score = score[0];
    float face_score = score[1];
    cout << "The test result of " << imgdir << ":" << endl
         << "      background score: " << setprecision(6) << bg_score << endl
         << "      face score: " << setprecision(6) << face_score << endl;
    if (bg_score < face_score)
        cout << "This is face" << endl;
    else
        cout << "This is background" << endl;

    free(img);
    free(img_first_layer);
    free(img_first_layer_pool);
    free(img_second_layer);
    free(img_second_layer_pool);
    free(img_third_layer);
    free(score);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        string imgdir = "face.jpg";
        clock_t start, end;
        start = clock();
        CNN(imgdir);
        end = clock();
        // cout << "CNN time :" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
        cout << "CNN time :" << (double)(end - start) << endl;
    }
    else
    {
        string imgdir = argv[1];clock_t start, end;
        start = clock();
        CNN(imgdir);
        end = clock();
        // cout << "CNN time :" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
        cout << "CNN time :" << (double)(end - start) << endl;
    }
}