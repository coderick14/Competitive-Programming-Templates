#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000000007
using namespace std;

const ll nodes = 1002;
vector<vector<ll>> adj(nodes);
vector<vector<ll>> capacity(nodes, vector<ll>(nodes)), flow(nodes, vector<ll>(nodes));
vector<ll> dist, pt;
queue<ll> q;
ll src, dest;

void add_edge(ll u, ll v, ll c) {
	if (u != v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
		capacity[u][v] += c;
		capacity[v][u] += c;
	}
}

bool bfs() {
	fill(dist.begin(), dist.end(),INF);
	dist[src] = 0;
	q.push(src);

	while (!q.empty() and dist[dest] == INF) {
		ll u = q.front(); q.pop();

		for (ll to : adj[u]) {
			if (dist[to] == INF and flow[u][to] < capacity[u][to]) {
				dist[to] = dist[u] + 1;
				q.push(to);
			}
		}
	}
	while (!q.empty()) q.pop();

	return dist[dest] != INF;
}

ll dfs(ll u, ll curr_flow) {
	if (curr_flow == 0 or u == dest) {
		return curr_flow;
	}

	for (; pt[u] < adj[u].size(); pt[u]++) {
		ll to = adj[u][pt[u]];

		if (dist[to] == dist[u] + 1) {
			ll pushed = dfs(to, min(curr_flow, capacity[u][to] - flow[u][to]));
			if (pushed > 0) {
				flow[u][to] += pushed;
				flow[to][u] -= pushed;
				return pushed; 
			}
		}
	}

	return 0;
}

ll dinic() {
	ll flow = 0;
	while (bfs()) {
		fill(pt.begin(), pt.end(),0);

		 while (ll pushed = dfs(src, INF)) {
		 	flow += pushed;
		 }
	}
	return flow;
}

int main() {
	ll n,m,i,u,v,c;
	cin >> n >> m;
	adj.resize(n);
	dist.resize(n);
	pt.resize(n);

	for (i = 0; i < m; i++) {
		cin >> u >> v >> c;
		u--;v--;
		add_edge(u,v,c);
	}
	cin >> src >> dest;
	src--;dest--;
	cout << dinic() << endl;
	return 0;
}