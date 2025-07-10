#include<bits/stdc++.h>
using namespace std;

void start()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

class data
{
public:
    int u, v, cost;
    data(int _u, int _v, int _cost)
    {
        u = _u;
        v = _v;
        cost = _cost;
    }

    bool operator < (const data &p) const {
        return cost > p.cost; // smaller cost comes first
    }
};

vector<int> parent;

int findParent(int node)
{
    if(parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]); // path compression
}

void unionSet(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if(u != v)
        parent[v] = u; // simply make one parent of the other
}

int main()
{
    start();

    int n, m;
    cin >> n >> m;

    priority_queue<data> edges;
    
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push(data(u, v, w));
    }

    parent.resize(n+1);
    for(int i = 1; i <= n; i++)
        parent[i] = i;

    int mst_cost = 0;
    vector<pair<int,int>> mst_edges;

    while(!edges.empty())
    {
        data cur = edges.top();
        edges.pop();

        int u = cur.u;
        int v = cur.v;
        int w = cur.cost;

        if(findParent(u) != findParent(v))
        {
            unionSet(u, v);
            mst_cost += w;
            mst_edges.push_back({u, v});
        }
    }

    cout << "Total cost of MST: " << mst_cost << endl;
    cout << "Edges in MST:" << endl;
    for(auto it : mst_edges)
    {
        cout << it.first << " - " << it.second << endl;
    }

    return 0;
}
