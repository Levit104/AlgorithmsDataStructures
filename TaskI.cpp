#include <fstream>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, k, p;
    fin >> n >> k >> p;

    vector<queue<int>> indexes(n);
    vector<int> carsOrder(p);
    for (int i = 0; i < p; i++) {
        fin >> carsOrder[i];
        indexes[--carsOrder[i]].push(i);
    }

    int actionsCount = 0;
    int const MAX_CONST = 500001;
    unordered_set<int> carsOnFloor;
    priority_queue<pair<int, int>> cars;

    for (int currentCar: carsOrder) {
        if (carsOnFloor.find(currentCar) == carsOnFloor.end()) {
            if (carsOnFloor.size() >= k) {
                carsOnFloor.erase(cars.top().second);
                cars.pop();
            }

            carsOnFloor.insert(currentCar);
            actionsCount++;
        }

        indexes[currentCar].pop();
        if (indexes[currentCar].empty()) {
            cars.emplace(MAX_CONST, currentCar);
        } else {
            cars.emplace(indexes[currentCar].front(), currentCar);
        }
    }

    fout << actionsCount << endl;

    fin.close();
    fout.close();

    return 0;
}
