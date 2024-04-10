#ifndef MAT_H
#define MAT_H

#define NUM 10


/*
使用步骤：
    1.调用create函数构造矩阵，调用传入行数、列数、二维数据（矩阵），返回一个Mat类型的矩阵
    2.调用solve函数求解，传入Mat类型的系数矩阵和向量矩阵，返回解向量（Mat类型的矩阵）
*/


class Mat
{
public:
    Mat();
    Mat(int mm, int nn, float arr[][NUM]);

    Mat create(int m, int n, float ** arr);//创建矩阵
    void Print();//打印矩阵

    int m = 1, n = 1;           //行数和列数
    float mat[NUM][NUM] = { 0 };   //矩阵开始的元素
    void augmat(Mat a, Mat b);  //求矩阵 a 和向量 b 的增广矩阵
    bool solve(Mat a, Mat b);   //求线性方程组的解，其中a为系数矩阵，b为向量矩阵
};

#endif // MAT_H
