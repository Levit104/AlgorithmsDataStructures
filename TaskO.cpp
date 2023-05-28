#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> colors;

bool dfs(int vertex, int color) {
    colors[vertex] = color;

    for (int v: graph[vertex]) {
        if (colors[v] == color || (colors[v] == 0 && !dfs(v, (color == 1) ? 2 : 1))) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    graph.resize(n);
    colors.resize(n);

    for (int i = 0; i < m; i++) {
        int from, to;
        fin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }

    bool isBipartite = true;
    for (int i = 0; i < n; i++) {
        isBipartite = !(colors[i] == 0 && !dfs(i, 1));
        if (!isBipartite) break;
    }

    fout << (isBipartite ? "YES" : "NO") << endl;

    fin.close();
    fout.close();

    return 0;
}