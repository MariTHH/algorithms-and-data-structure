#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

void trapAnimals() {
    string s;
    cin >> s;
    int j = 1;
    stack<char> st;
    unordered_map<char, vector<int>> mp;

    for (int i = 0; i < s.size(); ++i) {
        if (islower(s[i])){
            mp[s[i]].push_back(j);
            j++;
        }
        if (!st.empty() && tolower(st.top()) == tolower(s[i])) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    if (st.empty()) {
        cout << "Possible" << endl;
        for (int i = 0; i < s.size(); ++i) {
            if(isupper(s[i])){
                vector<int> indices = mp[tolower(s[i])];
                cout << indices.back() << " ";
                indices.pop_back();
                mp[tolower(s[i])] = indices;
            }
        }
    } else {
        cout << "Impossible" << endl;
    }
}

int main() {
    trapAnimals();
    return 0;
}

