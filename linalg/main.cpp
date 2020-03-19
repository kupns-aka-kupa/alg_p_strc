#include "_matrix.h"
#include "_sqmatrix.h"
#include "_vector.h"

int main()
{
    Vector<int> v(2, 3, 5);
//    v = Vector<int>{2, 3, 5};

    double arrays[5][5] = {{300, 130, 3, 7, 1},
                     {2, 8, 5, 90, 3},
                     {1, 5, 27, 4, 52},
                     {1, 1, 2, 0, 9},
                     {89, 6, 2, 1, 2}};
    int n = 4;
    double array[4][4] = {
        {3, 13, 3, 7},
        {2, 8, 5, 9},
        {1, 5, 27, 4},
        {1, 1, 2, 0},
    };
    double array2[4][4] = {
        {55, 9, 3, 22},
        {2, 8, 4, 9},
        {6, 5, 17, 4},
        {68, 55, 35, 1},
    };
//    int n = 3;
//    double array[3][3] = {
//        {30, 13, 3},
//        {2, 8, 5},
//        {1, 5, 27}
//    };
    double ** minor = new double * [n];
    for (int i = 0; i < n; i++)
    {
        minor[i] = new double [n];
        for (int j = 0; j < n; j++){
            minor[i][j] = array[i][j];
        }
    }
    double ** minor2 = new double * [n];
    for (int i = 0; i < n; i++)
    {
        minor2[i] = new double [n];
        for (int j = 0; j < n; j++){
            minor2[i][j] = array2[i][j];
        }
    }
    SqMatrix m(n, minor);
    std::cout << m.determinant() <<std::endl; // 1.21191e+08d
//    std::cout << m.determinant() <<std::endl; // 1224
    Matrix m4 = m * m;
    m4.print();
    return 0;
}
