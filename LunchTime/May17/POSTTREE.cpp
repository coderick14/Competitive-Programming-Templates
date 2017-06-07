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
vi depth(100005), span_parent(100005), dp(100005), val(100005);

void dfs(ll u) {
	ll temp_u = u;
	while (val[u] < val[span_parent[temp_u]]) {
		temp_u = span_parent[temp_u];
	}
	span_parent[u] = span_parent[temp_u];
	dp[u] = (depth[u] - depth[span_parent[temp_u]]) * val[u] + dp[span_parent[temp_u]];
	ll i, len = tree[u].adj.size();
    FOR(i,0,len) {
        ll v = tree[u].adj[i];
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

int main() {
	ll i,j,t,n;
	n = read_ll();
	tree.resize(n+1);
    FOR(i,2,n+1) {
        j = read_ll();
        tree[j].adj.pb(i);
        span_parent[i] = j;
    }
    FOR(i,1,n+1) {
    	val[i] = read_ll();
    }
    val[0] = -INF;
    span_parent[1] = dp[0] = 0;
    depth[0] = -1;
    dfs(1);

    FOR(i,1,n+1) {
    	printf("%lld ", dp[i]);
    }
	return 0;
}