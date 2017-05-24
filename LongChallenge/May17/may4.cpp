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
#define INF 1e18

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

void build_rangemax_tree(ll* t_max, ll n)   {
    ll i;
    for(i=n-1; i>0; i--)    {
        t_max[i] = max(t_max[i<<1], t_max[i<<1|1]);
    }
    /*for(i=1; i,2*n; i++)
        cout<<t_max[i]<<" ";
    cout<<endl;*/
}

ll range_max(ll* t, ll n, ll l, ll r)   {
    ll maxim = INT_MIN;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)  {
        if(l & 1)
            maxim = max(maxim, t[l++]);
        if(r & 1)
            maxim = max(maxim, t[--r]);
    }
    return maxim;
}

int main() {
	ll i,j,n,k,p;
	char query[100005];
	n = read_ll();
	k = read_ll();
	p = read_ll();
	k = min(n,k);
	vector<int> a(2*n), count(2*n);
	ll t_max[4*n];
	FOR(i,0,n) {
		j = read_int();
		a[n-i-1] = a[2*n-i-1] = j;
	}
	scanf("%s", query);
	FOR(i,0,k) {
		count[0] += a[i];
	}
	t_max[2*n] = count[0];
	FOR(i,1,n) {
		count[i] = count[i-1] + a[i+k-1] - a[i-1];
		t_max[i+2*n] = count[i];
	}
	FOR(i,n,2*n) {
		count[i] = count[i-n];
		t_max[i+2*n] = count[i];
	}
	// FOR(i,0,2*n) {
	// 	cout<<count[i]<<" ";
	// }
	// cout<<"\n";
	ll start_index = 0;
	build_rangemax_tree(t_max, 2*n);
	for(i=0; query[i]; i++) {
		if(query[i] == '!') {
			start_index = (start_index + 1)%n;
		}
		else {
			cout<<range_max(t_max, 2*n, start_index, start_index + n - k + 1)<<"\n";
		}
	}
	return 0;
}