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
vi depth(100005), parent(100005), section_ancestor(100005);
ll maxdepth = 0;
// DFS to calculate depths of each node in O(n)
void dfs(ll u) {
    ll i, len = tree[u].adj.size();
    FOR(i,0,len) {
        ll v = tree[u].adj[i];
        depth[v] = depth[u] + 1;
        if (depth[v] > maxdepth) {
            maxdepth = depth[v];
        }
        dfs(v);
    }
}

// LCA preprocessing in O(n)
// Divide the tree in sqrt(H) sections where H = height of the tree
// section_ancestor[i] stores the ancestor of node i in the last level of upper section
void LCA_preprocessing(ll n) {
    ll i, sqrtH = int(sqrt(maxdepth));

    FOR(i,1,n+1) {
        if (i < sqrtH) {
            section_ancestor[i] = 1;
        }
        else if (depth[i] % sqrtH == 0) {
            section_ancestor[i] = parent[i];
        }
        else {
            section_ancestor[i] = section_ancestor[parent[i]];
        }
    }
}

// Returns LCA of x and y in O(sqrt(n))
ll getLCA(ll x, ll y) {
    cout << "x = "<< x <<" y = "<< y << endl;
    while (section_ancestor[x] != section_ancestor[y]) {
        if (depth[x] > depth[y]) {
            x = section_ancestor[x];
        }
        else {
            y = section_ancestor[y];
        }
    }

    // x and y are now in the same section
    while (x != y) {
        if (depth[x] > depth[y]) {
            x = parent[x];
        }
        else {
            y = parent[y];
        }
    }

    return x;
}

int main(int argc, char *argv[]) {
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
    // cout << "DFS complete ----> maxdepth = " << maxdepth << endl;
    LCA_preprocessing(n);
    // cout << "LCA preprocessing done" << endl;
    // FOR(i,1,n+1) {
    //     cout << "section_ancestor[" << i <<"] = " << section_ancestor[i] << endl;
    // }
    x = read_ll();
    y = read_ll();
    // cout << "LCA of " << x << " and " << y << " = " << getLCA(x,y) << endl;
	return 0;
}
