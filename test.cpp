#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

const int inf = 1e9;

// dijkstra structure 
struct Node{
    string u;
    int dist;
    bool operator < (const Node &oth) const {
        // to sort the dist values descending
        return dist < oth.dist;
    }
};

int n = 0;

map<string, int> mp;

string Dijkstra(string from, string to, string words[]) {
    // assign vertices to strings
    mp[from] = n++;
    for (int i = 0; i < 5; i++) mp[words[i]] = n++;
    mp[to] = n++;

    // create a new list including the [from] and [to] strings with the [words]
    vector<string> word_list;
    word_list.push_back(from);
    for (int i = 0; i < n - 2; i++) word_list.push_back(words[i]);
    word_list.push_back(to);

    // distance array for dijkstra
    vector<int> _distance(n);
    for (int i = 0; i < n; i++) _distance[i] = inf;
    _distance[0] = 0;

    // dijkstra heap
    priority_queue<Node> pq;
    pq.push({from, 0});
    while (pq.size()) {
        string u = pq.top().u;
        int dist = pq.top().dist;
        pq.pop();
        for (int i = 0; i < n; i++) {
            int count_different_chars = 0;
            for (int j = 0; j < u.size(); j++) count_different_chars += (u[j] != word_list[i][j]);
            if (count_different_chars != 1) continue;
            if (_distance[mp[word_list[i]]] > _distance[mp[u]] + 1) {
                _distance[mp[word_list[i]]] = _distance[mp[u]] + 1;
                pq.push({word_list[i], _distance[mp[word_list[i]]]});
            }
        }
    }
    return ((_distance[mp[to]] == inf || _distance[mp[to]] < 2) ? "false" : "true");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string words[] = {"hot", "dot", "dog", "lot", "log"};
    string from = "hit";
    string to = "cog";
    cout << Dijkstra(from, to, words);
    return 0;
}