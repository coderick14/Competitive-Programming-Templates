#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<set<ll>> adj;
vector<ll> parent, subtree_size;

ll dfs(ll u, ll p) {
	subtree_size[u] = 1;
	for (auto v : adj[u]) {
		if (v != p) {
			subtree_size[u] += dfs(v,u);
		}
	}
	return subtree_size[u];
}

ll find_centroid(ll u, ll p, ll n) {
	for (auto v : adj[u]) {
		if (v != p and subtree_size[v] > n/2) {
			return find_centroid(v, u, n);
		}
	}
	return u;
}

void decompose(ll u, ll p = 0) {
	ll n = dfs(u, p);
	ll centroid = find_centroid(u, p, n);
	if (p == 0) {
		p = centroid;
	}
	parent[centroid] = p;

	for (auto v : adj[centroid]) {
		adj[v].erase(centroid);
		decompose(v, centroid);
	}
	adj[centroid].clear();
}

int main() {
	ll i, n, u, v;
	cin >> n;
	adj.resize(n+1);
	parent.resize(n+1);
	subtree_size.resize(n+1);

	for (i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	decompose(1);

	for (i = 1; i <= n; i++) {
		cout << parent[i] << endl;
	}
	return 0;
}