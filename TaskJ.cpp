#include <deque>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    deque<int> firstPart;
    deque<int> secondPart;

    for (int i = 0; i < n; i++) {
        char action;
        fin >> action;

        if (firstPart.size() > secondPart.size()) {
            secondPart.push_back(firstPart.front());
            firstPart.pop_front();
        }

        if (action == '-') {
            fout << secondPart.front() << endl;
            secondPart.pop_front();
        } else {
            int goblin;
            fin >> goblin;
            if (action == '+') {
                firstPart.push_back(goblin);
            } else {
                firstPart.push_front(goblin);
            }
        }
    }

    fin.close();
    fout.close();
}
