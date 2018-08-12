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
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) { sll(a[i]);}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define sll(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define sc(n) scanf("%c", &n)
#define INF 1000000000000007
#define MOD 1000000007

using namespace std;

template<typename T>
void prn(T first) {
    cout << first << "\n";
}

template<typename T, typename... Args>
void prn(T first, Args... args) {
    cout << first << " ";
    prn(args...);
}

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

struct node {
	vi adj;
};
vector<node> tree;
vi st(200005,0), rev_st(200005,0), subsize(200005,0);
ll timer = 0;

ll dfs(ll u) {
	st[u] = ++timer;
	rev_st[st[u]] = u;
	subsize[u] = 1;
	for (auto v : tree[u].adj) {
		subsize[u] += dfs(v);
	}
	return subsize[u];
}

int main() {
	ll i,j,t,n,q,u,k;
	sll(n);sll(q);
	tree.resize(n+1);
	FOR(i,2,n+1) {
		sll(j);
		//prn(j,i);
		tree[j].adj.pb(i);
	}
	subsize[1] = dfs(1);
	// FOR(i,1,n+1) {
	// 	cout << u << " " << st[u] << endl;
	// }
	FOR(i,0,q) {
		sll(u);sll(k);
		if (subsize[u] < k) {
			printf("-1\n");
		}
		else {
			printf("%lld\n", rev_st[st[u]+k -1]);
		}
	}
	return 0;
}