#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

string getFromFile() {
    fstream file;
    file.open("t.txt");

    string s;
    getline(file, s);

    file.close();

    return s;
}

vector<string> splitString(string& str) {
    vector<string> v;

    int last = 0;
    int found = str.find_first_of(" ,?!.");
    int n = 0;

    while (found != string::npos) {
        
        if (str.substr(last, found - last) != "") {
            string newstr = str.substr(last, found - last);
            for (auto& c : newstr)
                c = tolower(c);
            v.push_back(newstr);
        }
       
        last = found+1;
        found = str.find_first_of(" ,?!.", found+1);
    }
    cout << "\n";

    return v;
}

map<string, int> generateMap(vector<string>& v) {
    map<string, int> to_return;

    for (string s : v) {
        if (to_return[s] >= 0)
            to_return[s]++;
        //to_return[s] = 0;
    }

    return to_return;
}


priority_queue<map<int, string>> getSortedQueue(map<string, int>& m) {
    priority_queue<map<int, string>> q;

    for (const auto& [key, value] : m) {
        map<int, string> rev_map;
        rev_map[value] = key;
        q.push(rev_map);
    }

    return q;
}

class Compare {
public:
    bool operator() (pair<string, int> p1, pair<string, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;
        if (p1.first < p2.first)
            return false;
        return true;
    }
};

class CompareInv {
public:
    bool operator() (pair<string, int> p1, pair<string, int> p2) {
        if (p1.second > p2.second)
            return true;
        if (p1.second < p2.second)
            return false;
        if (p1.first > p2.first)
            return false;
        return true;
    }
};

int main(){
    //while (NULL) cout << "2";
    
    string str = getFromFile();
    cout << str <<endl;

    vector<string> v = splitString(str);

    map<string, int> word_count = generateMap(v);

    //for (int i=0;i<v.size();i++)
    //    cout << v[i] << "\n";

    for (const auto& [key, value] : word_count)
        cout << '[' << key << "] = " << value << "; " << endl;
    
    cout << endl;

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> sortedQueue;

    for (auto mapIterator = word_count.begin(); mapIterator != word_count.end(); mapIterator++) {
        sortedQueue.push(pair<string, int>(mapIterator->first, mapIterator->second));
    }
    //priority_queue<map<int, string>> q = getSortedQueue(word_count);

    while (!sortedQueue.empty()) {
        cout << sortedQueue.top().first << " => " << sortedQueue.top().second << endl;
        sortedQueue.pop();
    }
    
}
