// one of the best problems I've seen so far
// SPOJ : INS14L
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

struct node {
	vi adj;
};

vi start_time(100005), end_time(100005), subtree_size(100005), depth(100005), cumulative_depth(100005), parent(100005);
vector<node> tree;
ll timer = 0;

void dfs(ll u) {
	ll i, v, len = tree[u].adj.size();
	start_time[u] = ++timer;
	subtree_size[u] = 1;
	cumulative_depth[u] = depth[u];

	FOR(i,0,len) {
		v = tree[u].adj[i];
		depth[v] = depth[u] + 1;
		dfs(v);
		subtree_size[u] += subtree_size[v];
		cumulative_depth[u] += cumulative_depth[v];
	}

	end_time[u] = timer;
}

ll range_query(ll* t, ll n, ll l, ll r)   {
    ll sum=0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)    {
        if(l & 1)
            sum = (sum + t[l++])%MOD;
        if(r & 1)
            sum = (sum + t[--r])%MOD;
    }
    return sum;
}

void point_update(ll* t, ll n, ll index, ll key) {
	index += n;
	t[index] = (t[index] + key)%MOD;
	for(; index>1; index>>=1) {
		t[index>>1] = (t[index] + t[index^1])%MOD;
	}
}

void range_update(ll* t, ll n, ll l, ll r, ll key) {
	for(l+=n, r+=n; l<r; l>>=1, r>>=1)    {
        if(l & 1) {
            t[l] = (t[l] + key)%MOD;
            l++;
        }
        if(r & 1) {
        	--r;
            t[r] = (t[r] + key)%MOD;
        }
    }
}

ll point_query(ll* t, ll n, ll index) {
	ll ans = 0;
	for(index+=n; index > 0; index>>=1) {
		ans = (ans + t[index])%MOD;
	}
	return ans;
}

int main() {
	ll i,j,t,u,n,q,x,k,total;
	n = read_ll();

	tree.resize(n+1);
	ll seg_tree1[2*n+2], seg_tree2[2*n+2], seg_tree3[2*n+2];

	FOR(i,0,2*n+2) {
		seg_tree1[i] = seg_tree2[i] = seg_tree3[i] = 0;
	}
	parent[1] = 0;
	FOR(i,2,n+1) {
		j = read_ll();
		tree[j].adj.pb(i);
		parent[i] = j;
	}
	dfs(1);
	// FOR(i,1,n+1) {
	// 	printf("i = %lld st = %lld et = %lld sz = %lld dep = %lld cdep = %lld\n", i,start_time[i],end_time[i],subtree_size[i],depth[i],cumulative_depth[i]);
	// }
	q = read_ll();
	FOR(i,0,q) {
		t = read_ll();
		u = read_ll();

		if (t == 1) {
			x = read_ll();
			k = read_ll();

			total = subtree_size[u] * x + k * (cumulative_depth[u] - depth[u] * subtree_size[u]);
			// printf("calculated total = %lld\n", total);
			range_update(seg_tree1, n+1, start_time[u], end_time[u]+1, (x - (depth[u]*k) + MOD)%MOD);
			range_update(seg_tree2, n+1, start_time[u], end_time[u]+1, k);
			point_update(seg_tree3, n+1, start_time[parent[u]], total);
			// cout<<"==========================================================\n";
			// FOR(j,1,2*n+2) {
			// 	cout<<seg_tree1[j]<<" ";
			// }
			// cout<<"\n==========================================================\n";
			// cout<<"==========================================================\n";
			// FOR(j,1,2*n+2) {
			// 	cout<<seg_tree2[j]<<" ";
			// }
			// cout<<"\n==========================================================\n";
			// cout<<"==========================================================\n";
			// FOR(j,1,2*n+2) {
			// 	cout<<seg_tree3[j]<<" ";
			// }
			// cout<<"\n==========================================================\n";
		}
		else {
			ll val1 = (point_query(seg_tree1, n+1, start_time[u]) * subtree_size[u])%MOD;
			ll val2 = (point_query(seg_tree2, n+1, start_time[u]) * cumulative_depth[u])%MOD;
			ll val3 = range_query(seg_tree3, n+1, start_time[u], end_time[u]+1);
			// printf("val1 = %lld val2 = %lld val3 = %lld\n", val1, val2, val3);
			total = ((val1 + val2)%MOD + val3)%MOD;
			if (total < 0)
				total += MOD;

			printf("%lld\n", total);
		}
	}
	return 0;
}