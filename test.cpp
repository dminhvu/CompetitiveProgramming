#include <iostream>
#define INT_MAX 10000000000
using namespace std;
struct edge
{
    int src;
    int dest;
    int wt;
};
void BellmanFord(edge e[], int V, int E, int src)
{
    int *dis = new int[V];
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (dis[e[j].src] != INT_MAX && dis[e[j].src] + e[j].wt < dis[e[j].dest])
                dis[e[j].dest] = dis[e[j].src] + e[j].wt;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int x = e[i].src;
        int y = e[i].dest;
        int weight = e[i].wt;
        if (dis[x] != INT_MAX && dis[x] + weight < dis[y]) {
            cout << "Graph contains negative weight cycle"<< endl;
            cout << x << " " << y << '\n';
        }
                
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
}

int main()
{
    freopen64("input.txt", "r", stdin);
    int V, E, x;
    cin >> V;
    cin >> E;
    cin >> x;
    edge *e = new edge[E];
    for (int i = 0; i < E; i++)
    {
        cin >> e[i].src;
        cin >> e[i].dest;
        cin >> e[i].wt;
    }
    BellmanFord(e, V, E, x);
    return 0;
}
