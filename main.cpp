#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
using namespace std;
using namespace std::chrono;

// Задание "Palindrom Filter"

/*bool IsPalindrom(string n){
    for (int i = 0; i < n.length()/2; ++i){
        if (n[i] != n[n.length()-i-1])
        {
        return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength ){
    vector<string> result;

    for (int i = 0; i < words.size(); ++i)
        if (words[i].length() >= minLength && IsPalindrom(words[i]))
            result.push_back(words[i]);

    return result;
}


int main() {

    vector<string> test_1 = {"abacaba", "aba"};
    vector<string> test_2 = {"abacaba", "aba"};
    vector<string> test_3 = {"weew", "bro", "code"};
    int minLength;
    cin >> minLength;
    std::vector<std::string> res = PalindromFilter(test_3, minLength);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;

    return 0;
}*/



//-------------self-made Swap and Sort (1)----------------
/*void SpellsSwap(vector<string>& a){

    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a.size(); ++j) {
            if(a[i] < a[j])
            {
                string tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}*/

//-------------swap and sort via <algorithm> sort (2)-----
/*void SwapFunc(vector<string>& n) {
   sort(begin(n), end(n));
}*/
//---------------------------------------------------------

//--------------Задача "Максимизатор"----------------------
/*void UpdateIfGreater(const int first, int& second){
    if (first > second)
    {
        second = first;
        cout << second << endl;
    }else {

        cout << first << endl;
        cout << second << endl;
    }
}*/
//--------------Задача "Перемещение строк"----------------------
/*void MoveStrings (vector<string>& source, vector<string>& destination) {
    for (int i = 0; i < source.size(); ++i) {
        destination.push_back(source[i]);
    }
    source.clear();
}*/
//--------------Задача "Разворот последовательности"------------
/*void Reverse (vector<int>& v) {
    for (int i = 0; i < v.size()/2; ++i){
         int tmp = v[i];
         v[i] = v[v.size()-1-i];
         v[v.size()-1-i] = tmp;
    }
}*/
//--------------Задача "Разворот последовательности c "const"-----
/*vector<int> Reversed(const vector<int>& v){
    vector<int> result = v;
    for (int i = 0; i < result.size()/2; ++i) {
        int tmp = result[i];
        result[i] = result[result.size()-i-1];
        result[result.size()-i-1] = tmp;
    }
    return result;
}*/
//--------------Задача от Сани "использование итераторов"---------
/*void Funct (vector<int>& n){
    sort(begin(n), end(n));
}*/
//--------------Задача "средняя температура"----------------------







int main() {


//--------------Задача "средняя температура"----------------------

int t;
cin >> t;
vector<int> days_t_value;

cout << t << endl;
for (int i : days_t_value)
cout << i << " ";





//--------------Задача от Сани "использование итераторов"---------
    /*vector<int> n = { 4, 5, 8, 1, 2, 20, 54, 72, 12, 6 };
    Funct(n);
    for (auto it = n.cbegin(); it != n.cend(); ++it) {
        cout << *it << " ";
    }

    do {
        int a = *n.begin();  //n.front();
        int b = *n.rbegin(); //n.back();
        cout << "\n"<< "first element in vector: " << a << endl;
        cout << "last element in vector: " << b << endl;
    }
    while (false);*/
//--------------Задача "Разворот последовательности c "const"---
    /*vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result_vec = Reversed(vec);
    for (int i = 0; i < result_vec.size(); ++i) {
        cout << result_vec[i] << " ";
    }*/
//--------------Задача "Разворот последовательности"------------
   /* vector<int> num = { 1, 5, 3, 4, 2};
    Reverse(num);
    for (int i = 0; i < num.size(); ++i) {
        cout << num[i] << " ";
    }*/
//--------------Задача "Перемещение строк"----------------------
    /*vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for (int i = 0; i < destination.size(); ++i) {
        cout << destination[i] << " ";
    }*/
//--------------Задача "Максимизатор"---------------------------
    /*int a;
    int b;
    cin >> a >> b;
    UpdateIfGreater(a, b);
    UpdateIfGreater(5, b);
    cout << "a = " << a <<" , b = " << b << endl;*/
//--------------------------------------------------------------

    /*vector<string> spells = {"sonorus","reducto","expelliarmus","imperio","crucio","riddiculus",
                             "obliviate","alohomora","levitate","accio","expecto patronum","avada kedavra"};*/

//-------------------(1)-------------------
    /*SpellsSwap(spells);
    for (int i = 0; i < spells.size(); ++i)
        cout << spells[i] << " ";*/
//-------------------(2)-------------------
   /* SwapFunc(spells);
    for(auto x : spells){
        cout << x << " ";
    }*/
//---------------------------------------------------------

   // замер времени выполнения функции
    /*auto start = steady_clock::now();
    vector<MagiciansCount> mc = GetMagiciansNumber();
    auto finish = steady_clock::now();
    cout << "time is - "<< duration_cast<milliseconds> (finish - start).count() << " ms" << endl;


    start = steady_clock::now();
    PrintMagicianstNumber(mc);
    finish = steady_clock::now();
    cout << "time is - "<< duration_cast<milliseconds> (finish - start).count() << " ms" << endl;*/

    return 0;
}

