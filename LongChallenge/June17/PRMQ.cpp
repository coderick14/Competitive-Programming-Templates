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
	node *left, *right;
	ll data;

	node(node* left, node* right, ll data) {
		this->left = left;
		this->right = right;
		this->data = data;
	}
};

vi primes_index_map(1000005);
vi primes;
vi LPF(1000005,0);
vector<node*> tree_roots(100005);
vector<map<ll,ll> > prime_factors(100005);
map<ll,ll>::iterator it;

void sieve()
{
	ll n = 1e6;
	// bool prime[n+1];
    // memset(prime, true, sizeof(prime));
 
    for (ll p=2; p*p<=n; p++) {
        if (LPF[p] == 0) {
            for (ll i=p*2; i<=n; i += p)
                LPF[i] = p;
        }
    }
    for (ll p=2; p<=n; p++)
       if (LPF[p] == 0) {
            primes_index_map[p] = primes.size();
            primes.pb(p);
            LPF[p] = p;
        }
}

void build_tree(node* &root,ll l,ll r) {
    if (l==r) {
        root->data = (prime_factors[1].find(primes[l]) == prime_factors[1].end() ? 0 : prime_factors[1][primes[l]]);
        return;
    }
    ll mid = l + (r-l) / 2;
    root->left = new node(NULL, NULL, 0);
    root->right = new node(NULL, NULL, 0);
    build_tree(root->left, l, mid);
    build_tree(root->right, mid+1, r);
    root->data = root->left->data + root->right->data;
}

void update_tree(node* &prev, node* &cur, ll l, ll r, ll idx, ll value) {
    if (idx > r or idx < l or l > r)
        return;
    if (l == r) {
        cur->data = value + prev->data;
        return;
    }
    ll mid = l + (r-l) / 2;
    if (idx <= mid) {
        cur->right = ((cur->right == NULL || cur->right->data == prev->right->data) ? prev->right : cur->right);
        cur->left = ((cur->left == NULL || cur->left->data == prev->left->data) ? new node(NULL, NULL, 0) : cur->left);
        update_tree(prev->left,cur->left, l, mid, idx, value);
    }
    else {
        cur->left = ((cur->left == NULL || cur->left->data == prev->left->data) ? prev->left : cur->left);
        cur->right = ((cur->right == NULL || cur->right->data == prev->right->data) ? new node(NULL, NULL, 0) : cur->right);
        update_tree(prev->right, cur->right, mid+1, r, idx, value);
    }
    cur->data = cur->left->data + cur->right->data;
}

ll query(node* root, ll low, ll high, ll l, ll r) {
    if (l > high or r < low or low > high)
       return 0;
    if (l <= low and high <= r)
       return root->data;
    ll mid = (low+high) / 2;
    ll p1 = query(root->left,low,mid,l,r);
    ll p2 = query(root->right,mid+1,high,l,r);
    return p1+p2;
}

void factorize(ll n, ll index) {
	ll power,i,j;
	
	// if (n != 1) {
	// 	for(j=0; j<primes.size(); j++) {
	// 		i = primes[j];
	// 		power = 0;
	// 		while (n%i == 0) {
	// 			n = n / i;
	// 			power++;
	// 		}
	// 		if(power != 0) {
	// 			prime_factors[index][i] += power;
	// 		}
	// 	}
	// 	if (n != 1) {
	// 		prime_factors[index][n] += 1;
	// 	}
	// }
    while (n > 1) {
        i = LPF[n];
        power = 0;
        while(n % i == 0) {
            n = n / i;
            power++;
        }
        if (power != 0) {
            prime_factors[index][i] += power;
        }
    }
}

int main() {
	ll i,j,t,n,q,l,r,x,y,x_index,y_index;
	sieve();
	n = read_ll();
	
	FOR(i,1,n+1) {
		j = read_ll();
		factorize(j,i);
        tree_roots[i] = new node(NULL, NULL, 0);
        if (i == 1) {
            build_tree(tree_roots[1], 0, primes.size()-1);
        }
        else {
            for(it = prime_factors[i].begin(); it != prime_factors[i].end(); it++) {
                update_tree(tree_roots[i-1], tree_roots[i], 0, primes.size()-1, primes_index_map[it->first], it->second);
            }
        }
	}
	q = read_ll();
	
	FOR(i,0,q) {
		l = read_ll();
		r = read_ll();
		x = read_ll();
		y = read_ll();

        if (y < 2 || x > primes.back()) {
            printf("0\n");
            continue;
        }

        x_index = lower_bound(all(primes), x) - primes.begin();
        y_index = lower_bound(all(primes), y) - primes.begin();
        y_index = min(y_index, (ll)(primes.size()-1));
        if(primes[y_index] > y) {
            y_index -= 1;
        }
        if(x_index > y_index) {
            printf("0\n");
            continue;
        }

		ll val1 = (l == 1 ? 0 : query(tree_roots[l-1], 0, primes.size()-1, x_index, y_index));
		ll val2 = query(tree_roots[r], 0, primes.size()-1, x_index, y_index);

		printf("%lld\n", val2-val1);
	}
	return 0;
}