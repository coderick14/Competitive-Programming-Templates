// Stable counting sort of n elements each in the range [1,k]
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	ll i, n, k;
	cin >> n >> k;
	vector<ll> a(n+1), b(n+1), c(k+1,0);
	for(i = 1; i <= n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	for(i = 1; i <= k; i++) {
		c[i] = c[i] + c[i-1];
	}
	for (i = n; i >= 1; i--) {
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
	for (i = 1; i <= n; i++) {
		cout << b[i] << " ";
	}
}