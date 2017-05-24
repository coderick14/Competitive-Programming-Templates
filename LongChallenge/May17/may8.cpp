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

vector<pp > prime_factors;
vi prime_powers;

// Legendre's theorem to return highest power of a prime p in n!
// http://www.cut-the-knot.org/blue/LegendresTheorem.shtml
ll legendre(ll n, ll p) {
	ll ans = 0;
	while (n > 0) {
		n = n / p;
		ans = ans + n;
	}
	return ans;
}

// Extended Euclid's Algorithm
ll xGCD(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Multiplicative modular inverse using Extended Euclid's Algorithm
ll find_inverse(ll n, ll mod) {
	ll x,y;
	xGCD(n,mod,x,y);

	if (x < 0) {
		x = x + mod;
	}

	return x;
}

// factorize into prime factors
void factorize(ll n) {
	ll power,i,val;
	prime_factors.clear();
	prime_powers.clear();
	for(i=2; i*i <= n; i++) {
		power = 0, val = 1;
		while (n%i == 0) {
			n = n / i;
			power++;
			val = val * i;
		}
		if(power != 0) {
			prime_factors.pb(mp(i,power));
			prime_powers.pb(val);
		}
	}
	if (n != 1) {
		prime_factors.pb(mp(n,1));
		prime_powers.pb(n);
	}
}

// Generalized form of Lucas' Theorem
// https://math.stackexchange.com/questions/60206/lucas-theorem-but-without-prime-numbers
ll nCr_mod_prime_power(ll n, ll m, ll prime, ll exponent, ll prime_power) {
	ll highest_divisible_power = legendre(n,prime) - legendre(m,prime) - legendre(n-m,prime);
	
	if (highest_divisible_power >= exponent) {
		return 0;
	}

	exponent = exponent - highest_divisible_power;
	ll i, new_prime_power = 1;
	FOR(i,0,exponent) {
		new_prime_power = new_prime_power * prime;
	}
	
	vi factorials(new_prime_power);
	factorials[0] = 1;
	FOR(i,1,new_prime_power) {
		if (i % prime == 0) {
			factorials[i] = factorials[i-1];
		}
		else {
			factorials[i] = (factorials[i-1] * i) % new_prime_power;
		}
	}

	ll numerator = 1, denominator = 1, r = n-m;
	bool is_negative = false;
	int digits = 0;

	while (n > 0) {
		if (digits >= exponent && factorials[new_prime_power - 1] != 1) {
			is_negative = is_negative ^ ((n&1) ^ (m&1) ^ (r&1));
		}

		numerator = (numerator * factorials[n % new_prime_power]) % new_prime_power;
		denominator = (denominator * factorials[m % new_prime_power]) % new_prime_power;
		denominator = (denominator * factorials[r % new_prime_power]) % new_prime_power;

		n = n / prime;
		m = m / prime;
		r = r / prime;

		digits++;
	}

	ll answer = (numerator * find_inverse(denominator, new_prime_power)) % new_prime_power;

	if (is_negative && (prime != 2 || exponent < 3)) {
		answer = new_prime_power - answer;
	}

	FOR(i,0,highest_divisible_power) {
		answer = (answer * prime) % prime_power;
	}
	
	return answer;
}

// Chinese Remainder Theorem
// https://brilliant.org/wiki/chinese-remainder-theorem/
ll chinese_remainder_theorem(vi &remainders, ll mod) {
	if (remainders.size() == 1) {
		return remainders[0];
	}

	ll i, len = remainders.size();
	ll answer = 0;
	FOR(i,0,len) {
		answer = (answer + ((remainders[i] * (mod / prime_powers[i]))%mod  * find_inverse(mod / prime_powers[i], prime_powers[i]))%mod)%mod;
	}
	return answer;
}


// nCr modulo m (where m may be prime or composite)
ll nCr_modulo(ll n, ll m, ll mod) {
	if (mod == 1) {
		return 0;
	}
	ll i;
	factorize(mod);
	ll len = prime_powers.size();
	vi remainders;
	
	FOR(i,0,len) {
		remainders.pb(nCr_mod_prime_power(n,m,prime_factors[i].first, prime_factors[i].second, prime_powers[i]));
	}
	return chinese_remainder_theorem(remainders,mod);
}

int main() {
	ll i,j,t,n,k,m,r,mod;
	t = read_ll();
	while(t--) {
		n = read_ll();
		k = read_ll();
		mod = read_ll();

		m = n / k;
		if (n % k != 0) {
			m++;
		}

		if (n%k == 0) {
			printf("%lld 1\n", m);
			continue;
		}

		n = m - n - 1 + m*k;
		r = min(m-1,m*k - n);
		
		printf("%lld %lld\n", m, nCr_modulo(n,r,mod));
	}
	return 0;
}
