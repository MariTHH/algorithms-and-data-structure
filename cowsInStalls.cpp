#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);

    for (int i = 0; i < n; ++i) {
        cin >> stalls[i];
    }
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    int distance = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int placedCows = 1;
        int lastPlaced = stalls[0];

        for (int i = 1; i < stalls.size(); ++i) {
            if (stalls[i] - lastPlaced >= mid) {
                placedCows++;
                lastPlaced = stalls[i];
            }
        }
        if (placedCows >= k) {
            distance = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }

    cout << distance << endl;

    return 0;
}