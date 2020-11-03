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
        data.insert(std::make_pair(year,first_name));
    }
    void ChangeLastName (int year, const string& last_name){
        data.insert(std::make_pair(year,last_name));
    }
    string GetFullName (int year){

        for(auto it = data.begin(); it != data.end(); ++it){
            cout << it->first << " " << it->second << " ";
        }
    }
private:
    map<int, string> data;
    string s;
};


int main() {

    Person person;
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
    }

    return 0;
}
