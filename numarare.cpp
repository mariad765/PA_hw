#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>


const int MOD = 1000000007;

using namespace std;

vector<int> topological_sort(int N, vector<vector<int>>& graph) {
    // implementare din laboratorul 7
    // TopSort - BFS: algoritmul lui Kahn
    // T(n)=O(n+m)
    vector<int> in_degree(N + 1, 0);
    for (int u = 1; u <= N; ++u) {
        for (int v : graph[u]) {
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topo_order;
}

vector<long long> count_paths(int N, vector<vector<int>>& graph,
                                vector<int>& topo_order) {
    vector<long long> dp(N + 1, 0);
    dp[1] = 1;
    // forul parcurge nodurile sortate topologic si in vectorul dp
    // retine numarul de drumuri pana la vecinii fiecarui nod
    for (int u : topo_order) {
        for (int v : graph[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    return dp;
}

int main() {
    ifstream fin("numarare.in");
    ofstream fout("numarare.out");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> graph1(N + 1);
    vector<vector<int>> graph2(N + 1);

    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        graph1[x].push_back(y);
    }

    for (int i = 0; i < M; ++i) {
    int x, y;
    fin >> x >> y;
    // add it only if the edge is in the first graph
    if (std::find(graph1[x].begin(), graph1[x].end(), y) != graph1[x].end())
        graph2[x].push_back(y);
    }

    // topological sort
    vector<int> topo_order3 = topological_sort(N, graph2);
    // count paths using dynamic programming
    vector<long long> dp3 = count_paths(N, graph2, topo_order3);

    long long common_paths = 0;
    // extract the number of common paths
    common_paths = dp3[N] % MOD;

    fout << common_paths << "\n";

    fin.close();
    fout.close();

    return 0;
}
