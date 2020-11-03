#include <iostream>
#include <vector>
#include <list>

using std::list;
using std::cin;
using std::cout;
using std::endl;


list<int> ListRead (int n){
    list<int> nums;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        nums.push_back(data);
    }
    return nums;
}

int MiddleArifmetic (list<int>& nums){
    int sum = 0;

    for (auto it = nums.begin(); it != nums.end(); ++it) {
        sum += *it;
    }
    int middle_sum = sum / nums.size();
    return middle_sum;
}

void ListPrinter (const list<int>& list_name){
    for(auto it = list_name.cbegin(); it != list_name.cend(); ++it){
        cout << *it << " ";
    }
}
int main() {

    int itemQuantity;
    cin >> itemQuantity;
    list<int> nums = ListRead(itemQuantity);

    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    auto it_max = nums.begin();
    auto it_min = nums.begin();
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        if (*it_max < *it) {
            it_max = it;
        }
        if (*it_min > *it) {
            it_min = it;
        }
    }

    int middle_sum = MiddleArifmetic(nums);
    auto it_saved = *it_min;

    cout << *it_max << endl;
    cout << it_saved << endl;
    cout << middle_sum << endl;

    nums.erase(it_min);
    nums.insert(++it_max, it_saved);
    ListPrinter(nums);

    return 0;
}