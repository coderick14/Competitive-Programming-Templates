#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    bool visited;
    ll dist;
    vector<ll> adj;
};

int main() {
    ll n,e,i,s,u,v,d;
    cin>>n>>e;
    vector<node> graph(n+1);
    for(i=0;i<n;i++) {
        graph[i].visited = false;
        graph[i].dist = 0;
    }
    for(i=0;i<e;i++) {
        cin>>u>>v;
        graph[u].adj.push_back(v);
        graph[v].adj.push_back(u);
    }
    cin>>s;
    queue<ll> q;
    q.push(s);
    graph[s].dist = 0;
    graph[s].visited = true;
    while(!q.empty()) {
        s = q.front();
        q.pop();
        cout<<s<<" "<<graph[s].dist<<endl;
        for(i=0;i<graph[s].adj.size();i++) {
            d = graph[s].adj[i];
            if(!graph[d].visited) {
                graph[d].visited = true;
                graph[d].dist = graph[s].dist + 1;
                q.push(d);
            }
        }
    }
    return 0;
}
