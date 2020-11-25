#include <cassert>
#include <iostream>
#include <string>
#include <set>
#include <map>

using std::map;
using std::set;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using SynonymWords = map<string, set<string>>;


class SynonymsTable {
public:
    SynonymWords synonymWords;

    void AddSynonym(SynonymWords, const string &w1, const string &w2) {
        synonymWords[w1].insert(w2);
        synonymWords[w1].insert(w1);
    }

    int GetSynonymsCount(map<string, set<string>> m, const string &w) {
        return synonymWords[w].size();
    }

    bool SynonymsChecking(const string &w1, const string &w2) {
        if (synonymWords[w1].count(w2) == 1) {
            return true;
        }
        return false;
    }

    void Test() {
        {
            map<string, set<string>> empty;
            AddSynonym("a", "b");
            map<string, set<string>> expected = {
                    {"a", {"b"}},
                    {"b", {"a"}}
            };
            assert(empty == expected);
            cout << "TEST: OK" << endl;
        }
        {
            map<string, set<string>> synonymsCheck = {
                    {"a", {"b"}},
                    {"b", {"a", "c"}},
                    {"c", {"b"}}
            };
            AddSynonym(synonymsCheck, "a", "c");
        }
    }
};

int main(){

    SynonymsTable synonymsTable;

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; ++i){
        string command;
        cin >> command;
        if(command == "ADD"){
            string word1, word2;
            cin >> word1 >> word2;
            synonymsTable.AddSynonym(word1, word2);

        }
        if(command == "COUNT"){
            string word;
            cin >> word;
            cout << synonymsTable.GetSynonymsCount(word) << endl;
        }
        if(command == "CHECK"){
            string word1, word2;
            cin >> word1 >> word2;
            if(synonymsTable.SynonymsChecking(word1, word2)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}