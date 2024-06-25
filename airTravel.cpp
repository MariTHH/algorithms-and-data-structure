#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

struct Vertex {
    bool isVisited = false;
};

class Flight {
private:
    vector<Vertex> vertices;
    int **fuel_matrix;
    int num_vertices;

public:
    Flight(int n) : num_vertices(n) {
        vertices.resize(num_vertices);
        fuel_matrix = new int *[num_vertices];
        for (int i = 0; i < num_vertices; ++i) {
            fuel_matrix[i] = new int[num_vertices];
        }
    }

    ~Flight() {
        for (int i = 0; i < num_vertices; ++i) {
            delete[] fuel_matrix[i];
        }
        delete[] fuel_matrix;
    }

    void setFuelM() {
        int min_fuel = INT_MAX;
        int max_fuel = 0;

        for (int i = 0; i < num_vertices; ++i) {
            for (int j = 0; j < num_vertices; ++j) {
                cin >> fuel_matrix[i][j];

                if (i != j) {
                    min_fuel = min(min_fuel, fuel_matrix[i][j]);
                    max_fuel = max(max_fuel, fuel_matrix[i][j]);
                }
            }
        }

        findOptimalFuelTankSize(min_fuel, max_fuel);
    }

    int flying(int start_index, int fuel, bool swap_indexes) {
        int result = 1;
        vertices[start_index].isVisited = true;

        for (int i = 0; i < num_vertices; ++i) {
            int needed_fuel = swap_indexes ? fuel_matrix[start_index][i] : fuel_matrix[i][start_index];
            if (i != start_index && needed_fuel <= fuel && !vertices[i].isVisited) {
                result += flying(i, fuel, swap_indexes);
            }
        }

        return result;
    }

    void findOptimalFuelTankSize(int min_fuel, int max_fuel) {
        int l = min_fuel, r = max_fuel, mid;

        do {
            mid = l + (r - l) / 2;

            for (auto &vertex : vertices) {
                vertex.isVisited = false;
            }

            int result = flying(0, mid, false);

            for (auto &vertex : vertices) {
                vertex.isVisited = false;
            }

            result += flying(0, mid, true);

            if (result == 2 * num_vertices) {
                r = mid;
            } else {
                l = mid + 1;
            }
        } while (r > l);

        if (num_vertices == 1) {
            cout << 0 << endl;
        } else {
            cout << l << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    Flight flightGraph(n);
    flightGraph.setFuelM();

    return 0;
}
