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

struct connector {
	ll v1, v2, w;
};

ll calc_sum(vector<ll> &weights, ll u, ll v, ll total) {
	if (u == v) {
		return 0;
	}
	ll res;
	if (v < u) {
		ll temp = u;
		u = v;
		v = temp;
	}
	
	v -= 1;
	res = weights[v] - (u == 0 ? 0 : weights[u-1]);
	
	return min(res,total-res);
}

ll reduced_path_length(vector<ll> &reduced_cycle, ll u, ll v) {
	ll res;
	if (u <= v) {
		res = reduced_cycle[v] - (u == 0 ? 0 : reduced_cycle[u-1]);
	}
	else {
		res = reduced_cycle[v] + reduced_cycle.back() - (u == 0 ? 0 : reduced_cycle[u-1]);
	}
	
	return res;
}

int main() {
	ll i,j,t,n,q,u,v,w,v1,c1,v2,c2;
	t = read_ll();

	while(t--) {
		n = read_ll();
		q = read_ll();

		// node_count[i] contains number of nodes in i-th cycle
		vi node_count(n);

		// connectors[i] contains the edge joining the i-th and (i+1) % n cycle
		vector<connector> connectors(n);

		// weights[i] is a vector holding the weights of the i-th cycle
		// weights[i][j] connects vertices j and (j+1) % node_count[i] of the i-th cycle
		vi weights[n];

		FOR(i,0,n) {
			node_count[i] = read_ll();
			FOR(j,0,node_count[i]) {
				w = read_ll();
				weights[i].pb(w);
			}
		}

		FOR(i,0,n) {
			connectors[i].v2 = read_ll();
			connectors[i].v2 -= 1;
			connectors[(i+1) % n].v1 = read_ll();
			connectors[(i+1) % n].v1 -= 1;
			connectors[i].w  = read_ll();
		}

		// FOR(i,0,n) {
		// 	cout << connectors[i].v1 << " " << connectors[i].v2 << " " << connectors[i].w << endl;
		// }

		vi reduced_cycle;
		vi cycle_sums;

		FOR(i,0,n) {
			j = connectors[i].v1;
			ll path1 = 0, path2 = 0, path = 0;
			do {
				path += weights[i][j];
				j = (j+1) % node_count[i];
				if (j == connectors[i].v2) {
					path1 = path;
				}
			} while (j != connectors[i].v1);

			path2 = path - path1;
			ll min_path = min(path1, path2);

			cycle_sums.pb(path);
			reduced_cycle.pb(min_path);
			reduced_cycle.pb(connectors[i].w);
		}
		// FOR(i,0,2*n) {
		// 	cout << reduced_cycle[i] << " ";
		// }
		// cout << endl;
		FOR(i,1,2*n) {
			reduced_cycle[i] += reduced_cycle[i-1];
		}

		FOR(i,0,n) {
			FOR(j,1,weights[i].size()) {
				weights[i][j] += weights[i][j-1];
			}
		}

		while(q--) {
			v1 = read_ll();
			c1 = read_ll();
			v2 = read_ll();
			c2 = read_ll();

			v1 -= 1; v2 -= 1; c1 -= 1; c2 -= 1;
			// DEBUG(c1); DEBUG(v1);
			// DEBUG(c2); DEBUG(v2);

			ll forward_c1 = calc_sum(weights[c1], v1, connectors[c1].v2, cycle_sums[c1]);
			ll backward_c1 = calc_sum(weights[c1], v1, connectors[c1].v1, cycle_sums[c1]);

			ll forward_c2 = calc_sum(weights[c2], v2, connectors[c2].v2, cycle_sums[c2]);
			ll backward_c2 = calc_sum(weights[c2], v2, connectors[c2].v1, cycle_sums[c2]);
		
			// DEBUG(forward_c1); DEBUG(backward_c1);
			// DEBUG(forward_c2); DEBUG(backward_c2);

			ll res1 = forward_c1 + reduced_path_length(reduced_cycle, 2*c1+1, 2*((c2-1+n)%n)+1) + backward_c2;
			ll res2 = forward_c2 + reduced_path_length(reduced_cycle, 2*c2+1, 2*((c1-1+n)%n)+1) + backward_c1;
			
			printf("%lld\n", min(res1, res2));
		}
	}
	return 0;
}