#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;


void PrintMap(map<int, string>& m){
    for (auto item : m){
        cout << item.first <<": "<< item.second<< endl;
    }
}
map<string, int> ReversedMap(const map<int, string>& m){ // switch map<int, string> to map<string, int>
    map<string, int> result;
    for (auto item : m){ // better way -- for(const auto& item : m)
        result[item.second] = item.first;
    }
    return result;
}
void PrintReversedMap(const map<string, int>& m) { // printing map<string, int>
    for (auto item : m) { // better way -- for(const auto& item : m)
       cout << item.first << ": "<< item.second << endl;
    }
}

int main() {

    map<int, string> dates;
    dates[1994] = "Sonya's birth date";
    dates[1992] = "My birth date";
    dates[2020] = "fucking Corona";
    PrintMap(dates);
    dates.erase(2020); // .erase(m) - удаляет элемент с ключем "m" из map
    PrintMap(dates);
    PrintReversedMap(ReversedMap(dates));

    return 0;
}

