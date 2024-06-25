#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>

using namespace std;

class Scheduler {
private:
    struct Operation {
        int size;
        int index;

        Operation(int size, int index) : size(size), index(index) {}
    };

    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    vector<Operation> operations;
    multiset<int> emptySlots;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> opQueue;

public:
    Scheduler() {}

    void processOppositeValue(int negativeValue) {
        negativeValue = abs(negativeValue);

        operations.emplace_back(0, 0);
        auto &currentOp = operations[negativeValue - 1];

        if (currentOp.size != 0) {
            emptySlots.emplace(currentOp.index);
            emptySlots.emplace(currentOp.index + currentOp.size - 1);

            auto it1 = emptySlots.find(currentOp.index - 1);
            auto it3 = emptySlots.find(currentOp.index);

            if (it1 != emptySlots.end()) {
                emptySlots.erase(it1);
                emptySlots.erase(it3);
            }

            auto it2 = emptySlots.find(currentOp.index + currentOp.size);
            auto it4 = emptySlots.find(currentOp.index + currentOp.size - 1);

            if (it2 != emptySlots.end()) {
                emptySlots.erase(it2);
                emptySlots.erase(it4);
            }

            auto add = emptySlots.lower_bound(currentOp.index);
            if (*add != currentOp.index) {
                int right = *add;
                --add;
                opQueue.emplace(right - *add + 1, *add);
            } else {
                int left = *add;
                ++add;
                opQueue.emplace(*add - left + 1, left);
            }

            currentOp.size = 0;
        }
    }


    void processPositiveValue(int positiveValue, int totalSize) {
        auto front = opQueue.top();
        opQueue.pop();
        auto add = emptySlots.lower_bound(front.second);
        int upper = totalSize;

        if (add != emptySlots.end() && ++add != emptySlots.end()) {
            upper = *add;
        }

        while ((emptySlots.find(front.second) == emptySlots.end() || upper - front.second + 1 != front.first) && !opQueue.empty()) {
            front = opQueue.top();
            opQueue.pop();
            upper = totalSize;
            add = emptySlots.lower_bound(front.second);

            if (add != emptySlots.end() && ++add != emptySlots.end()) {
                upper = *add;
            }
        }

        bool isValid = (front.first >= positiveValue) && (emptySlots.find(front.second) != emptySlots.end()) && (upper - front.second + 1 == front.first);

        if (isValid) {
            cout << front.second << endl;
            operations.emplace_back(positiveValue, front.second);
            emptySlots.erase(front.second);

            if (front.first != positiveValue) {
                emptySlots.insert(front.second + positiveValue);
            } else {
                emptySlots.erase(front.second + positiveValue - 1);
            }

            opQueue.emplace(front.first - positiveValue, front.second + positiveValue);
        } else {
            cout << -1 << endl;
            operations.emplace_back(0, 0);
            opQueue.push(front);
        }
    }


    void runScheduler() {
        int totalSize, totalOps;
        cin >> totalSize >> totalOps;

        if (totalSize <= 0 || totalOps <= 0) {
            cout << "Invalid input. Sizes and operations must be positive integers." << endl;
            return;
        }

        opQueue.emplace(totalSize, 1);
        emptySlots.insert(1);
        emptySlots.insert(totalSize);

        for (int i = 0; i < totalOps; ++i) {
            int currentOp;
            cin >> currentOp;

            if (currentOp <= 0) {
                processOppositeValue(currentOp);
            } else {
                processPositiveValue(currentOp, totalSize);
            }
        }
    }
};

int main() {
    Scheduler scheduler;
    scheduler.runScheduler();

    return 0;
}