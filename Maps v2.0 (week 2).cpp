#include <iostream>
#include <string>
#include <map>

using std::map;
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

    map<string, int> spellsNums = {{"alohomora", 1}, {"accio", 2}, {"avada kedavra", 3}};
    PrintMap(spellsNums);

    return 0;
}
