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

const ll MAX = 1e9+7;
map<ll,ll> prime_factors;
vi primes;
map<ll,ll>::iterator it;

void sieve()
{
	ll n = 1e5;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (ll p=2; p<=n; p++)
       if (prime[p])
          primes.pb(p);
}

void factorize(ll n) {
	if (n == 1) {
		return;
	}
	ll power,i,j;
	for(j=0; j<primes.size(); j++) {
		i = primes[j];
		power = 0;
		while (n%i == 0) {
			n = n / i;
			power++;
		}
		if(power != 0) {
			prime_factors[i] += power;
		}
	}
	if (n != 1) {
		prime_factors[n] += 1;
	}
}

ll find_pow(ll base, ll exponent) {
	ll res = 1;
	base = base % MAX;
	while(exponent > 0) {
		if(exponent%2) {
			res = (res*base)%MAX;
		}
		base = (base*base)%MAX;
		exponent /= 2;
	}
	return res;
}

int main() {
	ll i,j,t,n;
	sieve();
	n = read_ll();
	FOR(i,0,n) {
		j = read_ll();
		factorize(j);
	}
	bool flag = true;
	for(it = prime_factors.begin(); it != prime_factors.end(); it++) {
		//cout<<it->first<<" "<<it->second<<endl;
		if(it->second % n != 0) {
			flag = false;
			break;
		}
	}
	if (flag == true) {
		printf("justdoit");
		return 0;
	}
	ll res = 1;
	for(it = prime_factors.begin(); it != prime_factors.end(); it++) {
		if (it->second % (n+1) != 0)
			res = (res * find_pow(it->first,n+1 - (it->second % (n+1)))) % MAX;
	}
	printf("%lld", res);
	
	return 0;
}