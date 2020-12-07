#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <exception>

using std::exception;
using std::vector;
using std::string;

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::setw;
using std::setfill;
using std::getline;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::ios;


struct Date {
    int day;
    int month;
    int year;
};

void EnsureNextSymbolAndSkip(stringstream& stream){
    if(stream.peek() != '/'){           // stream.peek() - method shows that symbol going next in the stream
        stringstream ss;                //       .peek() - method for streams (для потоков)
        ss << "expected '/', but has: " << char(stream.peek()); // char(stream.peek()) - преобразование к символьному
                                                                // отображению char( число )
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

Date ParseDate(const string& str){
    stringstream stream(str);
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.month;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;
};


int main(){

    /*string date_str = "2017/01/07"; // normal  */
    string date_str = "2017a01b07"; // with exceptions
    try {
        Date date = ParseDate(date_str);
        cout << setw(2) << setfill('0') << date.day << "."    // setw(2) - size of field "day" - 01, not 1
             << setw(2) << setfill('0') << date.month << "."  // setw(2) - size of field "day" - 01, not 1
             << date.year << endl;
    }
    catch (exception& ex){
        cout << "exception happens: " << ex.what(); // exception.what() - если в сообщении что-то есть,
                                                  //то текст будет возвращен (текст, что содержится в EnsureNext...> ss)
    }
    return 0;
}

