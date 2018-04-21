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
#define INF 1e18
#define MOD 1000000007

using namespace std;

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

struct edge {
	ll v,c;
};

struct node {
	vector<edge> adj;
};

vector<node> graph;
int dp[105][105][26];

bool solve(ll u, ll v, ll last_char) {
	if (dp[u][v][last_char] != -1) {
		return dp[u][v][last_char] == 0;
	}

	bool i_win = false;
	ll i,next_node,next_char;
	FOR(i,0,graph[u].adj.size()) {
		next_node = graph[u].adj[i].v;
		next_char = graph[u].adj[i].c;
		if (next_char >= last_char and !solve(v,next_node,next_char)) {
			i_win = true;
		}
	}
	dp[u][v][last_char] = i_win ? 0 : 1;
	return i_win;
}

int main() {
	ll i,j,k,t,n,e,u,v;
	char c;
	sll(n);sll(e);
	graph.resize(n+1);
	FOR(i,0,e) {
		sll(u);sll(v);
		cin >> c;
		graph[u].adj.pb(edge{v,c-'a'});
	}
	FOR(i,0,n+1) {
		FOR(j,0,n+1) {
			FOR(k,0,26)
				dp[i][j][k] = -1;
		}
	}
	FOR(i,1,n+1) {
		FOR(j,1,n+1) {
			if (solve(i,j,0)) {
				printf("A");
			}
			else {
				printf("B");
			}
		}
		printf("\n");
	}
	return 0;
}