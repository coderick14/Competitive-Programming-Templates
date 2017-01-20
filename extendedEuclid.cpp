#include <bits/stdc++.h>
#define ll long long
using namespace std;

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

int main() {
    ll a,b,c,x,y;
    cin>>a>>b>>c;
    ll gcd = xGCD(a,b,x,y);
    if(c%gcd == 0) {
        ll factor = c/gcd;
        cout<<"x = "<<x*factor<<"\ny = "<<y*factor<<endl;
    }
    else {
        cout<<"Solution does not exist\n";
    }
    return 0;
}
