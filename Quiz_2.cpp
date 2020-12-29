#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

// 1st
/*Дана целочисленная матрица {Aij}i=1,...,n;j=1,...,m (n,m<=20).
  Найти сумму произведений элементов строк.*/

// m[0][0] m[0][1] m[0][2]
// m[1][0] m[1][1] m[1][2]
// m[2][0] m[2][1] m[2][2]
// sum = (m[0][0] * m[0][1] * m[0][2]) + (m[1][0] * m[1][1] * m[1][2]) + (m[2][0] * m[2][1] * m[2][2])

// 2nd


int main(){

    /*int rows, colomns;
    cin >> rows >> colomns;
    int sum = 0;
    vector<vector<int>> m(rows, vector<int>(colomns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colomns; ++j) {
            cin >> m[i][j];
        }
    }
    *//* ------------------------------------------------------- *//*
    for (int i = 0; i < rows; ++i) {
        int pr = 1;                                             // после суммирования pr к sum, меняем снова pr на 1
        for (int j = 0; j < colomns; ++j) {
            pr *= m[i][j];
        }
        sum += pr;                                              // пишем сумму произведения 1ой строки
        cout << "i:" << i << " "<< pr << endl;
    }
    cout << "sum: " << sum <<endl;
    *//* ------------------------------------------------------- *//*
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colomns; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }*/

    /*vector<vector<int>> mtrx = {{2,6,7}, {7,8,7}, {4,2,1}};*/

    /*const int n = 3;
    int m [n][n];                       // 5 rows, 5 columns
    srand((0));                         // rand function initialization
    for (int i = 0; i < n; ++i) {       // for rows
        for(int j = 0; j < n; ++j){     // for columns
            m[i][j] = rand() % 9;       // filling with random numbers from 0 to 9
        }
    }*/

    // printing filled matrix

    /*cout << sum;*/


    /*vector<int> vec = {};
    int m = 10;
    srand(time(0));
    for (int i = 0; i < m; ++i) {
        vec.push_back(rand()%10);

    }
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }*/

    // for(unsigned int n = 100; n >= 0; n--) переполнение типа
    // unsigned int без знаковый и цикл будет бесконечным

    /* квадратная матрица, n на n, где n вводится (с файла или клавы), заполнить матрицу змейкой 
    1     2    3    4  5
    16   17   18   19  6
    15   24   25   20  7
    14   23   22   21  8
    13   12   11   10  9*/


    const int raww = 10;
    const int col = 10;
    /*int aRr[raww][col] = {{1, 2, 1}, {1, 1, 1}, {1,2, 3}};*/ // либо так
    int total_summa = 0;

    // заполнение матрицы и операции
    vector<vector<int>> vec (raww, vector<int>(col));
    for (int i = 0; i < raww; ++i) {
        for (int j = 0; j < col; ++j) {
            vec[i][j] = (i) * (j); // либо (i+1) * (j+1)

            total_summa += vec[i][j]; // сумма
        }
    }
    cout << "summa: " << total_summa << endl;

    // вывод матрицы
    for (int i = 1; i < raww; ++i) {
        for (int j = 1; j < col; ++j) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }





    return 0;
}
