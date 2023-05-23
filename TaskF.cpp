#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    vector<string> numbers;

    ifstream fin("number.in");
    ofstream fout("number.out");

    string inputData;
    while (fin >> inputData) {
        numbers.push_back(inputData);
    }

    sort(numbers.begin(), numbers.end(), [](const string &a, const string &b) {
        return a + b > b + a;
    });

    for (string &number: numbers) {
        fout << number;
    }

    fin.close();
    fout.close();

    return 0;
}
