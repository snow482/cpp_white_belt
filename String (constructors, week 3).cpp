#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using std::reverse;
using std::map;
using std::vector;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;


class ReversibleString{
public:
    ReversibleString()= default;
    ReversibleString(const string& s){
        str = s;
    }

    void Reverse(){
        string s;
        for(std::string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit){


        }


    }
    /*void Reverse(){
        reverse(begin(str), end(str));
    }*/
    string ToString() const {
        return str;

    }

private:
    string str;
};

int main(){

    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    /*s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;*/


    return 0;
}