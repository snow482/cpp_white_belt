#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;

//--------------Sorting chars via tolower()--------------
/*bool Cmp (char& a, char& b){
    return tolower(a)<tolower(b);
}*/
void LettersSorting(vector<char>& v){
    /*sort(v.begin(), v.end(), Cmp);*/ //

    sort(v.begin(), v.end(), [] (char& a, char& b){
        return tolower(a) < tolower(b);
    });
}

int main() {

    int q;
    cin >> q;
    vector<char> letters;
    for (int i = 0; i < q; ++i) {
        char w;
        cin >> w;
        letters.push_back(w);
    }
    LettersSorting(letters);
    for(auto i : letters){
        cout << i << " ";
    }
    return 0;
}
