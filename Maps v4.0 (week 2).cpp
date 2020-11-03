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

int main() {

    vector<string> v = {"one", "two", "three"};
    map<char, vector<string>> grouped_words;
    for (const string &item : v) {
        grouped_words[item[0]].push_back(item);
    }
    for (const auto &i : grouped_words) {
        cout << i.first << endl;
        for (const string &w : i.second) {
            cout << w << endl;
        }
        cout << endl;
    }

    return 0;
}