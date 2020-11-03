#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;


map<char, int> BuildCharCounters (const string& str) {
    map<char, int> counters;
    for(char ch : str){
        ++counters[ch];
    }
    return counters;
}

int main() {

    int n;
    cin >> n;
        for (int i = 0; i < n; ++i) {
            string word_1, word_2;
            cin >> word_1 >> word_2;
            if(BuildCharCounters(word_1) == BuildCharCounters(word_2)){
                cout << "YES" << endl;
            }else {
                cout << "NO" << endl;
            }
        }

    return 0;
}