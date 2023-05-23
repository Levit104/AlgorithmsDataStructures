#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, k;
    vector<int> numbers;

    fin >> n >> k;

    int number;
//    for (int i = 0; i < n; i++) {
//        fin >> number;
//        numbers.push_back(number);
//    }
    while (fin >> number) {
        numbers.push_back(number);
    }

//    for (auto it = numbers.begin(); it != numbers.end() - k + 1; it++) {
//        int minValue = *min_element(it, it + k);
//        fout << minValue << " ";
//    }

    int minValue, minIndex = -666;
    for (int beginIndex = 0; beginIndex < n - k + 1; beginIndex++) {
        int endIndex = beginIndex + k - 1;
        int beginValue = numbers[beginIndex];
        int endValue = numbers[endIndex];

        if (minIndex < beginIndex) {
            minValue = beginValue;
            for (int newMinIndex = beginIndex; newMinIndex < endIndex + 1; newMinIndex++) {
                int newMinValue = numbers[newMinIndex];
                if (newMinValue <= minValue) {
                    minValue = newMinValue;
                    minIndex = newMinIndex;
                }
            }
        } else if (endValue <= minValue) {
            minValue = endValue;
            minIndex = endIndex;
        }
        fout << minValue << " ";
    }

    return 0;
}
