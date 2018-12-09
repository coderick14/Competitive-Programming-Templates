/*
 * Deleted code is debugged code :)
 */
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
#define SULL(n) scanf("%llu", &n)
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

struct node {
    vi adj;
};

vector<node> tree;
vi depth(100005), parent(100005);

// DFS to calculate depths of the nodes
void dfs(ll u) {
    ll i, len = tree[u].adj.size();
    FOR(i,0,len) {
        ll v = tree[u].adj[i];
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

// Preprocessing for LCA in O(nlogn)
// binary_ancestor[i][j] stores the 2^j ancestor of node i

ll binary_ancestor[1000005][20];

void LCA_preprocessing(ll n) {
	ll i, j;

	for(i = 1; i <= n; i++) {
		for(j = 0; (1 << j) <= n; j++) {
			binary_ancestor[i][j] = -1;
		}
	}

	for(i = 1; i <= n; i++) {
		binary_ancestor[i][0] = parent[i];
	}

	for(j = 1; (1 << j) <=n; j++) {
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
	ll i,j,t,n,x,y;
    n = read_ll();
    tree.resize(n+1);
    // 1 is the root. Accept parents of the remaining (n-1) nodes
    FOR(i,2,n+1) {
        j = read_ll();
        tree[j].adj.pb(i);
        parent[i] = j;
    }
    dfs(1);
    LCA_preprocessing(n);
    x = read_ll();
    y = read_ll();
    cout << "LCA of " << x << " and " << y << " = " << getLCA(x,y) << endl;
	return 0;
}