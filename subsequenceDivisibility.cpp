//given a number having N digits, find number of subsequences of the number divisible by D
//Time Complexity : O(nd)
//Space Complexity : O(1)
#include <bits/stdc++.h>
#define ll long long int
#define d 8
using namespace std;

int main() {
    ll n,i,r;
    ll cnst = 1e9 + 7;
    cin>>n;
    int dp[2][d] = {0};
    char s[n+5];
    cin>>s;
    dp[0][0] = 1;
    for(i=0;i<n;i++) {
        for(r=0;r<d;r++) {
            dp[1][(10*r + int(s[i]-'0'))%d] = (dp[1][(10*r + int(s[i]-'0'))%d] + dp[0][r])%cnst;
            dp[1][r] = (dp[1][r] + dp[0][r])%cnst;
        }
        for(r=0;r<d;r++) {
            dp[0][r] = dp[1][r];
            dp[1][r] = 0;
        }
    }
    cout<<dp[0][0] - 1;
    return 0;
}
