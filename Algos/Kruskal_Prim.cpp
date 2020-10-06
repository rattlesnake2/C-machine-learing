#include <bits/stdc++.h>
using namespace std;
#define vec vector<vector<int>>

int getParent(vector<int> &parent, int v) {
    if (parent[v] == v) return v;
    return getParent(parent, parent[v]);
}

void kruskal(vec &graph, int V) {
    sort(graph.begin(), graph.end(),
         [](vector<int> v1, vector<int> v2) { return v1[2] < v2[2]; });

    vector<int> parent(V, -1);

    for (int i = 0; i < V; i++) parent[i] = i;
    int i = 0, cnt = 0;
    cout << "Source\t\tDestination\tDistance\n";
    while (cnt < V - 1) {
        int a = graph[i][0];
        int b = graph[i][1];
        int p1 = getParent(parent, a);
        int p2 = getParent(parent, b);
        if (p1 != p2) {
            cout << a << "\t\t" << b << "\t\t" << graph[i][2] << endl;
            cnt++;
            parent[a] = p2;
        }
        i++;
    }
}

int main(int argc, const char **argv) {
    cout << "Enter number of vertices and edges  ";
    int V, E;
    cin >> V >> E;
    vec graph(E, vector<int>(3, INT16_MAX));
    cout << "Enter source and destination vertex and Distance\n";

    for (int i = 0; i < E; i++) {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }
    cout << "Spanning Tree using Kruskal Algorithm\n";
    kruskal(graph, V);
}
