#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;


class Person{
public:

    void ChangeFirstName (int year, const string& first_name){
        auto it = m_firstName.find(year);
        if(it != m_firstName.end()){ // условие означает, что элемент в map ЕСТЬ и повторяется (.end() - указывает ЗА ПОСЛЕДНИЙ элемент map)
            cout << "error, first name on this year already exist" << endl;
            return;
        }
        m_firstName[year] = first_name;
    }
    void ChangeLastName (int year, const string& last_name){
        auto it = m_lastName.find(year);
        if(it != m_lastName.end()){
            cout << "error, last name on this year already exist" << endl;
            return;
        }
        m_lastName[year] = last_name;
    }
    string GetFullName (int year){
        string name = Checker(year, m_firstName);
        string last_name = Checker(year, m_lastName);

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

        if(name == "" && last_name == ""){
            return "Incognito";
        }
        if(name != "" && last_name == ""){
            return name + " with unknown last name";
        }
        if(last_name != "" && name == ""){
            return last_name + " with unknown first name";
        }
        else{
            return name + " " + last_name;
        }
    }
private:
    map<int,string> m_firstName;
    map<int,string> m_lastName;

    string Checker(int year, map<int, string>& m ){
        string s = "";
        for(auto it : m){
            if(year >= it.first){
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
    for(int year : {1900, 1966, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for(int year : {1969, 1970}){
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for(int year : {1969, 1970}){
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

