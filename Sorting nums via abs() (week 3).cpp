#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;

bool ModulationCompare (const int& a, const int& b){
    if(abs(a) < abs(b)){
        return true;
    }
    return false;
}
void Sorting (vector<int>& v){
    // simple sort
    sort(v.begin(), v.end(), ModulationCompare);

    // lambda function
    sort(v.begin(), v.end(), [] (int a, int b){
       if (abs(a) < abs(b)){
           return true;
       }
        return false;
    });

    // via std::greater() == ">" without abs
    sort(v.begin(), v.end(), std::greater());
}

int main() {

    int q;
    cin >> q;
    vector<int> nums;
    for(int i = 0; i < q; ++i){
        int amount;
        cin >> amount;
        nums.push_back(amount);
        Sorting(nums);
    }
    for(auto i : nums){
        cout << i << " ";
    }

    return 0;
}
