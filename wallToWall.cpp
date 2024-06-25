#include <iostream>
#include <vector>

using namespace std;

int calculate(int n, int k) {
    vector<int> teamSizes(k, 0);

    for (int i = 0; i < n; i++) {
        int minTeamIndex = 0;
        for (int j = 1; j < k; j++) {
            if (teamSizes[j] < teamSizes[minTeamIndex]) {
                minTeamIndex = j;
            }
        }

        teamSizes[minTeamIndex]++;
    }

    int totalFights = 0;

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            totalFights += teamSizes[i] * teamSizes[j];
        }
    }

    return totalFights;
}

int main() {
    int T;
    cin >> T;

    for (int q = 0; q < T; q++) {
        int n, k;
        cin >> n >> k;

        cout << calculate(n, k) << endl;
    }

    return 0;
}
