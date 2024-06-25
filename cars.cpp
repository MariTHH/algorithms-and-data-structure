#include <iostream>
#include <set>
#include <list>
#include <queue>


struct Car {
    int id;
    int id_next;

    bool operator<(const Car& other) const {
        return id_next > other.id_next;
    }
};

int main() {
    int n, k, p, operations = 0;
    std::cin >> n >> k >> p;

    int cars[p];
    std::queue<int> indexes[n + 1];
    std::set<Car> floor;

    for (int i = 0; i < p; i++) {
        int car;
        std::cin >> car;
        indexes[car].push(i);
        cars[i] = car;
    }

    for (int i : cars) {
        Car car_n = {i, indexes[i].front()};
        indexes[i].pop();

        auto car = floor.find(car_n);
        //int test = indexes[i].empty() ? 500007 : indexes[i].front();
        if (car != floor.end()) {
            auto new_car = *car;
            new_car.id_next = indexes[i].empty() ? 500007 : indexes[i].front();
            floor.erase(car);
            floor.insert(new_car);
            continue;
        }
        operations++;
        if (static_cast<int>(floor.size()) == k) {
            floor.erase(floor.begin());
        }
        floor.insert({i, indexes[i].empty() ? 500007 : indexes[i].front()});
    }

    std::cout << operations;

    return 0;
}
