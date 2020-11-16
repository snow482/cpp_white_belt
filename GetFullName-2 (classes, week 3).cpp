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

    void ChangeFirstName(int year, const string& first_name) {
        auto it = m_firstName.find(year);
        if (it !=m_firstName.end()) { // условие означает, что элемент в map ЕСТЬ и повторяется (.end() - указывает ЗА ПОСЛЕДНИЙ элемент map)
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
        string last_first_name = GetFullName(year); // last first name

        string name = Chronology(year, m_firstName);
        string last_name = Chronology(year, m_lastName);
        if (name == "" /*&& last_name == ""*/) {
            return "Incognito";
        }
        if (name != "" /*&& last_name == ""*/) {
            return name + " with unknown last name";
        }
        if (last_name != "" /*&& name == ""*/) {
            return last_name + " with unknown first name";
        } else {
            return name + " " + last_name;
        }


        /*if(chronology != ){

        }*/

        return name + " " + last_name;
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

    // пробежаться по map и проверить
    string Chronology(int year, map<int, string>& m) {
        string s; /*= Checker(year, m); // это последнее имя*/

        /*string s1;
        map<int, string> result;*/
        for(auto it : m){
            if(year <= it.first){
                /*result.insert(it);*/
                s = it.second;
            }
        }
        /*for(auto it1 : result){
            if (s != it1.second) {
                s1 = it1.second;
            }
        } return s1;*/

    }

};


int main() {
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");

    cout << person.GetFullName(1940) << endl;
    cout << person.GetFullNameWithHistory(1900) << endl;

    return 0;
}
