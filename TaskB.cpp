#include <iostream>
#include <stack>

using namespace std;

class Symbol {
public:
    char value;
    int index;

    Symbol(char val, int ind) {
        value = val;
        index = ind;
    };
};

int main() {
    string inputString;
    cin >> inputString;

    int numbers[inputString.size() / 2];
    stack<Symbol> symbols;

    int animalsCount = 0;
    int trapsCount = -1;

    for (char value: inputString) {
        if (islower(value)) {
            animalsCount++;
            if (!symbols.empty() && symbols.top().value == toupper(value)) {
                numbers[symbols.top().index] = animalsCount;
                symbols.pop();
            } else {
                Symbol symbol = Symbol(value, animalsCount);
                symbols.push(symbol);
            }
        } else {
            trapsCount++;
            if (!symbols.empty() && symbols.top().value == tolower(value)) {
                numbers[trapsCount] = symbols.top().index;
                symbols.pop();
            } else {
                Symbol symbol = Symbol(value, trapsCount);
                symbols.push(symbol);
            }
        }
    }

    if (symbols.empty()) {
        cout << "Possible" << endl;
        for (int n: numbers) {
            cout << n << " ";
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}