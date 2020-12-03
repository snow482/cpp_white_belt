#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;
/*using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;*/


struct Duration{
    int hour;
    int min;

    Duration(int h = 0, int m = 0){
        int total_time = h * 60 + m;
        hour = total_time / 60;
        min = total_time % 60 ;
    }
};

// ----------------------------------------------------------------------------------
// function for cin without overloading operators (with the same function body)
/*Duration ReadDuration (istream& stream){
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration {h, m};
}*/
// ----------------------------------------------------------------------------------
// creating overload operator ">>"
// by scheme " istream& operator >> (istream& stream, Obj& obj)
istream& operator >> (istream& stream, Duration& duration){
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream; // returning the stream reference - is very important!!!!
}

// ----------------------------------------------------------------------------------
// function for cout without overloading operators (with the same function body)
/*void PrintDuration(ostream& stream, const Duration& duration){
    stream << setfill('0'); //
    stream << setw(2) << duration.hour << ':';
    stream << setw(2) << duration.min;
}*/
// ----------------------------------------------------------------------------------

ostream& operator << (ostream& stream, const Duration& duration){
    stream << setfill('0'); //
    stream << setw(2) << duration.hour << ':';
    stream << setw(2) << duration.min;
    return stream; // returning the stream reference - is very important!!!!
}

Duration operator + (const Duration& lhs, const Duration& rhs){
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

int main(){

    stringstream dur_ss("13:14");
    /*Duration dur1 = ReadDuration(dur_ss);*/
    Duration dur1; // constructor for default time adding
    dur_ss >> dur1;
    Duration dur2  = {0, 47};
    /*PrintDuration(cout, dur1);*/ // without overloading operators
    cout << dur1 + dur2 << endl;
    cout << dur1 << endl;
    cout << dur1 << endl;
    //operator<<(operator<<(cout, "hello "), "world");


}