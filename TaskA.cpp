#include <iostream>

using namespace std;

int main() {
    int arrayLength;
    cin >> arrayLength;

    int array[arrayLength];
    for (int i = 0; i < arrayLength; i++) {
        cin >> array[i];
    }

    int identicalCount = 1;

    int rowStart = 0;
    int rowEnd = 0;

    int currentRowStart = 0;
    int currentRowEnd = 0;

    for (int i = 0; i < arrayLength; i++) {
        int currentElement = array[i];
        int nextElement = array[i + 1];

//        currentRowStart = i;
        currentRowEnd = i;

        if (i != arrayLength - 1) {
            if (currentElement == nextElement) {
                identicalCount++;
            } else {
                identicalCount = 1;
            }

            if (identicalCount == 3) {
                if (currentRowEnd - currentRowStart > rowEnd - rowStart) {
                    rowStart = currentRowStart;
                    rowEnd = currentRowEnd;
                }

                currentRowStart = i;
                identicalCount = 2;
            }
        } else {
            if (currentRowEnd - currentRowStart > rowEnd - rowStart) {
                rowStart = currentRowStart;
                rowEnd = currentRowEnd;
            }
        }
    }

    cout << rowStart + 1 << " " << rowEnd + 1;
}