#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#include <unordered_map>

void topological_sort_util(string u, unordered_map<string,
vector<string>>& graph,
unordered_map<string, bool>& visited, vector<string>& topo_order) {
    // mark current node as visseted
    visited[u] = true;
    // for all neighbours of u
    for (string v : graph[u]) {
        // if the neighbour is not visited
        if (!visited[v]) {
            // visit the neighbour
            topological_sort_util(v, graph, visited, topo_order);
        }
    }
    // cuurent node is added to the order
    topo_order.push_back(u);
}

int main() {
    ifstream fin("trenuri.in");
    ofstream fout("trenuri.out");

    string start, destination;
    fin >> start >> destination;

    int N;
    fin >> N;

    // a graph
    unordered_map<string, vector<string>> graph;
    // read the graph
    for (int i = 0; i < N; ++i) {
        string u, v;
        fin >> u >> v;
        graph[u].push_back(v);
    }

    // topological sort
    // make every node appear before the node that the vertex is to
    unordered_map<string, bool> visited;
    vector<string> topo_order;
    topological_sort_util(start, graph, visited, topo_order);

    // count the maximum number of nodes
    unordered_map<string, int> dist;
    // we process the nodes in topological sort order
    for (string u : topo_order) {
        // the distance to the node itself is 0
        dist[u] = 0;
        // for every neighbour of u
        for (string v : graph[u]) {
            // the distance to the neighbour is the maximum of the
            // distance to the neighbour and the distance to u + 1
            // because we want to visit as many cities as possible
            dist[u] = max(dist[u], dist[v] + 1);
        }
    }

    fout << dist[start] + 1 << "\n";

    fin.close();
    fout.close();

    return 0;
}
