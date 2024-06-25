#include <iostream>
#include <vector>
#include <algorithm>

void bubbleSort(std::string& str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] < str[j + 1]) {
                std::swap(str[j], str[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<std::string> numbers;
    std::string line, combinedString;

    while (std::getline(std::cin, line) && !line.empty()) {
        numbers.push_back(line);
    }

    for (const std::string& num : numbers) {
        combinedString += num;
    }

    bubbleSort(combinedString);

    std::cout << "Отсортированная строка: " << combinedString << "\n";

    return 0;
}
