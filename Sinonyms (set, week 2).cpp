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

void AddSynonym(SynonymWords& synonymWords, const string& w1, const string& w2) {
    synonymWords[w1].insert(w2);
    synonymWords[w2].insert(w1); // synonymWords[w1].insert(w1); - for error modulating
}

int GetSynonymsCount(SynonymWords& synonymWords, const string& w) {
    return synonymWords[w].size();
}

bool SynonymsChecking(SynonymWords& synonymWords, const string& w1, const string& w2) {
    return synonymWords[w1].count(w2) == 1;
}

/*void TestAddSynonym() {
    {
        map<string, set<string>> empty;
        AddSynonym(empty,"a", "b");
        map<string, set<string>> expected = {
                {"a", {"b"}},
                {"b", {"a"}}
        };
        assert(empty == expected);
    }
    cout << "Add Syn TEST-1: OK" << endl;
    {
        SynonymWords synonyms = {
                {"a", {"b"}},
                {"b", {"a", "c"}},
                {"c", {"b"}}
        };
        AddSynonym(synonyms, "a", "c");
        const SynonymWords expected = {
                {"a",{"b", "c"}},
                {"b",{"a", "c"}},
                {"c",{"a", "b"}}
        };
        assert(synonyms == expected);
    }
    cout << "Add syn TEST-2: OK" << endl;
}

void TestGetCount(){
    {
        map<string, set<string>> empty;
        assert(GetSynonymsCount(empty, "a") == 0);
    }
    cout << "Get Syn Test-1: OK"<< endl;
    {
        map<string, set<string>> synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}},
        };
        assert(GetSynonymsCount(synonyms, "a") == 2);
        assert(GetSynonymsCount(synonyms, "b") == 1);
        assert(GetSynonymsCount(synonyms, "c") == 1);
        assert(GetSynonymsCount(synonyms, "g") == 0);
    }
    cout << "Get Syn Count TEST-2: OK"<< endl;
}

void TestSynonymCheck(){
    {
        map<string, set<string>> empty;
        assert(!SynonymsChecking(empty, "a", "b"));
        assert(!SynonymsChecking(empty, "b", "a"));
    }
    cout << "Syn Check TEST-1: OK"<< endl;
    {
        SynonymWords synonym = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        assert(SynonymsChecking(synonym, "a", "b"));
        assert(SynonymsChecking(synonym, "a", "c"));
        assert(SynonymsChecking(synonym, "b", "a"));
        assert(SynonymsChecking(synonym, "c", "a"));
        assert(!SynonymsChecking(synonym, "c", "b"));
    }
    cout << "Syn Check TEST-2: OK"<< endl;
}

void TestAll(){
    TestAddSynonym();
    TestGetCount();
    TestSynonymCheck();
}*/

int main(){

    /*TestAll();
    return 0;*/

    int Q;
    cin >> Q;
    SynonymWords synonymm;

    for(int i = 0; i < Q; ++i){
        string command;
        cin >> command;
        if(command == "ADD"){
            string word1, word2;
            cin >> word1 >> word2;
            AddSynonym(synonymm,word1, word2);

        }
        if(command == "COUNT"){
            string word;
            cin >> word;
            cout << GetSynonymsCount(synonymm, word) << endl;
        }
        if(command == "CHECK"){
            string word1, word2;
            cin >> word1 >> word2;
            if(SynonymsChecking(synonymm, word1, word2)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
