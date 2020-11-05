#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;

struct IdentificationData{
    string first_name;
    string last_name;

};

map<int, IdentificationData>::iterator LinearFinding(int key, map<int, IdentificationData>& m){
    for(auto it = m.begin(); it != m.end(); ++it){
        if(key == it->first){
            return it;
        }
    }
}

class Person{
public:

    void ChangeFirstName (int year, const string& first_name){
        IdentificationData temp;

        /*LinearFinding(year, temp);*/

        temp.first_name = first_name;
        temp.last_name = "";

        data.insert(std::make_pair(year,temp));

    }
    void ChangeLastName (int year, const string& last_name){
        IdentificationData temp;
        /*temp.first_name = "";*/
        temp.last_name = last_name;

        data.insert(std::make_pair(year,temp));
    }
    string GetFullName (int year){

        auto it = data.find(year);
        s = it->second.first_name + " " + it->second.last_name;




        /*
        for(auto it = data.begin(); it != data.end(); ++it){
            if(year == it->first){
                cout << it->first << " " << it->second.first_name <<  it->second.last_name << endl;
            }
        }*/
        return s;

    }
private:
    map<int, IdentificationData> data;
    string s;

};


int main() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "APolina");
    person.ChangeLastName(1967, "Sergeeva");

    cout << person.GetFullName(1965) << endl;

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
