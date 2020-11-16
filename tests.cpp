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
        string name = Checker(year, m_firstName); // выводим макс. значение которое сооветствует >= year
        pair<int, string> yearName = {year, name};
        for(auto it : m_firstName){ // бежим по map имен
            if(it.second != name){  // если значение ключа массива имен != значению year
                namesWithoutDubl.push_back(yearName); // вставить значение в мап namesWithoutDubl
            }
        }
        for(auto it : namesWithoutDubl){

        }



        // найти и не выводить повторяющиеся элементы в map
        /*auto name_check = namesWithoutDublicates.begin();
        for(auto it : namesWithoutDublicates){
           if(name_check != it.second){
               name_check += it.second;


        /*if (name == ""  && last_name == "" ) {
            return "Incognito";
        }
        if (name != ""  && last_name == "" ) {
            return name + " with unknown last name";
        }
        if (last_name != ""  && name == "" ) {
            return last_name + " with unknown first name";
        } else {
            return name + " " + last_name;
        }*/
    }

private:
    map<int, string> m_firstName;
    map<int, string> m_lastName;
    vector<pair<int, string>> namesWithoutDubl;
    vector<string> last_namesWithoutDubl;

    string Checker(int year, const map<int, string>& m) {
        string s;
        for (auto it : m){
            if (year >= it.first) { // если год >= ключу в m
                s = it.second;      // s = значение данного ключа
            }
        }
        return s;
    }

    // пробежаться по map и проверить
    string Checker_1(int year, map<int, string>& m) {
        string s;
        for(auto it : m){
            if(year <= it.first){
                s = it.second;
            }
        }
        return s;
    }
};


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
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;


    return 0;
}

