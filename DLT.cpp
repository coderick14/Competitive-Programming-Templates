/*
 * Deleted code is debugged code :)
 */
// Hackerearth Dilku and Love Triangle
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define S(n) scanf("%lld", &n)
#define INF 1e18
#define MOD 1000000007

#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

using namespace std;

int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

/*
 * Hackerearth -> Dilku and Love Triangle 
 */
struct node {
	vector<ll> adj;
};

vector<node> graph;
vector<ll> bit;
vector<ll> start_time(500005), end_time(500005), parent(500005), depth(500005);
vector<bool> visited(500005, false);
ll timer = 0;

void dfs(ll u) {
	visited[u] = true;
	start_time[u] = ++timer;
	for(auto v : graph[u].adj) {
		if (visited[v] == false) {
			parent[v] = u;
			depth[v] = depth[u] + 1;
			dfs(v);
		}
	}
	end_time[u] =  timer;
}

/*
 * POINT UPDATE, RANGE QUERY
 */

// Add delta to A[index]
void point_update(ll index, ll delta) {
    for(;index < bit.size(); index += (index & -index)) {
        bit[index] += delta;
    }
}

// Query sum of A[1..index]
ll prefix_sum(ll index) {
    ll sum = 0;
    for(;index > 0; index -= (index & -index)) {
        sum += bit[index];
    }
    return sum;
}

// Query sum of A[a..b]
ll range_query(ll a, ll b) {
    return prefix_sum(b) - prefix_sum(a-1);
}

// Preprocessing for LCA in O(nlogn)
// binary_ancestor[i][j] stores the 2^j ancestor of node i

ll binary_ancestor[500005][20];

void LCA_preprocessing(ll n) {
	ll i, j;

	for(i = 1; i <= n; i++) {
		for(j = 0; 1 << j <= n; j++) {
			binary_ancestor[i][j] = -1;
		}
	}

	for(i = 1; i <= n; i++) {
		binary_ancestor[i][0] = parent[i];
	}

	for(j = 1; 1 << j <=n; j++) {
		for(i = 1; i <= n; i++) {
			binary_ancestor[i][j] = binary_ancestor[binary_ancestor[i][j-1]][j-1];
		}
	}
}

ll getLCA(ll x, ll y) {
	ll i, temp, log;

	// make x the node with greater depth
	if (depth[x] < depth[y]) {
		temp = x, x = y, y = temp;
	}

	for(log = 1; 1 << log <= depth[x]; log++);
	log--;

	// bring x and y to the same level
	for(i = log; i >= 0; i--) {
		if (depth[x] - (1 << i) >= depth[y]) {
			x = binary_ancestor[x][i];
		}
	}

	// x and y  are now at the same level
	for(i = log; i >= 0; i--) {
		if (binary_ancestor[x][i] != -1 && binary_ancestor[x][i] != binary_ancestor[y][i]) {
			x = binary_ancestor[x][i];
			y = binary_ancestor[y][i];
		}
	}

	return parent[x];
}

int main() {
	ll i,j,t,n,q,u,v;
	n = read_ll();
	q = read_ll();
	graph.resize(n+1);
	bit.resize(n+1);
	FOR(i,0,n-1) {
		u = read_ll();
		v = read_ll();
		graph[u].adj.pb(v);
		graph[v].adj.pb(u);
	}
	parent[1] = depth[1] = bit[0] = 0;
	dfs(1);
	LCA_preprocessing(n);

	while(q--) {
		t = read_ll();
		if (t == 1) {
			u = read_ll();
			v = read_ll();
			point_update(start_time[u],1);
			point_update(start_time[v],1);
			ll lca = getLCA(u,v);
			point_update(start_time[lca], -1);
			if (lca != 1)
				point_update(start_time[parent[lca]], -1);
		}
		else {
			u = read_ll();
			ll ans = range_query(start_time[u], end_time[u]);
			printf("%d\n", ans);
		}
	}
	return 0;
}
