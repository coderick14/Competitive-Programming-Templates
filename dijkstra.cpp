#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;

vector<vector<pair<ll,ll>>> adj;
vector<ll> dist;
set<pair<ll,ll>> active_vertices;

void dijkstra(ll u) {
	ll v,w;
	dist[u] = 0;
	active_vertices.insert({0, u});

	while (!active_vertices.empty()) {
		auto it = active_vertices.begin();
		u = it->second;
		active_vertices.erase(it);
		for (auto neighbour : adj[u]) {
			v = neighbour.first;
			w = neighbour.second;
			if (dist[u] + w < dist[v]) {
				it = active_vertices.find({dist[v], v});
				if (it != active_vertices.end()) {
					active_vertices.erase(it);
				}
				dist[v] = dist[u] + w;
				active_vertices.insert({dist[v], v});
			}
		}
	}
}

int main() {
	ll i, n, m, u, v, w, src;
	cin >> n >> m;
	adj.resize(n+1);
	dist.assign(n+1, INF);

	for (i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	cin >> src;

	dijkstra(src);
	for (i = 1; i <= n; i++) {
		cout << i << " " << dist[i] << endl;
	}
	return 0;
}
