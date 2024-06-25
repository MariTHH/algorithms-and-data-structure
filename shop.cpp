#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    std::sort(prices.begin(), prices.end());

    long long final = 0;
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % k != 0) {
            final += prices[i];
        }
    }

    std::cout << final << std::endl;

    return 0;
}
