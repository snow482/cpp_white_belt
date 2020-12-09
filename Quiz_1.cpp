#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

// 1st
/*Дана последовательность вещественных чисел {Aj} (n<=10000). Найти сумму чисел, лежащих на
 * отрезке [-7;19], наибольшее из таких чисел и номер этого числа в последовательности*/
// sum(-7..19) = 162


// 2nd
/*Дана последовательность натуральных чисел {Aj} (n<=10000). Найти сумму чисел, заканчивающихся
цифрой 0 или 7, наибольшее из таких чисел, и номер этого числа в последовательности*/


int main(){

    // ------------- 1st -------------
    vector<long> vec_1 = {-8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                          11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    long sum = 0;
    for (int i = 0; i < vec_1.size(); ++i) {
        if (vec_1[i] >= -7 && vec_1[i] <= 19){
            sum += vec_1[i];
        }
    }
    cout << "sum[-7;19]: " << sum << endl;
    long max = vec_1[0];
    for (int i = 1; i < vec_1.size(); ++i) {
        if(vec_1[i] >= -7 && vec_1[i] <= 19){
            max = vec_1[i];
        }
    }
    cout << "max: " << max << endl;
    for (int i = 0; i < vec_1.size(); ++i) {
        if(max == vec_1[i]){
            cout << "max_index: "<< i << endl;
            cout << "-------------------" << endl;
        }
    }

    // ------------- 2nd -------------
    vector<int> vec_2 = {0, 1, 17, 122, 112, 5, 6, 7, 4, 9, 10, 5, 14, 142, 1402, 1247, 120};
    int num_sum = 0;
    for(auto i : vec_2){
        if(i % 10 == 0 || i % 10 == 7){
            cout << i << " ";
            num_sum += i;
        }
    }
    cout << "\n" << "sum: " << num_sum << endl;
    auto max_value = vec_2.begin();
    for(auto it = vec_2.begin(); it != vec_2.end(); ++it){
        if(*max_value < *it){
            max_value = it;
        }
    }
    cout << "max_value: " << *max_value << endl;
    for (int i = 0; i < vec_2.size(); ++i) {
        if(vec_2[i] == *max_value){
            cout << "max_value_index: " << i << endl;
        }
    }




}