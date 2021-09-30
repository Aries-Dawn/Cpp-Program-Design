#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include<time.h>
using namespace std;

int getNumber(string name)
{
	int len_s = name.size();
	int i=0, j=0;
	while (i < len_s)
	{
		if (name[i] >= '0'&& name[i] <= '9')
		{
			j = i;
			int len = 0;
			while (name[i] >= '0'&& name[i] <= '9')
			{
				i++;
				len++;
			}
			string s0 = name.substr(j, len);//获取子串
            int num=0;//数字字符串转换为整型数字
			stringstream s1(s0);
			s1 >> num;
            return num;
		}
		else
		{
			i++;
		}
	}
	return 0;
}


vector<vector<double>> read_in(string name){
    int size = getNumber(name);
    vector<vector<double>> input;
    
    // FILE  *fq;
    // fq=fopen(name.c_str(),"r");
    ifstream infile;
    infile.open(name); 
    for (int i = 0; i < size; i++)
    {
        vector<double> temp0;
        for (int j = 0; j < size; j++)
        {
            double temp;
            // fscanf(fq,"%f ",&temp);
            infile >> temp;
            temp0.push_back(temp);
        }
        input.push_back(temp0);
        temp0.clear();
    }
    // fclose(fq);
    
    infile.close();
    return input;
}

vector<vector<double>> calculate(
                                    vector<vector<double>> &a, 
                                    vector<vector<double>> &b)
{
    vector<vector<double>> result;
    for (int i = 0; i < a.size(); i++)
    {
        vector<double> temp;
        for (int j = 0; j < b.size(); j++)
        {
            double res = 0;
            for (int k = 0; k < a.size(); k++)
            {
                res += a[i][k] * b[k][j];
            }
            temp.push_back(res);
        }
        result.push_back(temp);
    }
    return result;
}



int main(int argc, char *argv[]){
    clock_t start,end;
    start=clock();
    string input1 = argv[1];
    string input2 = argv[2];
    string out = argv[3];
    vector<vector<double>> matrix1 = read_in(input1);
    vector<vector<double>> matrix2 = read_in(input2);
    vector<vector<double>> result = calculate(matrix1,matrix2);

    ofstream file(out);
    file.setf(ios::fixed);
    file.precision(5);//精度为输出小数点后5位
    cout.setf(ios::fixed);
    cout.precision(3); 
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            file << result[i][j] << " ";
            // cout << result[i][j] << " ";
        }
        // cout << endl;
        file << endl;
    }
    file.close();
    
    end=clock();
    cout<<"F1运行时间"<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}



