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


class Person {
public:

    void ChangeFirstName(int year, const string &first_name) {
        auto it = m_firstName.find(year);
        if (it !=
            m_firstName.end()) { // условие означает, что элемент в map ЕСТЬ и повторяется (.end() - указывает ЗА ПОСЛЕДНИЙ элемент map)
            cout << "error, first name on this year already exist" << endl;
            return;
        }
        m_firstName[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
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
        CreateOutputString(name, last_name);

        /*for (auto it_f : m_firstName){
            if(year >= it_f.first){
                name = it_f.second;
            }
        }
        for(auto it_l : m_lastName){
            if(year >= it_l.first){
                last_name = it_l.second;
            }
        }*/
    }

    string GetFullNameWithHistory(int year) {
        string chronology = Chronology(year, m_firstName);
        if(chronology != ){

        }

        return chronology;
    }

private:
    map<int, string> m_firstName;
    map<int, string> m_lastName;

    string Checker(int year, map<int, string>& m) {
        string s = "";
        for (auto it : m){
            if (year >= it.first) { // если год >= ключу в m
                s = it.second;      // s = значение данного ключа
            }
        }
        return s;
    }


    // пробежаться по map и проверить
    string Chronology(int year, map<int, string>& m) {
        string s = Checker(year, m); // это последнее имя
       /*std::vector<string> res;*/
        string s1 = "";
        map<int, string> result;
        for(auto it : m){
            if(year <= it.first){
                result.insert(it);
            }
        }
        for(auto it1 : result){
            if (s != it1.second) {
                s1 = it1.second;
            }
        } return s1;

    }
    string CreateOutputString (string name, string last_name){
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

};


int main() {
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;


    return 0;
}
