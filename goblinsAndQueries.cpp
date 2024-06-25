#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, t;
    char c;
    cin >> n;
    deque<int> simpleGoblins;
    deque<int> privilegedGoblins;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == '+') {
            cin >> t;
            simpleGoblins.push_back(t);
        } else if (c == '*') {
            cin >> t;
            if (simpleGoblins.size() != privilegedGoblins.size()) {
                simpleGoblins.push_front(t);
            } else {
                privilegedGoblins.push_back(t);
            }
        } else {
            if (!privilegedGoblins.empty()) {
                cout << privilegedGoblins.front() << endl;
                privilegedGoblins.pop_front();
            } else {
                cout << simpleGoblins.front() << endl;
                simpleGoblins.pop_front();
            }
        }
        if (simpleGoblins.size() > privilegedGoblins.size()) {
            privilegedGoblins.push_back(simpleGoblins.front());
            simpleGoblins.pop_front();
        }
    }
    return 0;
}
