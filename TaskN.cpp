#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;


void dfs(int vertex) {
    visited[vertex] = true;
    for (int v: graph[vertex]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    graph.resize(n);
    visited.resize(n);

    for (int from = 0; from < n; from++) {
        int to;
        fin >> to;
        graph[from].push_back(to - 1);
        graph[to - 1].push_back(from);
    }

    int components_count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            components_count++;
        }
    }

    fout << components_count << endl;

    fin.close();
    fout.close();

    return 0;
}