#include <iostream>
#include <vector>
#include <map>
#include <list>

using std::list;
using std::cin;
using std::pair;
using std::cout;
using std::endl;

list<int> TestCountsAdding (int n){
    list<int> listName;
    for (int i = 0; i < n; ++i) {
        int nums;
        cin >> nums;
        listName.push_back(nums);
    }
    return listName;
}

void ListPrinter (list<int>& listName) {
    for(auto it = listName.begin(); it != listName.end(); ++it){
        cout << *it << " ";
    }
}

int MiddleSum (list<int>& listName){
    int sum = 0;
    for(auto it = listName.begin(); it != listName.end(); ++it){
        sum += *it;
    }
    int middleSum = sum / listName.size();
    return middleSum;
}

int main() {

    int comandQuantity;
    cin >> comandQuantity;

    list<int> testList = TestCountsAdding(comandQuantity);


    auto it_max = testList.begin();
    auto it_min = testList.begin();
    for (auto it = testList.begin(); it != testList.end(); ++it) {

        if (*it_max < *it) {
            it_max = it;
        }
        if (*it_min > *it) {
            it_min = it;
        }
    }
    ListPrinter(testList);
    int middleSum = MiddleSum(testList);

    int saved_it_min = *it_min;

    cout << "\nlist max: " << *it_max << "\nlist min: " << saved_it_min << endl;
    cout << "middle sum: " << middleSum << endl;

    testList.erase(it_min);
    testList.insert(++it_max, saved_it_min);
    ListPrinter(testList);

    return 0;
}