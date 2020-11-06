#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;

/*
struct IdentificationData{
    string first_name;
    string last_name;
    bool firstNameChanging = false;
    bool lastNameChanging = false;

};
*/





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
        // via lower_bound
        auto it_firstName = m_firstName.lower_bound(year);
        auto it_lastName = m_lastName.lower_bound(year);

        if(it_firstName == m_firstName.end() && it_lastName == m_lastName.end()){
            return "Incognito";
        }

        if(it_firstName == m_firstName.end()){
            return it_lastName->second + " with unknown first name";
        }

        if(it_lastName == m_lastName.end()){
            return it_firstName->second + " with unknown last name";
        }
        return it_firstName ->second + " " + it_lastName->second ;


        // via loop
        /*for(auto it = m_firstName.begin(); it != m_firstName.end(); ++it){
           -----
           cout << it->first << " " << it->second << endl;
        }*/


        // написать приватный метод,
        // 1) чекаем, пуст ли map (m.size()), если да, то - Incognito
        // 2) бежим по map и ищем искомый год, если года нет, для имени и фамилии выводим - Incognito
        // 3) бежим по map и ищем искомый год, если нет года и имени,то фамилию выводим -
        //
        // 3) бежим по map и ищем искомый год, если года нет, для имени и фамилии выводим map->second от предыдущего для



    }
private:
    /*map<int, IdentificationData> data;*/
    map<int,string> m_firstName;
    map<int,string> m_lastName;
};


int main() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1966, "APolina");
    person.ChangeLastName(1967, "Sergeeva");

    cout << person.GetFullName(1967) << endl;

   /* Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for(int year : {1900, 1966, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1970, "Appolinaria");
    for(int year : {1969, 1970}){
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for(int year : {1969, 1970}){
        cout << person.GetFullName(year) << endl;
    }*/

    return 0;
}
