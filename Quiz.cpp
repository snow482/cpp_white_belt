#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;




/* void Func (vector<int> v){

}*/



/*
1) пробежать по массиву, проверить заканчивается ли число на 2 и 4
2) найти произведение этих чисел
3) найти наименьшее из этих чисел и номер этого числа
*/

/*Дана последовательность натуральных чисел {Aj} (n<=10000) Найти произведение чисел,
 * заканчивающихся цифрой 2 или 4, наименьшее из таких чисел и номер этого числа в последовательности.*/
int main() {

    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 142, 1402, 1247, 120};
    for(int i = 0; i < vec.size(); ++i){
       cout << vec[i]/10 << " " << vec[i] % 10 << " " << (vec[i]/10) * 10 + vec[i] % 10 <<endl;
        /*if(vec[i] % 3 == 0){
          cout << i << " ";
       }*/
    }



}