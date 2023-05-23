#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    vector<int> prices;

    ifstream fin("shop.in");
    ofstream fout("shop.out");

    fin >> n >> k;

    int price;
    while (fin >> price) {
        prices.push_back(price);
    }

    sort(prices.begin(), prices.end(), greater<>());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % k != 0) {
            sum += prices[i];
        }
    }

    fout << sum;

    fin.close();
    fout.close();

    return 0;
}
