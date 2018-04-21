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

struct node {
	vi adj;
};

char s[300005];
vi letter(26,0);
vector<node> graph;
bool in_stack[300005];
vi visited;
ll ans = -1, iter = 0;
bool cycle = false;

void dfs(ll u) {
	//cout << "at node " << u << endl;
	ll i,v;
	visited[u] = iter;
	in_stack[u] = true;
	letter[s[u-1]-'a'] += 1;
	FOR(i,0,graph[u].adj.size()) {
		v = graph[u].adj[i];
		if (in_stack[v]) {
			//DEBUG(v);
			cycle = true;
			return;
		}
		if (visited[v] < iter)
			dfs(v);
	}
	if (!cycle) {
		//cout<<u<<endl;
		FOR(i,0,26) {
			//cout<<letter[i];
			ans = max(ans,letter[i]);
		}
		//cout<<endl;
	}
	in_stack[u] = false;
	letter[s[u-1]-'a'] -= 1;
}

int main() {
	ll i,j,t,n,m,u,v;
	sll(n);sll(m);
	scanf("%s",s);
	vi indeg(n+1,0),outdeg(n+1,0);
	graph.resize(n+1);
	visited.resize(n+1);
	FOR(i,0,m) {
		sll(u);sll(v);
		graph[u].adj.pb(v);
		indeg[v] += 1;
		outdeg[u] += 1;
	}
	vi starts;
	FOR(i,1,n+1) {
		if (indeg[i] == 0) {
			starts.pb(i);
		}
	}
	if (starts.size() == 0) {
		printf("-1\n");
		return 0;
	}
	ll  res = -1;
	FOR(i,0,starts.size()) {
		iter += 1;
		dfs(starts[i]);
		if (cycle) {
			res = -1;
			break;
		}
		res = max(res,ans);
		cycle = false;
		ans = -1;
		// memset(visited,false,sizeof(visited));
		// memset(in_stack,false,sizeof(in_stack));
		FOR(j,0,26) {
			letter[j] = 0;
		}
	}
	printf("%lld\n", res);
	return 0;
}