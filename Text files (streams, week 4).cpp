#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>

using std::getline;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;    // for reading (successor from - istream)
using std::ofstream;    // ofstream - for writing (successor from - ostream)
using std::ostream;
using std::ios;         // режим допзаписи

// fstream - for reading/writing (successor from - iostream)
// getline() - for reading from stream

void ReadAllFile (const string& way){
    ifstream input(way);
    if(input){
        string line;
        while (getline(input, line)){
            cout << line << endl;
        };
    }
}


int main(){
   string way = "C:/git/output.txt";
   ofstream output(way, ios::app);      // if add "way, ios::app" - old text will not change (app - append)
   output << "One Ring to bring them all, and in the darkness bind them";
   ReadAllFile(way);

/*"One Ring to rule them all, One Ring to find them,
 * One Ring to bring them all, and in the darkness bind them"*/

// --------------------------------------------------------------------------------------
    /*ifstream input ("C:/git/date.txt");
    int day;
    int month;
    int year;

    if(input) {
        *//*getline(input, year, '.');
        getline(input, month, '.');
        getline(input, day, '.');*//*
        input >> year;
        input.ignore(1);
        input >> month;
        input.ignore(1);
        input >> day;
    }
    cout << day << "." << month << "." << year << endl;*/
// --------------------------------------------------------------------------------------
    /*ifstream input("C:/git/The Lord of the Rings.txt");    // way to file path
    string line;
    *//*getline(input, line); *//*                             // taking string from the file
    // file streams can be bool and we can change just for - if(input) {..}
    if(input.is_open()){
        while(getline(input, line)){
            cout << line << endl;
        }
    }else {
        cout << "wrong path or file name" << endl;
    }*/

    return 0;
}