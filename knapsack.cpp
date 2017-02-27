#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll i,j,n,w;
    cin>>n>>w;
    ll dp[n+1][w+1];
    ll val[n], wt[n];
    for(i=0;i<n;i++)
        cin>>val[i]>>wt[i];
    for(i=0;i<=n;i++) {
        for(j=0;j<=w;j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(j < wt[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            }
        }
    }
    //for(i=0;i<=n;i++) {
    //    for(j=0;j<=w;j++)
    //        cout<<dp[i][j]<<" ";
    //    cout<<endl;
    //}
    cout<<dp[n][w]<<endl;
    return 0;
}
