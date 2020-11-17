#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;


class Person {
public:

    void ChangeFirstName(int year, const string& first_name) {
        auto it = m_firstName.find(year);
        if (it != m_firstName.end()) { // условие означает, что элемент в map ЕСТЬ и повторяется (.end() - указывает ЗА ПОСЛЕДНИЙ элемент map)
            cout << "error, first name on this year already exist" << endl;
            return;
        }
        m_firstName[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        auto it = m_lastName.find(year);
        if (it != m_lastName.end()) {
            cout << "error, last name on this year already exist" << endl;
            return;
        }
        m_lastName[year] = last_name;
    }

    string GetFullName(int year) {
        string name = Checker(year, m_firstName);
        string last_name = Checker(year, m_lastName);

        if (name == "" && last_name == "") {
            return "Incognito";
        }
        if (name != "" && last_name == "") {
            return name + " with unknown last name";
        }
        if (last_name != "" && name == "") {
            return last_name + " with unknown first name";
        } else {
            return name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) {

        auto current_name = Checker_1(year, m_firstName);
        auto current_last_name = Checker_1(year, m_lastName);
        if (current_name.second == "" && current_last_name.second == "") {
            return "Incognito";
        }
        vector<string> name_vec = PreviousData(current_name, m_firstName);
        vector<string> last_name_vec = PreviousData(current_last_name, m_lastName);

        if (current_name.second != "" && current_last_name.second == "") {
            return current_name.second + PreviousDataPrinter(name_vec) + " with unknown last name";
        }
        if(current_name.second == "" && current_last_name.second != ""){
            return  current_last_name.second + PreviousDataPrinter(last_name_vec) + " with unknown first name";
        }
        return current_name.second + PreviousDataPrinter(name_vec)+ " " +
               current_last_name.second + PreviousDataPrinter(last_name_vec);

    }

private:
    map<int, string> m_firstName;
    map<int, string> m_lastName;

    string Checker(int year, const map<int, string>& m) {
        string s;
        for (auto it : m){
            if (year >= it.first) { // если год >= ключу в m
                s = it.second;      // s = значение данного ключа
            }
        }
        return s;
    }
    string PreviousDataPrinter(const vector<string>& v){

        if(v.empty()){
            return "";
        }
        string s = " (";
        for(auto it = v.rbegin(); it != v.rend(); ++it){
            s += *it;
            if(it != --v.rend())
            {s += ", ";}
        }
        s += ")";
        return s;
    }
    vector <string> PreviousData ( const pair<int, string>& p, const map<int, string>& m){
        vector<string> vec;
        for(const auto& it : m){
            if(it.first >= p.first){
                break;
            }
            bool check = DublicateElemCheck(it.second,  vec);
            if(!check){
                 vec.push_back(it.second);
            }
        }
        bool doubleCheck = DublicateElemCheck(p.second,  vec);
        if(doubleCheck){
             vec.erase(vec.begin()+vec.size()-1);
        }
        return vec;
    }


    // пробежаться по map и проверить
    pair<int, string> Checker_1(int year, map<int, string>& m) {
        pair<int, string> p;
        for(auto it : m){
            if(it.first <= year ){
                p.first = it.first;
                p.second = it.second;
            }
        }
        return p;
    }
    bool DublicateElemCheck(string value, vector<string>& v){
        if(v.empty()){
            return false;
        }
        else {
            string s = v[v.size()-1];
            if(value == s){
                return true;
            }
            return false;
        }

        /*auto tt = v.begin();
        for(auto it = v.begin(); it != v.end(); ++it){
            if(value == *it){
                return true;
            }
        }*/
    }


};


// найти элемент по году
// (2) запомнить год и значение
// передать их в вектор
// пройтись по мапу до значений (2)
// найти значения подобные (2)
// сохранить значения (не год) в вектор
// вывести эти значения п) Полина (Анна, Галина) Волосатова (Власова)
//



int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}

