#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Letter {
public:
    char symbol;
    int weight;

    Letter(char s, int w) {
        symbol = s;
        weight = w;
    };
};

int main() {
    ifstream fin("aurora.in");
    ofstream fout("aurora.out");

    string inputString;
    vector<Letter> letters;
    vector<Letter> repeatedLetters;

    fin >> inputString;

    for (char s = 'a'; s <= 'z'; s++) {
        int w;
        fin >> w;
        Letter letter = Letter(s, w);
        letters.push_back(letter);
    }

    sort(letters.begin(), letters.end(), [](const Letter &l1, const Letter &l2) {
        return l1.weight > l2.weight;
    });

    for (Letter letter: letters) {
        int repeatCount = (int) count(inputString.begin(), inputString.end(), letter.symbol);
        if (repeatCount >= 2) {
            repeatedLetters.push_back(letter);
        }
    }

    for (int i = 0, left = 0, right = (int) inputString.size() - 1; i < repeatedLetters.size(); i++, left++, right--) {
        Letter letter = repeatedLetters[i];

        int newLeft = (int) inputString.find(letter.symbol);

        if (letter.symbol != inputString[left]) {
            swap(inputString[left], inputString[newLeft]);
        }

        int newRight = (int) inputString.rfind(letter.symbol);

        if (letter.symbol != inputString[right]) {
            swap(inputString[right], inputString[newRight]);
        }
    }

    fout << inputString << endl;

    return 0;
}
