#include <fstream>
#include <vector>

using namespace std;

bool allCanBePlaced(int &numberOfCows, vector<int> &stallsCoordinates, int &distance) {
    int previousCow = stallsCoordinates.front();
    int numberOfCowsPlaced = 1;

    for (int &stallsCoordinate : stallsCoordinates) {
        if (stallsCoordinate - previousCow >= distance) {
            numberOfCowsPlaced++;
            previousCow = stallsCoordinate;
        }
    }

    return numberOfCowsPlaced >= numberOfCows;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, k;
    vector<int> stallsCoordinates;

    fin >> n >> k;

    int stall;
    while (fin >> stall) {
        stallsCoordinates.push_back(stall);
    }

    int left = 1;
    int right = stallsCoordinates.back() - stallsCoordinates.front() + 1;

    while (left + 1 != right) {
        int distance = (left + right) / 2;

        if (allCanBePlaced(k, stallsCoordinates, distance)) {
            left = distance;
        } else {
            right = distance;
        }
    }

    fout << left << endl;

    fin.close();
    fout.close();

    return 0;
}