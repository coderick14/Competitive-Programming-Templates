#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;

vector<vector<ll>> adj;
vector<ll> low, discover;
vector<bool> visited;
set<ll> articulation_pts;
ll timer = 0;


void explore(ll u, ll p = 0) {
	visited[u] = true;
	discover[u] = low[u] = ++timer;

	ll children = 0;
	for (ll v : adj[u]) {
		if (visited[v] == false) {
			children++;
			explore(v,u);
			low[u] = min(low[u], low[v]);
			if (p == 0 and children > 1) {
				articulation_pts.insert(u);
			}
			if (p != 0 and low[v] >= discover[u]) {
				articulation_pts.insert(u);
			}
		}
		else if (v != p) {
			low[u] = min(low[u], discover[v]);
		}
	}
}

void dfs(ll n) {
	ll i;
	for (i = 1; i <= n; i++) {
		if (visited[i] == false) {
			explore(i);
		}
	}
}

int main() {
	ll n, m, i, u, v;
	cin >> n >> m;
	adj.resize(n+1);
	discover.resize(n+1);
	low.resize(n+1);
	visited.assign(n+1,false);

	for (i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(n);
	for (ll pt : articulation_pts) {
		cout << pt << endl;
	}
	return 0;
}