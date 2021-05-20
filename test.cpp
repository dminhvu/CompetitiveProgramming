#include <vector>
#include <queue>
#include <fstream>
#include <iostream>

#define sz(a) int(a.size())
#define inf 1e6

using namespace std;

void Dijkstra(vector<vector<pair<int, int>>> adj, int key);

int main()
{
    fstream myFile;
    myFile.open("input.txt", ios::in);
    int ver, ed;
    int u, v, w;
    myFile >> ver >> ed;
    vector<vector<pair<int, int>>> adj(ver + 1);
    for (int i = 0; i < ed; i++)
    {
        myFile >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijkstra(adj,2);
    myFile.close();
    return 0;
}

void Dijkstra(vector<vector<pair<int, int>>> adj, int key)
{
    if (key >= sz(adj))
    {
        cout << "No such source";
        return;
    }
    queue<int> q;
    vector<int> dist(sz(adj), inf);
    int u, v, w;
    dist[key] = 0;
    q.push(key);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int i =0;i<sz(adj[u]);i++) {
            v = adj[u][i].first;
            w = adj[u][i].second;
            if (dist[v] > dist[u]+w) {
                dist[v] = dist[u]+w;
                q.push(v);
            }
        }
    }
    
    for (int i = 1;i < sz(dist);i++)
        cout << key << " -> " << i << " = "<<dist[i]<<'\n';
}