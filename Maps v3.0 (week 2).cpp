#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;


void PrintMap(const map<string, int>& m){
    for (const auto& item : m){
        cout << item.first << ": " << item.second << endl;
    }
}

int main() {

    vector<string> v = {"one", "two", "three", "two"};
    map<string, int> dublicateCounter;

    for (const auto& item : v){
        ++dublicateCounter[item];   // как только произошло обращение к конкретному элементу словаря с помощью
                                    // квадратных скобок, компилятору нужно создать пару ключ-значение, с данным ключем
                                    // и значением по умолчанию. В данном случае, как только происходит обращение
                                    // к какому то ключу, если этот ключ был, то компилятор возвращает ссылку на него
                                    // и успешно происходит ++dublicateCounter[item], а если такого ключа не было, то
                                    // компилятор его сам добавляет со значением 0, тк целое число поумолчанию = 0;
    } // обращение к несуществующему ключу может увеличить размер map(словаря)
    PrintMap(dublicateCounter);

    return 0;
}

