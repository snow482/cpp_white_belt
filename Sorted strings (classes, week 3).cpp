#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

//--------------Sorted Strings------------------------------------

//need to write the same sorted string via set for more effective work

//--------------Sorted Strings------------------------------------
class SortedStrings{
public:
    void AddString (const string& s){
        v.push_back(s);
    }
    vector<string> GetSortedStrings(){
        std::sort(v.begin(), v.end());
        return v;
    }
private:
    vector<string> v;
};

void PrintSortedStrings(SortedStrings& strings){
    for (const string& s :strings.GetSortedStrings()){
        cout << s << " ";
    }
}

int main() {

       SortedStrings strings;

       strings.AddString("first");
       strings.AddString("third");
       strings.AddString("second");
       PrintSortedStrings(strings);

       strings.AddString("second");
       PrintSortedStrings(strings);

    return 0;
}
