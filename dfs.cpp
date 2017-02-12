#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    bool visited;
    vector<ll> adj;
};

void explore(vector<node> &graph, ll u) {
    graph[u].visited = true;
    for(ll i=0; i<graph[u].adj.size(); i++) {
        ll v = graph[u].adj[i];
        if(!graph[v].visited) {
            explore(graph,v);
        }
    }
}

void dfs(vector<node> &graph, ll n) {
    for(ll i=1; i<=n; i++) {
        if(!graph[i].visited) {
            explore(graph,i);
        }
    }
}

int main() {
    ll n,e,i,s,u,v,d;
    cin>>n>>e;
    vector<node> graph(n+1);
    for(i=0;i<n;i++) {
        graph[i].visited = false;
    }
    for(i=0;i<e;i++) {
        cin>>u>>v;
        graph[u].adj.push_back(v);
        graph[v].adj.push_back(u);
    }
    dfs(graph,n);
    return 0;
}
