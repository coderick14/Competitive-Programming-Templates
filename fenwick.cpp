#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
 * POINT UPDATE, RANGE QUERY
 */

// Add delta to A[index]
void point_update(vector<ll> &bit, ll index, ll delta) {
    for(;index < bit.size(); index += (index & -index)) {
        bit[index] += delta;
    }
}

// Query sum of A[1..index]
ll prefix_sum(vector<ll> &bit, ll index) {
    ll sum = 0;
    for(;index > 0; index -= (index & -index)) {
        sum += bit[index];
    }
    return sum;
}

// Query sum of A[a..b]
ll range_query(vector<ll> &bit, ll a, ll b) {
    return prefix_sum(bit,b) - prefix_sum(bit,a-1);
}

/*
 * RANGE UPDATE, POINT QUERY
 */

// Add delta to A[a..b]
void range_update(vector<ll> &bit, ll a, ll b, ll delta) {
    point_update(bit,a,delta);
    point_update(bit,b+1,-delta);
}

// Returns A[index]
ll point_query(vector<ll> &bit, ll index) {
    ll sum = 0;
    for(;index > 0; index -= (index & -index)) {
        sum += bit[index];
    }
    return sum;
}

/*
 * RANGE UPDATE, RANGE QUERY
 */

// Add delta to A[a..b]
void range_update(vector<ll> &bit1, vector<ll> &bit2, ll a, ll b, ll delta) {
    range_update(bit1,a,b,delta);
    point_update(bit2,a,delta * (a-1));
    point_update(bit2,b+1,-delta * b);
}

// Query sum of A[1..index]
ll prefix_sum(vector<ll> &bit1, vector<ll> &bit2, ll index) {
    return prefix_sum(bit1,index) * index - prefix_sum(bit2,index);
}

// Query sum of A[a..b]
ll range_query(vector<ll> &bit1, vector<ll> &bit2, ll a, ll b) {
    return prefix_sum(bit1, bit2, b) - prefix_sum(bit1, bit2, a-1);
}


// Slightly optimized to read a single value
// Returns A[index]
ll read_single_value(vector<ll> &bit, ll index) {
    ll sum = bit[index];
    if (index > 0) {
        ll z = index - (index & -index);
        index--;
        while (index != z) {
            sum -= bit[index];
            index -= (index & -index);
        }
    }
    return sum;
}

int main() {
    ll i,n,q,v,l,r;
    cin >> n;
    vector<ll> bit(n+1,0);
    for (i = 1; i <= n; i++) {
        cin >> v;
        point_update(bit,i,v);
    }
    cin >> q;
    for (i = 0; i < q; i++) {
        cin >> l >> r;
        cout << "Sum of range [" << l << "," << r << "] = " << range_query(bit,l,r) << endl;
        cout << "Value at " << l << " = " << read_single_value(bit,l) << endl;
        cout << "Value at " << r << " = " << read_single_value(bit,r) << endl;
    }
    return 0;
}
