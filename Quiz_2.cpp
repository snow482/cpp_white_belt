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

// m[1][1] m[1][2] m[1][3]
// m[2][1] m[2][2] m[2][3]
// m[3][1] m[3][2] m[3][3]
// sum = (m[1][1] * m[1][2] * m[1][3]) + (m[2][1] * m[2][2] * m[2][3]) + (m[3][1] * m[3][2] * m[3][3])


// 2nd
/*#define n;
#define m;

void MultipRows( int arr[3][3]){

}*/


int main(){


    int rows, colomns;
    cin >> rows >> colomns;
    vector<vector<int>> mtrx;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colomns; ++j) {
            /*mtrx.push_back(vector<int>());*/
            cin >> mtrx[i][j];
        }
    }

    /*vector<vector<int>> mtrx = {{2,6,7}, {7,8,7}, {4,2,1}};*/

    /*int sum = 0;
    for (int i = 0; i < mtrx.size(); ++i) {
       sum = (mtrx[0][0] * mtrx[0][1] * mtrx[0][2]) + (mtrx[1][0] * mtrx[1][1] * mtrx[1][2]) + (mtrx[2][0] * mtrx[2][1] * mtrx[2][2]);


    }*/




    /*const int n = 3;
    int m [n][n];                       // 5 rows, 5 columns
    srand((0));                         // rand function initialization
    for (int i = 0; i < n; ++i) {       // for rows
        for(int j = 0; j < n; ++j){     // for columns
            m[i][j] = rand() % 9;       // filling with random numbers from 0 to 9
        }
    }*/

    // printing filled matrix
    for (int i = 0; i < mtrx.size(); ++i) {
        for (int j = 0; j < mtrx.size(); ++j) {
            cout << mtrx[i][j] << " ";
        }
        cout << endl;

    }
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


}
