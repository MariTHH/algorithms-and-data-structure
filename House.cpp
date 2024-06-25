#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, k, a_prev = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int afterIncubation = a * b;
        if (afterIncubation > c){
            int afterExperiment = afterIncubation - c;
            if (afterExperiment >= d){
                a = d;
                break;
            } else {
                if (afterExperiment == a_prev){
                    break;
                }
                a_prev = a;
                a = afterExperiment;
            }
        } else {
            a = 0;
            break;
        }
    }

    cout << a;
}