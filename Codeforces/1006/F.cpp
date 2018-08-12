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

ll grid[23][23];
map<ll,ll> dp[23];
ll n,m;

void dfs1(ll i, ll j, ll k) {
	if (i >= n or j >= m) {
		return;
	}
	if ((i + j) == ((n + m) / 2 - 1)) {
		dp[i][grid[i][j]^k]++;
		return;
	}
	dfs1(i+1,j,grid[i][j]^k);
	dfs1(i,j+1,grid[i][j]^k);
}

ll dfs2(ll i, ll j, ll k) {
	if (i < 0 or j < 0)
		return 0;
	if ((i + j) == ((n + m) / 2 - 1)) {
		return dp[i][k];
	}
	return dfs2(i,j-1,grid[i][j] ^ k) + dfs2(i-1,j,grid[i][j] ^ k);
}

int main() {
	ll i,j,t,k;
	sll(n);sll(m);sll(k);
	FOR(i,0,n) {
		FOR(j,0,m) {
			sll(grid[i][j]);
		}
	}
	dfs1(0,0,0);
	cout << dfs2(n-1,m-1,k);
	return 0;
}