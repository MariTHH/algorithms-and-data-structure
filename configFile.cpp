#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

int main() {
    unordered_map<string, int> variables;
    stack<unordered_map<string, int*>> changesStack;

    string line;
    while (cin >> line) {
        if (line == "{") {
            changesStack.push({});
        } else if (line == "}") {
            for (auto& change : changesStack.top()) {
                if (change.second == nullptr) {
                    variables.erase(change.first);
                } else {
                    variables[change.first] = *change.second;
                }
            }
            changesStack.pop();
        } else {
            size_t equalsPos = line.find('=');
            string var1 = line.substr(0, equalsPos);
            string var2 = line.substr(equalsPos + 1);

            if (!changesStack.empty() && changesStack.top().find(var1) == changesStack.top().end()) {
                changesStack.top()[var1] = variables.find(var1) != variables.end() ? new int(variables[var1]) : nullptr;
            }

            if (isdigit(var2[0]) || (var2[0] == '-' && isdigit(var2[1]))) {
                variables[var1] = stoi(var2);
            } else {
                int value = variables[var2];
                cout << value << endl;
                variables[var1] = value;
            }
        }
    }

    return 0;
}