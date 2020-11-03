#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <utility>

using std::list;
using std::string;
using std::cin;
using std::pair;
using std::cout;
using std::endl;



list<pair<int, string>> PairListRead (int n){
    pair<int, string> newPair;
    list<pair<int, string>> info;

    for (int i = 0; i < n; ++i) {
        int peopleQuantity;
        string city;
        cin >> peopleQuantity >> city;
        newPair.first = peopleQuantity;
        newPair.second = city;
        info.push_back(newPair);
    }
    return info;
}
// - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - - -
// function initialization without defining (see to the main() )

/*void func(list<pair<int,string>>& viaPair, std::function<void(int,string)> call){
    for (auto it = viaPair.begin(); it != viaPair.end(); ++it){
        call(it->first,it->second);
    }
}*/
// - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - - -

int MiddleSum (list<pair<int, string>>& testList){
    int sum = 0;
    for(auto it = testList.begin(); it != testList.end(); ++it){
        sum += it->first;
    }
    int middleSum = sum / testList.size();
    return middleSum;
}
void PairListPrinting(const list<pair<int, string>>& printedList){
    for (auto it = printedList.cbegin(); it != printedList.cend(); ++it){
        cout << "People quantity: " << it->first << "\nCity: " << it->second << endl;
    }
}

int main() {

    int commandQuantity;
    cin >> commandQuantity;
    list<pair<int, string>> viaPair = PairListRead(commandQuantity);

// - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - - -
// function definition in the main()

    /*func(viaPair,[](int f, string s){cout << f << " " << s << endl;});*/
// - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - - -

    PairListPrinting(viaPair);

    auto itMax = viaPair.begin();
    auto itMin = viaPair.begin();
    for(auto it = viaPair.begin(); it != viaPair.end(); ++it){
        if(itMax->first < it->first){
            itMax = it;
        }
        if(itMin->first > it->first){
            itMin = it;
        }
    }
    int middleSum = MiddleSum(viaPair);
    auto itMinSaved = *itMin; // saving itMin for adding after itMax
    // (! data types is "narrow" place)
    cout << "\nPeople quantity Min: " << itMin->first << endl;
    cout << "\nPeople quantity Max: " << itMax->first << endl;
    cout << "\nMiddle sum: " << middleSum << endl;

    // Deleting min value and adding the value after max value
    viaPair.erase(itMin);
    PairListPrinting(viaPair);
    viaPair.insert(++itMax, itMinSaved);
    PairListPrinting(viaPair);

    return 0;
}