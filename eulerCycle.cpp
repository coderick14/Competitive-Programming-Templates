//Codechef problem code TOURISTS
#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

set<pair<ll,ll> > edges[N];
vector<pair<ll,ll> > final_edges(N);
ll deg[N];
bool visited[N];
ll cnt = 0;

void dfs(ll u) {
	visited[u] = 1;
	cnt++;
	set<pair<ll,ll> >::iterator it;
	for(it = edges[u].begin(); it != edges[u].end(); it++) {
		if(!visited[it->first])
			dfs(it->first);
	}
}

int main() {
	ll i,n,e,u,v,index;
	cin>>n>>e;
	for(i=0;i<e;i++) {
		cin>>u>>v;
		edges[u].insert(make_pair(v,i));
		edges[v].insert(make_pair(u,i));
		deg[u] += 1;
		deg[v] += 1;
	}
	for(i=1;i<=n;i++) {
		if(deg[i] & 1) {
			cout<<"NO";
			return 0;
		}
	}
	dfs(1);
	if(cnt != n) {
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	//generate eulerian cycle
	for(u=1;u<=n;u++) {
		while(!edges[u].empty()) {
			ll s = u;
			do {
				pair<ll,ll> p = *edges[s].begin();
				index = p.second;
				v = p.first;
				final_edges[index] = make_pair(s,v);
				edges[s].erase(p);
				edges[v].erase(make_pair(s,index));
				s = v;
			}while(s != u);
		}
	}
	//final_edges store the directed edges in the same order of input
	for(i=0;i<e;i++) {
		cout<<final_edges[i].first<<" "<<final_edges[i].second<<"\n";
	}
	return 0;
}