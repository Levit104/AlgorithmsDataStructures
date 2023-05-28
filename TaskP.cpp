#include <fstream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> adjacencyMatrix;
vector<bool> visited;
int n;
int visited_count = 0;


void dfs(int v, bool reversed) {
    visited[v] = true;
    visited_count++;

    for (int i = 0; i < n; i++) {
        bool start = reversed ? adjacencyMatrix[i][v] : adjacencyMatrix[v][i];
        if (start && !visited[i]) {
            dfs(i, reversed);
        }
    }
}


int main() {
    ifstream fin("avia.in");
    ofstream fout("avia.out");

    fin >> n;

    graph.resize(n, vector<int>(n));
    adjacencyMatrix.resize(n, vector<bool>(n));
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> graph[i][j];
        }
    }

    int l = 0;
    int r = INT_MAX;

    while (l < r) {
        int m = (l + r) / 2;

        adjacencyMatrix.assign(n, vector<bool>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjacencyMatrix[i][j] = (graph[i][j] <= m);
            }
        }

        visited_count = 0;
        visited.assign(n, false);
        dfs(0, false);
        visited.assign(n, false);
        dfs(0, true);

        if (visited_count == 2 * n) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    fout << l << endl;

    fin.close();
    fout.close();

    return 0;
}