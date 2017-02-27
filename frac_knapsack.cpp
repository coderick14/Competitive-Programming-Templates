#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

bool comp(pll a, pll b) {
    float ratio1 = float(a.first)/float(a.second);
    float ratio2 = float(b.first)/float(b.second);
    return ratio1 > ratio2;
}

int main() {
    ll i,value,weight,n,w;
    cin>>n>>w;
    vector<pll > ratio;
    for(i=0;i<n;i++) {
        cin>>value>>weight;
        ratio.push_back(make_pair(value,weight));
    }
    sort(ratio.begin(), ratio.end(), comp);
    float res = 0.0;
    i = 0;
    while(i<n && w-ratio[i].second >= 0) {
        res += ratio[i].first;
        w -= ratio[i].second;
        i++;
    }
    if(i<n) {
        res += (float(ratio[i].first)/float(ratio[i].second))*w;
    }
    cout<<res<<endl;
    return 0;
}
