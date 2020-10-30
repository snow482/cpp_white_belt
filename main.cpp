#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
#include <list>
#include <utility>
#include <functional>
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
//--------------Задача "Перемещение строк"-----------------------
/*void MoveStrings (vector<string>& source, vector<string>& destination) {
    for (int i = 0; i < source.size(); ++i) {
        destination.push_back(source[i]);
    }
    source.clear();
}*/
//--------------Задача "Разворот последовательности"--------------
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
//--------------Задача "Очередь v1""----------------------------------
/*void Worry(vector<string>& v, int n){
    v[n-1] = "WORRY";
}
void Quiet(vector<string>& v, int n){
    v[n-1] = "QUIET";
}
void ComePlus(vector<string>& v, int n){
    for (int i = 0; i < n; ++i) {
        string s = "COME";
        v.push_back(s);
    }
}
void ComeMines(vector<string>& v, int n) {
    for (int i = 0; i < abs(n); ++i) {
        v.pop_back();
    }
}
int WorryCount(vector<string>& v){
    int wc = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == "WORRY"){
            ++wc;
        }
    }
    return wc;
}*/
//--------------Разбор map v1----------------------------------
/*void PrintMap(map<int, string>& m){
    for (auto item : m){
        cout << item.first <<": "<< item.second<< endl;
    }
}
map<string, int> ReversedMap(const map<int, string>& m){ // switch map<int, string> to map<string, int>
    map<string, int> result;
    for (auto item : m){ // лучше если -> for(const auto& item : m)
        result[item.second] = item.first;
    }
    return result;
}
void PrintReversedMap(const map<string, int>& m) { // printing map<string, int>
    for (auto item : m) { // лучше если -> for(const auto& item : m)
       cout << item.first << ": "<< item.second << endl;
    }
}*/
//--------------Разбор map v2, v3----------------------------------
/*void PrintMap(const map<string, int>& m){
    for (const auto& item : m){
        cout << item.first << ": " << item.second << endl;
    }
}*/

//--------------Anagrams----------------------------------
/*map<char, int> BuildCharCounters (const string& str) {
    map<char, int> counters;
    for(char ch : str){
        ++counters[ch];
    }
    return counters;
}*/
//--------------Capitals library----------------------------------







//--------------Iterators task v1.0------------------------------------
/*list<int> TestCountsAdding (int n){
    list<int> listName;
    for (int i = 0; i < n; ++i) {
        int nums;
        cin >> nums;
        listName.push_back(nums);
    }
    return listName;
}

void ListPrinter (list<int>& listName) {
    for(auto it = listName.begin(); it != listName.end(); ++it){
        cout << *it << " ";
    }
}

int MiddleSum (list<int>& listName){
    int sum = 0;
    for(auto it = listName.begin(); it != listName.end(); ++it){
        sum += *it;
    }
    int middleSum = sum / listName.size();
    return middleSum;
}*/
//--------------Iterators task v2.0------------------------------------
/*list<int> ListRead (int n){
    list<int> nums;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        nums.push_back(data);
    }
    return nums;
}

int MiddleArifmetic (list<int>& nums){
    int sum = 0;

    for (auto it = nums.begin(); it != nums.end(); ++it) {
        sum += *it;
    }
    int middle_sum = sum / nums.size();
    return middle_sum;
}

void ListPrinter (const list<int>& list_name){
    for(auto it = list_name.cbegin(); it != list_name.cend(); ++it){
        cout << *it << " ";
    }
}*/
//--------------Iterators task v3.0 - changing to std::pair-------------
list<pair<int, string>> PairListRead (int n){
    pair<int, string> newPair;
    list<pair<int, string>> info;

    for (int i = 0; i < n; ++i) {
        int peopleQuantity;
        string city;
        cin >> peopleQuantity >> city;
        newPair.first = peopleQuantity;
        newPair.second = city;
        info.push_back(newPair);
    }
    return info;
}
// - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - - -
// function initialization without defining (see to the main() )

/*void func(list<pair<int,string>>& viaPair, std::function<void(int,string)> call){
    for (auto it = viaPair.begin(); it != viaPair.end(); ++it){
        call(it->first,it->second);
    }
}*/
// - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - - -

int MiddleSum (list<pair<int, string>>& testList){
    int sum = 0;
    for(auto it = testList.begin(); it != testList.end(); ++it){
        sum += it->first;
    }
    int middleSum = sum / testList.size();
    return middleSum;
}
void PairListPrinting(const list<pair<int, string>>& printedList){
    for (auto it = printedList.cbegin(); it != printedList.cend(); ++it){
        cout << "People quantity: " << it->first << "\nCity: " << it->second << endl;
    }
}

int main() {
//--------------Iterators task v3.0 - changing list to std::pair list-------------
    int commandQuantity;
    cin >> commandQuantity;
    list<pair<int, string>> viaPair = PairListRead(commandQuantity);
// - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - - -
// function definition in the main()

    /*func(viaPair,[](int f, string s){cout << f << " " << s << endl;});*/
// - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - - -
    PairListPrinting(viaPair);

    auto itMax = viaPair.begin();
    auto itMin = viaPair.begin();
    for(auto it = viaPair.begin(); it != viaPair.end(); ++it){
        if(itMax->first < it->first){
            itMax = it;
        }
        if(itMin->first > it->first){
            itMin = it;
        }
    }
    int middleSum = MiddleSum(viaPair);
    auto itMinSaved = *itMin; // saving itMin for adding after itMax
                              // (! data types is "narrow" place)
    cout << "\nPeople quantity Min: " << itMin->first << endl;
    cout << "\nPeople quantity Max: " << itMax->first << endl;
    cout << "\nMiddle sum: " << middleSum << endl;

    // Deleting min value and adding the value after max value
    viaPair.erase(itMin);
    PairListPrinting(viaPair);
    viaPair.insert(++itMax, itMinSaved);
    PairListPrinting(viaPair);
//--------------Iterators task v2.0------------------------------------
    /*int itemQuantity;
    cin >> itemQuantity;
    list<int> nums = ListRead(itemQuantity);

    for(auto it = nums.begin(); it != nums.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    auto it_max = nums.begin();
    auto it_min = nums.begin();
    for (auto it = nums.begin(); it != nums.end(); ++it){
        if(*it_max < *it){
            it_max = it;
        }
        if(*it_min > *it){
            it_min = it;
        }
    }

    int middle_sum = MiddleArifmetic(nums);
    auto it_saved = *it_min;

    cout << *it_max <<endl;
    cout << it_saved << endl;
    cout << middle_sum << endl;

    nums.erase(it_min);
    nums.insert(++it_max, it_saved);
    ListPrinter(nums);*/
//--------------Iterators task v1.0------------------------------------
   /* int comandQuantity;
    cin >> comandQuantity;

    list <int> testList = TestCountsAdding(comandQuantity);


    auto it_max = testList.begin();
    auto it_min = testList.begin();
    for (auto it = testList.begin(); it != testList.end(); ++it){

        if(*it_max < *it){
            it_max = it;
        }
        if(*it_min > *it){
            it_min = it;
        }
    }
    ListPrinter(testList);
    int middleSum = MiddleSum(testList);

    int saved_it_min = *it_min;

    cout << "\nlist max: " << *it_max << "\nlist min: " << saved_it_min << endl;
    cout << "middle sum: " << middleSum << endl;

    testList.erase(it_min);
    testList.insert(++it_max, saved_it_min);
    ListPrinter(testList);
*/


//--------------Capitals library----------------------------------


//--------------Anagrams----------------------------------
/*int n;
cin >> n;
    for (int i = 0; i < n; ++i) {
        string word_1, word_2;
        cin >> word_1 >> word_2;
        if(BuildCharCounters(word_1) == BuildCharCounters(word_2)){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }*/
//--------------Разбор map v4----------------------------------
/*vector<string> v = {"one", "two", "three"};
map<char, vector<string>> grouped_words;
for (const string& item : v){
    grouped_words[item[0]].push_back(item);
}
for(const auto& i : grouped_words){
    cout << i.first << endl;
    for(const string& w : i.second){
        cout << w << endl;
    }
    cout << endl;
}*/
//--------------Разбор map v3----------------------------------
/*vector<string> v = {"one", "two", "three", "two"};
map<string, int> dublicateCounter;

for (const auto& item : v){
    ++dublicateCounter[item];   // как только произошло обращение к конкретному элементу словаря с помощью
                                // квадратных скобок, компилятору нужно создать пару ключ-значение, с данным ключем
                                // и значением по умолчанию. В данном случае, как только происходит обращение
                                // к какому то ключу, если этот ключ был, то компилятор возвращает ссылку на него
                                // и успешно происходит ++dublicateCounter[item], а если такого ключа не было, то
                                // компилятор его сам добавляет со значением 0, тк целое число поумолчанию = 0;
} // обращение к несуществующему ключу может увеличить размер map(словаря)
PrintMap(dublicateCounter);*/
//--------------Разбор map v2----------------------------------
/*map<string, int> spellsNums = {{"alohomora", 1}, {"accio", 2}, {"avada kedavra", 3}};
PrintMap(spellsNums);*/
//--------------Разбор map v1----------------------------------
/*map<int, string> dates;
dates[1994] = "Sonya's birth date";
dates[1992] = "My birth date";
dates[2020] = "fucking Corona";
PrintMap(dates);
dates.erase(2020); // .erase(m) - удаляет элемент с ключем "m" из map
PrintMap(dates);
PrintReversedMap(ReversedMap(dates));*/
//--------------Задача "Очередь v1"----------------------------
/*int opertations_quantity; // operations quantity
cin >> opertations_quantity;
vector<string> stackNum;
string command;
int command_meaning;
for(int i = 0; i < opertations_quantity; ++i){
    cin >> command;

    if (command == "WORRY_COUNT"){
        int wc = WorryCount(stackNum);
        cout << "WORRY COUNT: "<< wc << endl;
        continue;
    }

    if(command == "COME" || command == "WORRY" || command == "QUIET"){
        cin >> command_meaning;

        if (command == "COME" && command_meaning > 0){
            ComePlus(stackNum, command_meaning);
        }
        if (command == "COME" && command_meaning < 0){
            ComeMines(stackNum, command_meaning);
        }
        if (command == "WORRY" && command_meaning > 0){
            Worry(stackNum, command_meaning);
        }
        if (command == "QUIET" && command_meaning > 0){
            Quiet(stackNum, command_meaning);
        }
        continue;
    }

    cout << "Please, write a command from list below:\n"<< "COME (+/-)N <- for adding/deleting N humans \n"
        << "WORRY N <- change the human N \n" << " QUIET N <- change the human N \n"
        << "WORRY_COUNT <- for checking worrying people \n";

}
for (string str : stackNum)
    cout << str << " ";*/
//--------------Задача "средняя температура"----------------------
/*int t;
cin >> t;
vector<int> days_t_value;
int t_sum = 0;
for (int i = 0; i < t; ++i) {
    int inpu = 0;
    cin >> inpu;
    days_t_value.push_back(inpu);
    t_sum += inpu;
}
int middle_t = t_sum / t;
vector<int> days_quantity;
for (int i = 0; i < t; ++i) {
    if (days_t_value[i] > middle_t) {
        days_quantity.push_back(i);
    }
}
cout << days_quantity.size() << endl;
for (int day_index : days_quantity) {
    cout << day_index << " ";
}
cout << endl;*/
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

