#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    int previousResult = 0;
    for (int i = 0; i < k; i++) {
        a = a * b - c;

        if (a < 0) { // a + c < c
            a = 0;
            break;
        }

        if (a > d) {
            a = d;
        }

        if (a == previousResult) {
            break;
        }

        previousResult = a;
    }

    cout << a << endl;

    return 0;
}