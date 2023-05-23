#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>

using namespace std;

bool isNumber(string &str) {
    return str.find_first_not_of("-0123456789") == string::npos;
//    return isdigit(str[0]) || str[0] == '-';
}

bool variableNotExists(unordered_map<string, stack<int>> &map, string &key) {
    return map.find(key) == map.end() || map[key].empty();
}

int main() {
    string line;

    unordered_map<string, stack<int>> mainMap;

    stack<list<string>> blocksContainer;

    list<string> newBlock;

    blocksContainer.push(newBlock); // container = { }

    while (getline(cin, line)) {
        if (line == "{") {

            blocksContainer.push(newBlock); // container = { {  } }

        } else if (line == "}") {

            for (string &changedVariable: blocksContainer.top()) {
                mainMap[changedVariable].pop();
            }

            blocksContainer.pop();

        } else {
            int separator = (int) line.find('=');
            string leftSide = line.substr(0, separator);
            string rightSide = line.substr(separator + 1);

            if (isNumber(rightSide)) { // a = 10

                int convertedValue = stoi(rightSide);
                mainMap[leftSide].push(convertedValue);

            } else { // a = b

                if (variableNotExists(mainMap, rightSide)) {
                    mainMap[rightSide].push(0); // b = 0
                }

                int newValue = mainMap[rightSide].top(); // newValue = b
                mainMap[leftSide].push(newValue); // a = newValue = b

                cout << mainMap[leftSide].top() << endl;
            }

            blocksContainer.top().push_front(leftSide); // = currentBlock.push( a )
        }
    }

    return 0;
}
