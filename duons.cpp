#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

const int a = 0;
const int b = 1;
const int c = 2;
const int d = 3;
const int e = 4;
const int f = 5;
const int g = 6;
const int h = 7;

const char add = '+';
const char del = '-';

string op(char o, int i, int j) {
    char a = 'a' + i;
    char b = 'a' + j;
    return string(1, a) + string(1, b) + string(1, o);
}

deque<string> solve(vector<int>& m) {
    deque<string> ans;

    while (m[a] > 0 && m[b] > 0) {
        m[a]--; m[b]--;
        ans.push_back(op(del, a, b));
    }

    while (m[a] > 0 && m[d] > 0) {
        m[a]--; m[d]--;
        ans.push_back(op(del, a, d));
    }

    while (m[a] > 0 && m[e] > 0) {
        m[a]--; m[e]--;
        ans.push_back(op(del, a, e));
    }

    while (m[a] > 0) {
        m[a]--; m[b]--;
        ans.push_back(op(del, a, b));

        if (m[b] < 0) {
            m[b]++; m[c]++;
            ans.push_front(op(add, b, c));
        }
    }

    while (m[b] > 0) {
        m[b]--; m[c]--;
        ans.push_back(op(del, b, c));

        if (m[c] < 0) {
            m[c]++; m[g]++;
            ans.push_front(op(add, c, g));
        }
    }

    while (m[d] > 0) {
        m[d]--; m[h]--;
        ans.push_back(op(del, d, h));

        if (m[h] < 0) {
            m[h]++; m[g]++;
            ans.push_front(op(add, h, g));
        }
    }

    while (m[e] > 0) {
        m[e]--; m[f]--;
        ans.push_back(op(del, e, f));

        if (m[f] < 0) {
            m[f]++; m[g]++;
            ans.push_front(op(add, f, g));
        }
    }

    while (m[c] > 0) {
        m[c]--; m[g]--;
        ans.push_back(op(del, c, g));
    }

    while (m[h] > 0) {
        m[h]--; m[g]--;
        ans.push_back(op(del, h, g));
    }

    while (m[f] > 0) {
        m[f]--; m[g]--;
        ans.push_back(op(del, f, g));
    }

    if (m[g] == 0) {
        return ans;
    } else {
        return {};
    }
}

int main() {
    vector<int> m;
    string line;
    getline(cin, line);
    istringstream iss(line);

    int num;
    while (iss >> num) {
        m.push_back(num);
    }

    deque<string> ans = solve(m);
    if (ans.empty()) {
        cout << "impossible" << endl;
    } else {
        for (const string& s : ans) {
            cout << s << endl;
        }
    }

    return 0;
}
