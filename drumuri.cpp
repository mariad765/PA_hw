#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <limits>
#include <utility>

const long long INF = std::numeric_limits<long long>::max();

using namespace std;

struct Edge {
    long long to;  // neighbour
    long long cost;  // cost to neighbour
};

vector<long long> dijkstra(long long start, const vector<vector<Edge>>& graph) {
    vector<long long> dist(graph.size(), INF);
    // definne  min-heap
    /* template<
    * class T,
    * class Container = std::vector<T>,
    * class Compare = std::less<typename Container::value_type>
    * > class priority_queue;
    */
    priority_queue<pair<long long, long long>,
                    vector<pair<long long, long long>>, greater<>> pq;
    // init vector of distances
    // start distance to start is 0
    dist[start] = 0;
    // place it in queue - will be top of queue
    /* emplace
    * (C++11)
    * constructs element in-place and sorts the underlying container
    * (public member function)
    */
    pq.emplace(0, start);

    while (!pq.empty()) {
        // the the edge-cost out of the queue
        // this is the shortest distence to vertex u
        long long current_dist = pq.top().first;
        // this is the vertex u
        long long u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue;

        // for all neighbours of u
        // update the distance to the neighbour
        for (const auto& edge : graph[u]) {
            // this is v - neighbour of u
            long long v = edge.to;
            // this is the cost of the vertex u to v
            long long weight = edge.cost;
            // if the distance to v is greater than the distance
            // to u + the cost of u to v
            // update the distance to v to be the shortest path
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                // place the new distance to v in the queue
                // add the neighbour to the queue
                pq.emplace(dist[v], v);
            }
        }
    }

    // return the vector of shortest distances from start to all nodes
    return dist;
}

int main() {
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    int N, M;

    fin >> N >> M;

    vector<vector<Edge>> graph(N + 1);
    // reversed graph
    // instead of adding edge a to b we add edge b to a
    vector<vector<Edge>> reversed_graph(N + 1);
    // vector of edges a, b and cost c
    vector<tuple<int, int, long long>> edges;
    // read the edges
    // add the edges to the graph
    // add the reversed edges to the reversed graph
    for (int i = 0; i < M; ++i) {
        int a, b;
        long long c;
        fin >> a >> b >> c;
        graph[a].push_back({b, c});
        reversed_graph[b].push_back({a, c});
        edges.push_back(make_tuple(a, b, c));
    }

    // these are the 3 nodes that we need to find the shortest path between
    int x, y, z;
    fin >> x >> y >> z;

    // find the shortest path from x to all nodes
    vector<long long> dist_from_x = dijkstra(x, graph);
    // find the shortest path from y to all nodes
    vector<long long > dist_from_y = dijkstra(y, graph);
    // find the shortest path from z to all nodes
    vector<long long> dist_to_z = dijkstra(z, reversed_graph);
    // min cost for the 3 nodes ( path between all 3)
    long long min_cost1 = INF;
    // for all nodes
    // node i is the node that I am checking if it is
    // the shortest path between x, y and z
    for (int i = 0; i < N; i++) {
        // if the distance from x to i or from y to i or from z to i is INF
        // it means that there is no path from x to i
        // or from y to i or from z to i
        if (dist_from_x[i] == INF ||
                                dist_from_y[i]==INF || dist_to_z[i] ==INF) {
            continue;
        }
        // if the distance from x to i + distance from y to i +
        // distance from z to i is smaller than the min cost
        min_cost1 = min(min_cost1, dist_from_x[i] +
                            dist_to_z[i] + dist_from_y[i]);
    }

    fout << min_cost1 << endl;

    fin.close();
    fout.close();

    return 0;
}
