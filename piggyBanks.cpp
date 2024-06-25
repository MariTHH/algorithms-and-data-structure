#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> keys;
    vector<vector<int>> grph(n + 1);
    unordered_set<int> used;

    for (int i = 1; i <= n; ++i) {
        int key;
        cin >> key;
        keys[i] = key;

        grph[key].push_back(i);
        grph[i].push_back(key);
    }

    int num = 0;

    for (int i = 1; i <= n; ++i) {
        if (used.find(i) == used.end()) {
            vector<int> stack;
            stack.push_back(i);

            while (!stack.empty()) {
                int v = stack.back();
                stack.pop_back();

                if (used.find(v) == used.end()) {
                    used.insert(v);

                    for (int j : grph[v]) {
                        if (used.find(j) == used.end()) {
                            stack.push_back(j);
                        }
                    }
                }
            }

            num++;
        }
    }

    cout << num << endl;

    return 0;
}
