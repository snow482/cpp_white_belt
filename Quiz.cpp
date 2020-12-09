#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


/*Дана последовательность натуральных чисел {Aj} (n<=10000) Найти произведение чисел,
 * заканчивающихся цифрой 2 или 4, наименьшее из таких чисел и номер этого числа в
 * последовательности.*/

/*
1) пробежать по массиву, проверить заканчивается ли число на 2 или 4
2) найти произведение этих чисел
3) найти наименьшее из этих чисел и индекс этого числа в последовательности
*/

int main() {

    /*------------- v1.0 -------------
    vector<int> vec = {0, 1, 12, 122, 112, 5, 6, 7, 4, 9, 10, 5, 14, 142, 1402, 1247, 120};
    long long num_composition = 1;
    vector<int> v;
    for(auto i : vec){
        if(i % 10 == 2 || i % 10 == 4){
            cout << i << endl;
            v.push_back(i);
        }
    }
    cout << "-----" << endl;
    for(auto i : v){
        num_composition *= i;
    }
    cout << num_composition << endl;

    auto it_min = v.begin();
    for(auto it = v.begin(); it != v.end(); ++it){
        if(*it_min > *it){
            it_min = it;
        }
    }
    cout << *it_min << endl;

    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] == *it_min ){
            cout << i << endl;
        }
    }*/

    //------------- v2.0 -------------
    vector<int>numbers = {5, 6, 7, 8, 9, 10, 5, 14, 142, 402, 47, 120};
    vector<int>founded_nums;
    long long multiply_nums = 1;

    for(auto i : numbers){
        if(i % 10 == 2 || i % 10 == 4){
            founded_nums.push_back(i);
        }
    }
    for(auto it : founded_nums){
        cout << it << " " << "\n";
    }
    for (int i = 0; i < founded_nums.size(); ++i) {
        multiply_nums *= founded_nums[i];

    }
    cout << multiply_nums << endl;

    int min = founded_nums[0];
    for (int i = 1; i < founded_nums.size(); ++i) {
        if(min > founded_nums[i]){
            min = founded_nums[i];
        }
    }
    cout << min << endl;

    for (int i = 0; i < numbers.size(); ++i) {
        if(min == numbers[i]){
            cout << i << endl;
        }
    }
}